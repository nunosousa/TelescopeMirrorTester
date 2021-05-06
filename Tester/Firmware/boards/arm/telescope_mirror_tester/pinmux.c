/*
 * Copyright (c) 2020 Google LLC.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <drivers/pinmux.h>
#include <soc.h>

static int board_pinmux_init(const struct device *dev)
{
	__unused const struct device *muxa = DEVICE_DT_GET(DT_NODELABEL(pinmux_a));
	__unused const struct device *muxb = DEVICE_DT_GET(DT_NODELABEL(pinmux_b));

	__ASSERT_NO_MSG(device_is_ready(muxa));
	__ASSERT_NO_MSG(device_is_ready(muxb));

	ARG_UNUSED(dev);


#if ATMEL_SAM0_DT_SERCOM_CHECK(0, atmel_sam0_uart) && defined(CONFIG_UART_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(1, atmel_sam0_uart) && defined(CONFIG_UART_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(2, atmel_sam0_uart) && defined(CONFIG_UART_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(3, atmel_sam0_uart) && defined(CONFIG_UART_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(4, atmel_sam0_uart) && defined(CONFIG_UART_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(5, atmel_sam0_uart) && defined(CONFIG_UART_SAM0)
#warning Pin mapping may not be configured
#endif

#if ATMEL_SAM0_DT_SERCOM_CHECK(0, atmel_sam0_spi) && defined(CONFIG_SPI_SAM0)
	pinmux_pin_set(muxa, 4, PINMUX_FUNC_D); /* SERCOM0 PAD[0] on PA04 (MOSI) */
	pinmux_pin_set(muxa, 5, PINMUX_FUNC_D); /* SERCOM0 PAD[1] on PA05 (SCLK) */
	pinmux_pin_set(muxa, 6, PINMUX_FUNC_D); /* SERCOM0 PAD[2] on PA06 (MISO) */
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(1, atmel_sam0_spi) && defined(CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(2, atmel_sam0_spi) && defined(CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(4, atmel_sam0_spi) && defined(CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(5, atmel_sam0_spi) && defined(CONFIG_SPI_SAM0)
#warning Pin mapping may not be configured
#endif

#if ATMEL_SAM0_DT_SERCOM_CHECK(0, atmel_sam0_i2c) && defined(CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(1, atmel_sam0_i2c) && defined(CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(2, atmel_sam0_i2c) && defined(CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(4, atmel_sam0_i2c) && defined(CONFIG_I2C_SAM0)
#warning Pin mapping may not be configured
#endif
#if ATMEL_SAM0_DT_SERCOM_CHECK(5, atmel_sam0_i2c) && defined(CONFIG_I2C_SAM0)
	pinmux_pin_set(muxb, 30, PINMUX_FUNC_D); /* SERCOM5 PAD[1] on PB30 (SCL) */
	pinmux_pin_set(muxb, 31, PINMUX_FUNC_D); /* SERCOM5 PAD[0] on PB31 (SDA) */
#endif

#if ATMEL_SAM0_DT_TCC_CHECK(0, atmel_sam0_tcc_pwm) && defined(CONFIG_PWM_SAM0_TCC)
	pinmux_pin_set(muxa, 8, PINMUX_FUNC_F); /* TCC0/WO[0] on PA08 (A11) */
	pinmux_pin_set(muxa, 9, PINMUX_FUNC_F); /* TCC0/WO[1] on PA09 (A12) */
	pinmux_pin_set(muxa, 10, PINMUX_FUNC_F); /* TCC0/WO[2] on PA10 (B12) */
	pinmux_pin_set(muxa, 11, PINMUX_FUNC_F); /* TCC0/WO[3] on PA11 (B11) */
	pinmux_pin_set(muxb, 10, PINMUX_FUNC_F); /* TCC0/WO[4] on PB10 (A21) */
	pinmux_pin_set(muxb, 11, PINMUX_FUNC_F); /* TCC0/WO[5] on PB11 (A22) */
#endif
#if ATMEL_SAM0_DT_TCC_CHECK(3, atmel_sam0_tcc_pwm) && defined(CONFIG_PWM_SAM0_TCC)
	pinmux_pin_set(muxb, 12, PINMUX_FUNC_F); /* TCC3/WO[0] on PB12 (B22) */
	pinmux_pin_set(muxb, 13, PINMUX_FUNC_F); /* TCC3/WO[1] on PB13 (B21) */
#endif

	if (IS_ENABLED(CONFIG_USB_DC_SAM0)) {
		/* USB DP on PA25, USB DM on PA24 */
		pinmux_pin_set(muxa, 25, PINMUX_FUNC_H);
		pinmux_pin_set(muxa, 24, PINMUX_FUNC_H);
	}

	return 0;
}

SYS_INIT(board_pinmux_init, PRE_KERNEL_1, CONFIG_PINMUX_INIT_PRIORITY);

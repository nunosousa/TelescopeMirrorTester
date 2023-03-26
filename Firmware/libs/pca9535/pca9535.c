#include "pca9535.h"
#include "../../hal/twi_master.h"

#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/io.h>

bool pca9535_event = false;

/*
 * tbd
 */
ISR(PCINT0_vect)
{
    /* Check for low level active pin state */
    /* PB5 PCINT5 (Pin Change Interrupt 5) */
    if ((PINB & (1 << PINB5)) == 0)
        pca9535_event = true;

    return;
}

/*
 * tbd
 */
void pca9535_init(void)
{
    /* Setup up I2C interface */
    twi_init(TWI_FREQ_100K, false);

    /* Disable general interrupts during setup */
    cli();

    /* Set interrupt */
    /* PB5 PCINT5 (Pin Change Interrupt 5) */
    PORTB &= ~(1 << PORTB5); /* Pull-up resistor off on PB5 */
    DDRB &= ~(1 << DDB5);    /* Configure PB5 as input */
    PCICR |= 1 << PCIE0;     /* Enable PCI0 */
    PCMSK0 |= 1 << PCINT5;   /* Configure PB5 as interrupt source */

    /* Enable general interrupts after setup */
    sei();
}

/*
 * tbd
 */
pca_status_t pca9535_set_port_dir(uint8_t address,
                                  pca_port_t port, uint8_t direction)
{
    uint8_t p_data[2];
    twi_status_t twi_status;

    p_data[0] = CONFIGURATION_PORT_0 + port;
    p_data[1] = direction;

    if (p_data[0] != CONFIGURATION_PORT_0 && p_data[0] != CONFIGURATION_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, p_data, 2, false);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    return PCA9535_OK;
}

/*
 * tbd
 */
pca_status_t pca9535_get_port_dir(uint8_t address,
                                  pca_port_t port, uint8_t *direction)
{
    uint8_t p_data;
    twi_status_t twi_status;

    p_data = CONFIGURATION_PORT_0 + port;

    if (p_data != CONFIGURATION_PORT_0 && p_data != CONFIGURATION_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, &p_data, 1, true);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    twi_status = twi_master_receive(address, &p_data, 1);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    *direction = p_data;

    return PCA9535_OK;
}

/*
 * tbd
 */
pca_status_t pca9535_set_port_output(uint8_t address,
                                     pca_port_t port, uint8_t output)
{
    uint8_t p_data[2];
    twi_status_t twi_status;

    p_data[0] = OUTPUT_PORT_0 + port;
    p_data[1] = output;

    if (p_data[0] != OUTPUT_PORT_0 && p_data[0] != OUTPUT_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, p_data, 2, false);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    return PCA9535_OK;
}

/*
 * tbd
 */
pca_status_t pca9535_get_port_output(uint8_t address,
                                     pca_port_t port, uint8_t *output)
{
    uint8_t p_data;
    twi_status_t twi_status;

    p_data = OUTPUT_PORT_0 + port;

    if (p_data != OUTPUT_PORT_0 && p_data != OUTPUT_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, &p_data, 1, true);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    twi_status = twi_master_receive(address, &p_data, 1);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    *output = p_data;

    return PCA9535_OK;
}

/*
 * tbd
 */
pca_status_t pca9535_set_port_polarity(uint8_t address,
                                       pca_port_t port, uint8_t polarity)
{
    uint8_t p_data[2];
    twi_status_t twi_status;

    p_data[0] = POLARITY_INVERSION_PORT_0 + port;
    p_data[1] = polarity;

    if (p_data[0] != POLARITY_INVERSION_PORT_0 && p_data[0] != POLARITY_INVERSION_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, p_data, 2, false);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    return PCA9535_OK;
}

/*
 * tbd
 */
pca_status_t pca9535_get_port_polarity(uint8_t address,
                                       pca_port_t port, uint8_t *polarity)
{
    uint8_t p_data;
    twi_status_t twi_status;

    p_data = POLARITY_INVERSION_PORT_0 + port;

    if (p_data != POLARITY_INVERSION_PORT_0 && p_data != POLARITY_INVERSION_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, &p_data, 1, true);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    twi_status = twi_master_receive(address, &p_data, 1);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    *polarity = p_data;

    return PCA9535_OK;
}

/*
 * tbd
 */
pca_status_t pca9535_get_port_input(uint8_t address,
                                    pca_port_t port, uint8_t *input)
{
    uint8_t p_data;
    twi_status_t twi_status;

    p_data = INPUT_PORT_0 + port;

    if (p_data != INPUT_PORT_0 && p_data != INPUT_PORT_1)
        return PCA9535_E_INVALID_ARGS;

    twi_status = twi_master_transmit(address, &p_data, 1, true);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    twi_status = twi_master_receive(address, &p_data, 1);

    if (twi_status != TWI_OK)
        return PCA9535_E_COMS;

    *input = p_data;

    return PCA9535_OK;
}

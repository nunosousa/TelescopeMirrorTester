/*
 * twi_master.c
 *
 * Created: 09-Jun-19 11:20:17 AM
 *  Author: TEP SOVICHEA
 */

#include "twi_master.h"

#include <stdbool.h>

static ret_code_t tw_start(void);
static void tw_stop(void);
static ret_code_t tw_write_sla(uint8_t sla);
static ret_code_t tw_write(uint8_t data);
static uint8_t tw_read(bool read_ack);

/*
 * tbd
 */
void tw_init(twi_freq_mode_t twi_freq_mode, bool pullup_en)
{
    DDRC |= (1 << TW_SDA_PIN) | (1 << TW_SCL_PIN);

    if (pullup_en)
        PORTC |= (1 << TW_SDA_PIN) | (1 << TW_SCL_PIN);
    else
        PORTC &= ~((1 << TW_SDA_PIN) | (1 << TW_SCL_PIN));

    DDRC &= ~((1 << TW_SDA_PIN) | (1 << TW_SCL_PIN));

    switch (twi_freq_mode)
    {
    case TW_FREQ_100K:
        /* Set bit rate register 72 and prescaler to 1 resulting in
        SCL_freq = 16MHz/(16 + 2*72*1) = 100KHz	*/
        // set TWSR prescale
        TWBR = 72;
        break;

    case TW_FREQ_250K:
        /* Set bit rate register 24 and prescaler to 1 resulting in
        SCL_freq = 16MHz/(16 + 2*24*1) = 250KHz	*/
        TWBR = 24;
        break;

    case TW_FREQ_400K:
        /* Set bit rate register 12 and prescaler to 1 resulting in
        SCL_freq = 16MHz/(16 + 2*12*1) = 400KHz	*/
        TWBR = 12;
        break;

    default:
        break;
    }
}

/*
 * tbd
 */
static ret_code_t tw_start(void)
{
    /* Send START condition */
#if DEBUG_LOG
    printf(BG "Send START condition..." RESET);
#endif
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);

    /* Wait for TWINT flag to set */
    loop_until_bit_is_set(TWCR, TWINT);

    /* Check error */
    if (TW_STATUS != TW_START && TW_STATUS != TW_REP_START)
    {
#if DEBUG_LOG
        printf("\n");
#endif
        return TW_STATUS;
    }

#if DEBUG_LOG
    printf("SUCCESS\n");
#endif
    return SUCCESS;
}

/*
 * tbd
 */
static void tw_stop(void)
{
    /* Send STOP condition */
#if DEBUG_LOG
    puts(BG "Send STOP condition." RESET);
#endif
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/*
 * tbd
 */
static ret_code_t tw_write_sla(uint8_t sla)
{
    /* Transmit slave address with read/write flag */
#if DEBUG_LOG
    printf(BG "Write SLA + R/W: 0x%02X..." RESET, sla);
#endif
    TWDR = sla;
    TWCR = (1 << TWINT) | (1 << TWEN);

    /* Wait for TWINT flag to set */
    loop_until_bit_is_set(TWCR, TWINT);
    if (TW_STATUS != TW_MT_SLA_ACK && TW_STATUS != TW_MR_SLA_ACK)
    {
#if DEBUG_LOG
        printf("\n");
#endif
        return TW_STATUS;
    }

#if DEBUG_LOG
    printf("SUCCESS\n");
#endif
    return SUCCESS;
}

/*
 * tbd
 */
static ret_code_t tw_write(uint8_t data)
{
    /* Transmit 1 byte*/
#if DEBUG_LOG
    printf(BG "Write data byte: 0x%02X..." RESET, data);
#endif
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);

    /* Wait for TWINT flag to set */
    loop_until_bit_is_set(TWCR, TWINT);
    if (TW_STATUS != TW_MT_DATA_ACK)
    {
#if DEBUG_LOG
        printf("\n");
#endif
        return TW_STATUS;
    }

#if DEBUG_LOG
    printf("SUCCESS\n");
#endif
    return SUCCESS;
}

/*
 * tbd
 */
static uint8_t tw_read(bool read_ack)
{
    if (read_ack)
    {
        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
        loop_until_bit_is_set(TWCR, TWINT);
        if (TW_STATUS != TW_MR_DATA_ACK)
        {
            return TW_STATUS;
        }
    }
    else
    {
        TWCR = (1 << TWINT) | (1 << TWEN);
        loop_until_bit_is_set(TWCR, TWINT);
        if (TW_STATUS != TW_MR_DATA_NACK)
        {
            return TW_STATUS;
        }
    }
    uint8_t data = TWDR;
#if DEBUG_LOG
    printf(BG "Read data byte: 0x%02X\n" RESET, data);
#endif
    return data;
}

/*
 * tbd
 */
ret_code_t tw_master_transmit(uint8_t slave_addr, uint8_t *p_data,
                              uint8_t len, bool repeat_start)
{
    ret_code_t error_code;

    /* Send START condition */
    error_code = tw_start();
    if (error_code != SUCCESS)
    {
        return error_code;
    }

    /* Send slave address with WRITE flag */
    error_code = tw_write_sla(TW_SLA_W(slave_addr));
    if (error_code != SUCCESS)
    {
        return error_code;
    }

    /* Send data byte in single or burst mode */
    for (int i = 0; i < len; ++i)
    {
        error_code = tw_write(p_data[i]);
        if (error_code != SUCCESS)
        {
            return error_code;
        }
    }

    if (!repeat_start)
    {
        /* Send STOP condition */
        tw_stop();
    }

    return SUCCESS;
}

/*
 * tbd
 */
ret_code_t tw_master_receive(uint8_t slave_addr, uint8_t *p_data, uint8_t len)
{
    ret_code_t error_code;

    /* Send START condition */
    error_code = tw_start();
    if (error_code != SUCCESS)
    {
        return error_code;
    }

    /* Write slave address with READ flag */
    error_code = tw_write_sla(TW_SLA_R(slave_addr));
    if (error_code != SUCCESS)
    {
        return error_code;
    }

    /* Read single or multiple data byte and send ack */
    for (int i = 0; i < len - 1; ++i)
    {
        p_data[i] = tw_read(TW_READ_ACK);
    }
    p_data[len - 1] = tw_read(TW_READ_NACK);

    /* Send STOP condition */
    tw_stop();

    return SUCCESS;
}

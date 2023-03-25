#include "twi_master.h"

#include <stdbool.h>

static twi_status_t twi_start(void);
static void twi_stop(void);
static twi_status_t twi_write_sla(uint8_t slave_addr, uint8_t rw);
static twi_status_t twi_write(uint8_t data);
static uint8_t twi_read(bool read_ack);

/*
 * tbd
 */
void twi_init(twi_freq_mode_t twi_freq_mode, bool pullup_en)
{
    TWCR = 0; /* Disable interrupts */

    /* Configure TWI pins */
    DDRC |= (1 << DDC4) | (1 << DDC5);

    if (pullup_en)
        PORTC |= (1 << PORTC4) | (1 << PORTC5);
    else
        PORTC &= ~((1 << PORTC4) | (1 << PORTC5));

    DDRC &= ~((1 << DDC4) | (1 << DDC5));

    /* Configure bit rate */
#if (F_CPU == 16000000)
    TWSR = 0; /* Prescaler Value set to 1 */

    switch (twi_freq_mode)
    {
    case TWI_FREQ_100K:
        /* Set bit rate register 72 and prescaler to 1 resulting in
        SCL_freq = 16MHz/(16 + 2*72*1) = 100KHz	*/
        TWBR = 72;
        break;

    case TWI_FREQ_250K:
        /* Set bit rate register 24 and prescaler to 1 resulting in
        SCL_freq = 16MHz/(16 + 2*24*1) = 250KHz	*/
        TWBR = 24;
        break;

    case TWI_FREQ_400K:
        /* Set bit rate register 12 and prescaler to 1 resulting in
        SCL_freq = 16MHz/(16 + 2*12*1) = 400KHz	*/
        TWBR = 12;
        break;

    default:
        break;
    }
#else
#error "No bit rate generator values were calculated for the selected CPU frequency (F_CPU)!"
#endif
}

/*
 * tbd
 */
static twi_status_t twi_start(void)
{
    /* Send START condition */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);

    /* Wait for TWINT flag to set */
    loop_until_bit_is_set(TWCR, TWINT);

    /* Check error */
    if (TW_STATUS != TW_START && TW_STATUS != TW_REP_START)
        return TWI_STA_FAIL;

    return TWI_OK;
}

/*
 * tbd
 */
static void twi_stop(void)
{
    /* Send STOP condition */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/*
 * tbd
 */
static twi_status_t twi_write_sla(uint8_t slave_addr, uint8_t rw)
{
    /* Transmit slave address with read/write flag */
    TWDR = (slave_addr << 1) | rw;
    TWCR = (1 << TWINT) | (1 << TWEN);

    /* Wait for TWINT flag to set */
    loop_until_bit_is_set(TWCR, TWINT);

    if (TW_STATUS != TW_MT_SLA_ACK && TW_STATUS != TW_MR_SLA_ACK)
        return TWI_ADD_ACK_FAIL;

    return TWI_OK;
}

/*
 * tbd
 */
static twi_status_t twi_write(uint8_t data)
{
    /* Transmit 1 byte*/
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);

    /* Wait for TWINT flag to set */
    loop_until_bit_is_set(TWCR, TWINT);

    if (TW_STATUS != TW_MT_DATA_ACK)
        return TWI_DTW_ACK_FAIL;

    return TWI_OK;
}

/*
 * tbd
 */
static uint8_t twi_read(bool read_ack)
{
    if (read_ack)
    {
        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

        loop_until_bit_is_set(TWCR, TWINT);

        if (TW_STATUS != TW_MR_DATA_ACK)
            return TWI_DTR_ACK_FAIL;
    }
    else
    {
        TWCR = (1 << TWINT) | (1 << TWEN);

        loop_until_bit_is_set(TWCR, TWINT);

        if (TW_STATUS != TW_MR_DATA_NACK)
            return TWI_DTR_NACK_FAIL;
    }

    return TWDR;
}

/*
 * tbd
 */
twi_status_t twi_master_transmit(uint8_t slave_addr, uint8_t *p_data,
                                 uint8_t len, bool repeat_start)
{
    twi_status_t error_code;

    /* Send START condition */
    error_code = twi_start();

    if (error_code != TWI_OK)
        return error_code;

    /* Send slave address with WRITE flag */
    error_code = twi_write_sla(slave_addr, TW_WRITE);

    if (error_code != TWI_OK)
        return error_code;

    /* Send data byte in single or burst mode */
    for (int i = 0; i < len; ++i)
    {
        error_code = twi_write(p_data[i]);

        if (error_code != TWI_OK)
            return error_code;
    }

    if (!repeat_start)
        twi_stop(); /* Send STOP condition */

    return TWI_OK;
}

/*
 * tbd
 */
twi_status_t twi_master_receive(uint8_t slave_addr, uint8_t *p_data, uint8_t len)
{
    twi_status_t error_code;

    /* Send START condition */
    error_code = twi_start();

    if (error_code != TWI_OK)
        return error_code;

    /* Write slave address with READ flag */
    error_code = twi_write_sla(slave_addr, TW_READ);

    if (error_code != TWI_OK)
        return error_code;

    /* Read single or multiple data byte and send ack */
    for (int i = 0; i < len - 1; ++i)
    {
        p_data[i] = twi_read(true);
    }
    p_data[len - 1] = twi_read(false);

    /* Send STOP condition */
    twi_stop();

    return TWI_OK;
}

#ifndef TWI_MASTER_H
#define TWI_MASTER_H

#include <avr/io.h>
#include <util/twi.h>
#include <stdbool.h>

typedef enum
{
    TWI_OK, /* API execution successful. */
    TWI_STA_FAIL,
    TWI_ADD_ACK_FAIL,
    TWI_DTW_ACK_FAIL,
    TWI_DTR_ACK_FAIL,
    TWI_DTR_NACK_FAIL
} twi_status_t;

typedef enum
{
    TWI_FREQ_100K,
    TWI_FREQ_250K,
    TWI_FREQ_400K
} twi_freq_mode_t;

/*
 * tbd
 */
void twi_init(twi_freq_mode_t twi_freq, bool pullup_en);

/*
 * tbd
 */
twi_status_t twi_master_transmit(uint8_t slave_addr, uint8_t *p_data,
                                 uint8_t len, bool repeat_start);

/*
 * tbd
 */
twi_status_t twi_master_receive(uint8_t slave_addr, uint8_t *p_data,
                                uint8_t len);

#endif /* TWI_MASTER_H */

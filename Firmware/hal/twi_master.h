#ifndef TWI_MASTER_H
#define TWI_MASTER_H

#include <avr/io.h>
#include <util/twi.h>
#include <stdbool.h>

typedef enum
{
    TWI_OK = 0 /* API execution successful. */
} twi_status_t;

typedef enum
{
    TW_FREQ_100K = 100,
    TW_FREQ_250K = 250,
    TW_FREQ_400K = 400
} twi_freq_mode_t;

/*
 * tbd
 */
void tw_init(twi_freq_mode_t twi_freq, bool pullup_en);

/*
 * tbd
 */
twi_status_t tw_master_transmit(uint8_t slave_addr, uint8_t *p_data,
                                uint8_t len, bool repeat_start);

/*
 * tbd
 */
twi_status_t tw_master_receive(uint8_t slave_addr, uint8_t *p_data,
                               uint8_t len);

#endif /* TWI_MASTER_H */

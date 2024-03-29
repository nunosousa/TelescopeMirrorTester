#ifndef INDICATOR_LED_H
#define INDICATOR_LED_H

#include <stdint.h>

#define NUMBER_OF_LEDS 4

typedef enum
{
    REMOTE = 0,
    MOTOR = 1,
    MOTOR_OLERLOAD = 2,
    MOTOR_LIMIT_SWITCH = 3
} indicator_led_t;

typedef enum
{
    LED_ON,
    LED_OFF
} led_state_t;

/*
 * tbd.
 */
void indicator_led_init(void);

/*
 * tbd.
 */
void indicator_led_set_state(indicator_led_t indicator_led, led_state_t state);

#endif /* INDICATOR_LED_H */

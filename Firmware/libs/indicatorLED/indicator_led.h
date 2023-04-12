#ifndef INDICATOR_LED_H
#define INDICATOR_LED_H

#include <stdint.h>

#define NUMBER_OF_LEDS 4

typedef enum
{
    REMOTE,
    MOTOR,
    MOTOR_OLERLOAD,
    MOTOR_LIMIT_SWITCH
} indicator_led_t;

typedef enum
{
    LED_ON,
    LED_OFF,
    LED_PULSE_WARNING,
    LED_PULSE_ONCE
} led_state_t;

typedef struct
{
    indicator_led_t name; /* Motor max allowed duty cycle in % */
    led_state_t state;    /* Motor min allowed duty cycle in % */
    uint8_t pulse_count;  /* Motor current duty cycle */
} led_parameters_t;

/*
 * tbd.
 */
void indicator_led_init(void);

/*
 * tbd.
 */
void indicator_led_set_state(indicator_led_t indicator_led, led_state_t state);

/*
 * tbd.
 */
void indicator_led_process(void);

#endif /* INDICATOR_LED_H */

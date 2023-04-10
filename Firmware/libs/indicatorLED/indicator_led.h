#ifndef INDICATOR_LED_H
#define INDICATOR_LED_H

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
    LED_PULSE
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

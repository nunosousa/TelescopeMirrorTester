#include "indicator_led.h"
#include "../pca9535/pca9535.h"
#include "../../src/main.h"

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

/* LED bit value */
#define REMOTE_LED 0
#define MOTOR_LED 1
#define MOTOR_OLERLOAD_LED 2
#define MOTOR_LIMIT_SWITCH_LED 3

/*  */
#define WARNING_LED_PULSES 5
#define ONCE_LED_PULSES 1

/*
 * tbd.
 */
static void indicator_led_set(indicator_led_t indicator_led, bool led_on);

/*
 * tbd.
 */
void indicator_led_init(void)
{
    uint8_t led_state;

    led_state = _BV(REMOTE_LED) | _BV(MOTOR_LED) | _BV(MOTOR_OLERLOAD_LED) |
                _BV(MOTOR_LIMIT_SWITCH_LED);

    /* Configure all led pins to high */
    pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, led_state);

    /* Configure all pins as outputs */
    pca9535_set_port_dir(PIN_EXPANDER_ADDRESS, PORT_1, 0x00);
}

/*
 * tbd.
 */
static void indicator_led_set(indicator_led_t indicator_led, bool led_on)
{
    uint8_t led_state, led_to_change;

    /* Get current LED status */
    pca9535_get_port_output(PIN_EXPANDER_ADDRESS, PORT_1, &led_state);

    /* Determine which LED */
    switch (indicator_led)
    {
    case REMOTE:
        led_to_change = _BV(REMOTE_LED);
        break;

    case MOTOR:
        led_to_change = _BV(MOTOR_LED);
        break;

    case MOTOR_OLERLOAD:
        led_to_change = _BV(MOTOR_OLERLOAD_LED);
        break;

    case MOTOR_LIMIT_SWITCH:
        led_to_change = _BV(MOTOR_LIMIT_SWITCH_LED);
        break;

    default:
        return;
    }

    /* Change LED state accordingly */
    if (led_on == true)
        led_state &= ~led_to_change;
    else
        led_state |= led_to_change;

    /* Update LED status */
    pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, led_state);
}

/*
 * tbd.
 */
void indicator_led_set_state(indicator_led_t indicator_led, led_state_t state)
{
    /* check input */
    if (indicator_led > MOTOR_LIMIT_SWITCH)
        return;

    switch (state)
    {
    case LED_ON: /* activate led immediately */
        indicator_led_set(indicator_led, true);
        break;

    case LED_OFF: /* deactivate led immediately */
        indicator_led_set(indicator_led, false);
        break;

    default:
        return;
    }
}

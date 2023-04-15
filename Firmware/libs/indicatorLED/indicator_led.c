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

/* Initial conditions */
static led_parameters_t led_parameters[NUMBER_OF_LEDS] =
    {{LED_OFF, 0},
     {LED_OFF, 0},
     {LED_OFF, 0},
     {LED_OFF, 0}};

/*
 * tbd.
 */
static void indicator_led_set(indicator_led_t indicator_led, bool led_on);

/*
 * tbd.
 */
static bool indicator_led_get(indicator_led_t indicator_led);

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
        led_state |= led_to_change;
    else
        led_state &= ~led_to_change;

    /* Update LED status */
    pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, led_state);
}

/*
 * tbd.
 */
static bool indicator_led_get(indicator_led_t indicator_led)
{
    uint8_t led_state, led_on;

    /* Get current LED status */
    pca9535_get_port_output(PIN_EXPANDER_ADDRESS, PORT_1, &led_state);

    /* Determine which LED */
    switch (indicator_led)
    {
    case REMOTE:
        led_on = led_state & _BV(REMOTE_LED);
        break;

    case MOTOR:
        led_on = led_state & _BV(MOTOR_LED);
        break;

    case MOTOR_OLERLOAD:
        led_on = led_state & _BV(MOTOR_OLERLOAD_LED);
        break;

    case MOTOR_LIMIT_SWITCH:
        led_on = led_state & _BV(MOTOR_LIMIT_SWITCH_LED);
        break;

    default:
        return false;
    }

    /* Change LED state accordingly */
    if (led_on != 0)
        return true;
    else
        return false;
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
        led_parameters[indicator_led].state = LED_ON;
        led_parameters[indicator_led].pulse_count = 0;
        break;

    case LED_OFF: /* deactivate led immediately */
        indicator_led_set(indicator_led, false);
        led_parameters[indicator_led].state = LED_OFF;
        led_parameters[indicator_led].pulse_count = 0;
        break;

    case LED_PULSE_WARNING: /* set led to blink for WARNING_LED_PULSES cycles */
        led_parameters[indicator_led].state = LED_PULSE_WARNING;
        led_parameters[indicator_led].pulse_count = WARNING_LED_PULSES;
        break;

    case LED_PULSE_ONCE: /* set led to blink for ONCE_LED_PULSES cycles */
        led_parameters[indicator_led].state = LED_PULSE_ONCE;
        led_parameters[indicator_led].pulse_count = ONCE_LED_PULSES;
        break;

    default:
        return;
    }
}

/*
 * tbd.
 */
void indicator_led_process(void)
{
    bool led_on;

    /* Check if any LED needs changing its state */
    for (indicator_led_t led = 0; led <= MOTOR_LIMIT_SWITCH; led++)
    {
        if (led_parameters[led].pulse_count == 0)
            continue;

        /* Get current LED status */
        led_on = indicator_led_get(led);

        /* Blink led */
        if (led_on == true)
        {
            indicator_led_set(led, false);
            led_parameters[led].pulse_count -= 1;
        }
        else
        {
            indicator_led_set(led, true);
        }
    }
}

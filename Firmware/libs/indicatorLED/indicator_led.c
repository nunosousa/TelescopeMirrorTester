#include "indicator_led.h"
#include "../pca9535/pca9535.h"
#include "../../src/main.h"

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

/* LED bit value */
#define REMOTE_LED 5
#define MOTOR_LED 4
#define MOTOR_OLERLOAD_LED 0
#define MOTOR_LIMIT_SWITCH_LED 1

/*  */
#define WARNING_LED_PULSES 5
#define ONCE_LED_PULSES 1

/* Initial conditions */
static led_parameters_t led_parameters[NUMBER_OF_LEDS] =
    {{REMOTE, LED_OFF, 0},
     {MOTOR, LED_OFF, 0},
     {MOTOR_OLERLOAD, LED_OFF, 0},
     {MOTOR_LIMIT_SWITCH, LED_OFF, 0}};

/*
 * tbd.
 */
void indicator_led_init(void)
{
    /* Configure all pins to high */
    pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, 0xFF);

    /* Configure all pins as outputs */
    pca9535_set_port_dir(PIN_EXPANDER_ADDRESS, PORT_1, 0x00);
}

/*
 * tbd.
 */
void indicator_led_set_state(indicator_led_t indicator_led, led_state_t state)
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
    switch (state)
    {
    case LED_ON:
        led_state |= led_to_change;
        led_parameters[indicator_led].state = LED_ON;
        break;

    case LED_OFF:
        led_state &= ~led_to_change;
        led_parameters[indicator_led].state = LED_OFF;
        break;

    case LED_PULSE_WARNING:
        led_state |= led_to_change;
        led_parameters[indicator_led].state = LED_PULSE_WARNING;
        led_parameters[indicator_led].pulse_count = WARNING_LED_PULSES;
        break;

    case LED_PULSE_ONCE:
        led_state |= led_to_change;
        led_parameters[indicator_led].state = LED_PULSE_ONCE;
        led_parameters[indicator_led].pulse_count = ONCE_LED_PULSES;
        break;

    default:
        return;
    }

    /* Update LED status */
    pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, led_state);
}

/*
 * tbd.
 */
void indicator_led_process(void)
{
    uint8_t led_state, led_to_change;

    /* Check if any LED needs changing its state */
    for (uint8_t i = 0; i < NUMBER_OF_LEDS; i++)
    {
        if (led_parameters[i].pulse_count == 0)
            continue;

        /* Get current LED status */
        pca9535_get_port_output(PIN_EXPANDER_ADDRESS, PORT_1, &led_state);

        /* Determine which LED */
        switch (led_parameters[i].name)
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
            continue;
        }

        /* do something to togle led if necessary */

        /* Update LED status */
        pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, led_state);
    }
}

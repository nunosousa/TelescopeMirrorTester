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
    uint8_t output_led;

    /* Get current LED status */
    pca9535_get_port_output(PIN_EXPANDER_ADDRESS, PORT_1, &output_led);

    /* Determine which LED and which state parameters */
    switch (indicator_led)
    {
    case REMOTE:
        if (state == LED_ON)
            output_led &= ~_BV(REMOTE_LED);
        else
            output_led |= _BV(REMOTE_LED);

        break;

    case MOTOR:
        if (state == LED_ON)
            output_led &= ~_BV(MOTOR_LED);
        else
            output_led |= _BV(MOTOR_LED);

        break;

    case MOTOR_OLERLOAD:
        if (state == LED_ON)
            output_led &= ~_BV(MOTOR_OLERLOAD_LED);
        else
            output_led |= _BV(MOTOR_OLERLOAD_LED);

        break;

    case MOTOR_LIMIT_SWITCH:
        if (state == LED_ON)
            output_led &= ~_BV(MOTOR_LIMIT_SWITCH_LED);
        else
            output_led |= _BV(MOTOR_LIMIT_SWITCH_LED);

        break;

    default:
        return;
    }

    /* Update LED status */
    pca9535_set_port_output(PIN_EXPANDER_ADDRESS, PORT_1, output_led);
}

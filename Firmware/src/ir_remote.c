#include "ir_remote.h"

#include "../libs/necIr/nec_ir.h"
#include "../libs/indicatorLED/indicator_led.h"
#include "../libs/motorControl/motor_control.h"

#include <stdio.h>

#define MOTOR_SPEED_STEP 20

/*
 * tbd.
 */
void ir_remote_process(void)
{
    motor_parameters_t *motor_state = NULL;
    static motor_t motorID;
    nec_command_t *remote_code;
    uint16_t code;
    uint8_t speed;

    /* Get the last received IR remote code */
    remote_code = nec_ir_get_command();
    if (remote_code == NULL)
        return;

    /* Merge address and command for ease of parsing */
    code = (remote_code->address << 8) | remote_code->command;

    /* Parse code */
    switch (code)
    {
    case 0x0045: /* key 1 - motor A */
        /* Turn ir remote indicator led on */
        indicator_led_set_state(REMOTE, LED_ON);

        motorID = MOTOR_A;
        printf("1 key\n");

        /* Turn ir remote indicator led off */
        indicator_led_set_state(REMOTE, LED_OFF);

        break;

    case 0x0046: /* key 2 - motor B */
        /* Turn ir remote indicator led on */
        indicator_led_set_state(REMOTE, LED_ON);

        motorID = MOTOR_B;
        printf("2 key\n");

        /* Turn ir remote indicator led off */
        indicator_led_set_state(REMOTE, LED_OFF);

        break;

    case 0x0047: /* key 3 - motor B */
        /* Turn ir remote indicator led on */
        indicator_led_set_state(REMOTE, LED_ON);

        motorID = MOTOR_C;
        printf("3 key\n");

        /* Turn ir remote indicator led off */
        indicator_led_set_state(REMOTE, LED_OFF);

        break;

    case 0x0018: /* key up - increase speed */
        /* Turn ir remote indicator led on */
        indicator_led_set_state(REMOTE, LED_ON);

        motor_state = get_motor_state(motorID);
        if (motor_state != NULL)
        {
            if (motor_state->speed > (motor_state->max_speed - MOTOR_SPEED_STEP))
                speed = motor_state->max_speed;
            else
                speed = motor_state->speed + MOTOR_SPEED_STEP;

            motor_drive(motorID, FORWARD_DRIVE, speed);

            printf("up key\n");
        }

        /* Turn ir remote indicator led off */
        indicator_led_set_state(REMOTE, LED_OFF);

        break;

    case 0x0052: /* key down - decrease speed */
        /* Turn ir remote indicator led on */
        indicator_led_set_state(REMOTE, LED_ON);

        motor_state = get_motor_state(motorID);
        if (motor_state != NULL)
        {
            if (motor_state->speed < (motor_state->min_speed + MOTOR_SPEED_STEP))
                speed = motor_state->min_speed;
            else
                speed = motor_state->speed - MOTOR_SPEED_STEP;

            motor_drive(motorID, FORWARD_DRIVE, speed);

            printf("down key\n");
        }

        /* Turn ir remote indicator led off */
        indicator_led_set_state(REMOTE, LED_OFF);

        break;

    case 0x001C: // /* key OK - set speed to zero */
        /* Turn ir remote indicator led on */
        indicator_led_set_state(REMOTE, LED_ON);

        motor_state = get_motor_state(motorID);
        if (motor_state != NULL)
        {
            motor_drive(motorID, FORWARD_DRIVE, 0);

            printf("OK key\n");
        }

        /* Turn ir remote indicator led off */
        indicator_led_set_state(REMOTE, LED_OFF);

        break;

    default:
        break;
    }
}

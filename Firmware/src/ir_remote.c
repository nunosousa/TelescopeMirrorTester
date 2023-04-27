#include "ir_remote.h"

#include "../libs/necIr/nec_ir.h"
#include "../libs/indicatorLED/indicator_led.h"
#include "../libs/motorControl/motor_control.h"

#include <stdio.h>

#define MOTOR_SPEED_STEP 15

/*
 * tbd.
 */
void ir_remote_process(void)
{
    motor_parameters_t *motor_state = NULL;
    static motor_t motorID = NONE;
    motor_drive_t drive;
    nec_command_t *remote_code;
    uint16_t code;
    int16_t speed;

    /* Turn ir remote indicator led on */
    indicator_led_set_state(REMOTE, LED_ON);

    /* Get the last received IR remote code */
    remote_code = nec_ir_get_command();
    if (remote_code == NULL)
        return;

    /* Merge address and command for ease of parsing */
    code = (remote_code->address << 8) | remote_code->command;

    /* Parse code */
    switch (code)
    {
    case 0x0045: /* key 1 - select motor A */
        motorID = MOTOR_A;
        break;

    case 0x0046: /* key 2 - select motor B */
        motorID = MOTOR_B;
        break;

    case 0x0047: /* key 3 - select motor B */
        motorID = MOTOR_C;
        break;

    case 0x0018: /* key up - increase speed on selected motor */
        if (motorID == NONE)
            break;

        motor_state = get_motor_state(motorID);
        if (motor_state == NULL)
            break;

        speed = motor_state->speed;
        drive = motor_state->drive;

        /* Reflect direction on the speed sign for ease of calculations */
        if (drive == REVERSE_DRIVE)
            speed = -speed;

        /* Update speed */
        speed += MOTOR_SPEED_STEP;

        /* Avoid abrupt changes in direction */
        if ((drive == REVERSE_DRIVE) && (speed > 0))
        {
            drive = BRAKE;
            speed = 0;
        }

        /* Update drive direction and speed signal if required */
        if (speed > 0)
            drive = FORWARD_DRIVE;
        else if (speed < 0)
        {
            drive = REVERSE_DRIVE;
            speed = -speed;
        }

        if (speed > motor_state->max_speed)
            speed = motor_state->max_speed;

        motor_drive(motorID, drive, (uint8_t)speed);

        break;

    case 0x0052: /* key down - decrease speed on selected motor */
        if (motorID == NONE)
            break;

        motor_state = get_motor_state(motorID);
        if (motor_state == NULL)
            break;

        speed = motor_state->speed;
        drive = motor_state->drive;

        /* Reflect direction on the speed sign for ease of calculations */
        if (drive == REVERSE_DRIVE)
            speed = -speed;

        /* Update speed */
        speed -= MOTOR_SPEED_STEP;

        /* Avoid abrupt changes in direction */
        if ((drive == FORWARD_DRIVE) && (speed < 0))
        {
            drive = BRAKE;
            speed = 0;
        }

        /* Update drive direction and speed signal if required */
        if (speed > 0)
            drive = FORWARD_DRIVE;
        else if (speed < 0)
        {
            drive = REVERSE_DRIVE;
            speed = -speed;
        }

        if (speed > motor_state->max_speed)
            speed = motor_state->max_speed;

        motor_drive(motorID, drive, (uint8_t)speed);

        break;

    case 0x001C: // /* key OK - set speed to zero on selected motor */
        if (motorID == NONE)
            break;

        motor_state = get_motor_state(motorID);
        if (motor_state == NULL)
            break;

        motor_drive(motorID, BRAKE, 0);

        break;

    default:
        break;
    }

    /* Turn ir remote indicator led off */
    indicator_led_set_state(REMOTE, LED_OFF);
}

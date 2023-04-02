#include "motor_control.h"
#include "../../hal/timer2_pwm.h"

#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>

/* Initial conditions */
static motor_parameters_t motor_parameters[NUMBER_OF_MOTORS] =
    {{100, 0, 100, 0, COAST},
     {100, 0, 100, 0, COAST},
     {100, 0, 100, 0, COAST}};

/*
 * Perform motor interface initializations.
 */
void motor_init(void)
{
    /* Initialize PWM */
    timer2_pwm_init();

    /* Configure motor select pins */
    /* Motor A */
    DDRB |= 1 << DDB4;       /* Configure PB4 as output */
    PORTB &= ~(1 << PORTB4); /* PB4 set to low */

    /* Motor B */
    DDRD |= 1 << DDD7;       /* Configure PD7 as output */
    PORTD &= ~(1 << PORTD7); /* PD7 set to low */

    /* Motor C */
    DDRD |= 1 << DDD2;       /* Configure PD2 as output */
    PORTD &= ~(1 << PORTD2); /* PD2 set to low */
}

/*
 * Drive motor.
 */
void motor_drive(motor_t motorID, motor_drive_t drive, uint8_t speed)
{
    uint16_t duty_cycle_a, duty_cycle_b;

    /* Select motor drive parameters */
    switch (drive)
    {
    case FORWARD_DRIVE:
        duty_cycle_a = speed; // IN2
        duty_cycle_b = 100;   // IN1
        break;
    case REVERSE_DRIVE:
        duty_cycle_a = 100;
        duty_cycle_b = speed;
        break;
    case BRAKE:
        duty_cycle_a = 100;
        duty_cycle_b = 100;
        break;
    case COAST:
        duty_cycle_a = 0;
        duty_cycle_b = 0;
        break;
    default: /* invalid option */
        return;
    }

    timer2_pwm_set_duty_cycle(duty_cycle_a, duty_cycle_b);

    /* Activate motor enable lines and update motor status */
    switch (motorID)
    {
    case MOTOR_A:
        PORTB |= 1 << PORTB4;    /* PB4 (Motor A) set to high */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_A].drive = drive;
        motor_parameters[MOTOR_A].speed = speed;

        /* Update the state for the other motors */
        motor_parameters[MOTOR_B].drive = COAST;
        motor_parameters[MOTOR_B].speed = 0;
        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;

        break;

    case MOTOR_B:
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD |= 1 << PORTD7;    /* PD7 (Motor B) set to high */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_B].drive = drive;
        motor_parameters[MOTOR_B].speed = speed;

        /* Update the state for the other motors */
        motor_parameters[MOTOR_A].drive = COAST;
        motor_parameters[MOTOR_A].speed = 0;
        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;

        break;

    case MOTOR_C:
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD |= 1 << PORTD2;    /* PD2 (Motor C) set to high */

        motor_parameters[MOTOR_C].drive = drive;
        motor_parameters[MOTOR_C].speed = speed;

        /* Update the state for the other motors */
        motor_parameters[MOTOR_A].drive = COAST;
        motor_parameters[MOTOR_A].speed = 0;
        motor_parameters[MOTOR_B].drive = COAST;
        motor_parameters[MOTOR_B].speed = 0;

        break;

    default:                     /* invalid option */
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_A].drive = COAST;
        motor_parameters[MOTOR_A].speed = 0;
        motor_parameters[MOTOR_B].drive = COAST;
        motor_parameters[MOTOR_B].speed = 0;
        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;

        timer2_pwm_set_duty_cycle(0, 0);
    }

    return;
}

/*
 * Get motor state.
 */
motor_parameters_t *get_motor_state(motor_t motorID)
{
    switch (motorID)
    {
    case MOTOR_A:
        return &motor_parameters[MOTOR_A];
    case MOTOR_B:
        return &motor_parameters[MOTOR_B];
    case MOTOR_C:
        return &motor_parameters[MOTOR_C];
    default:
        return NULL;
    }
}

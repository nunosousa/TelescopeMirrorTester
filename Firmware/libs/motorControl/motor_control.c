#include "motor_control.h"
#include "../../hal/adc.h"
#include "../../hal/timer2_pwm.h"
#include "../limitSwitch/limit_switch.h"
#include "../indicatorLED/indicator_led.h"

#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Current low pass filter constants */
/* Simple averaging filter quocients */
#define MUL_CONST_1 1 /* y[-1] * MUL_CONST_1 */
#define MUL_CONST_2 1 /* x[0] * MUL_CONST_2 */
#define DIV_CONST 1   /* (y[-1] * MUL_CONST_1 + x[0] * MUL_CONST_2) << DIV_CONST */

/*
 * Current operating motor
 */
static motor_t active_motor = NONE;

/* Initial conditions */
static motor_parameters_t motor_parameters[NUMBER_OF_MOTORS] =
    {{100, 0, 0, COAST, 0, UINT16_MAX, LIMIT_SW_OFF},
     {100, 0, 0, COAST, 0, UINT16_MAX, LIMIT_SW_OFF},
     {100, 0, 0, COAST, 0, UINT16_MAX, LIMIT_SW_OFF}};

/*
 * Perform motor interface initializations.
 */
static void motor_update_position(void);

/*
 * Perform motor interface initializations.
 */
void motor_init(void)
{
    /* Initialize PWM */
    timer2_pwm_init();

    /* Configure ADC */
    adc_init();

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

    /* Configure limit switch inputs */
    limit_switch_init();

    /* Update motor position */
    motor_update_position();

    /* Identify current motor */
    active_motor = NONE;
}

/*
 * Drive motor.
 */
void motor_drive(motor_t motorID, motor_drive_t drive, uint8_t speed)
{
    uint8_t speed_pwm;
    uint16_t duty_cycle_a, duty_cycle_b;

    /* Adjust from percentage to PWM duty cycle */
    speed_pwm = 100 - speed;

    /* Select motor drive parameters */
    switch (drive)
    {
    case FORWARD_DRIVE:
        duty_cycle_a = 100;       // IN2
        duty_cycle_b = speed_pwm; // IN1
        break;
    case REVERSE_DRIVE:
        duty_cycle_a = speed_pwm;
        duty_cycle_b = 100;
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

    /* Activate motor enable lines, PWM signals and update motor status */
    switch (motorID)
    {
    case MOTOR_A:
        /* Abort if the appropriate limit switch is activated */
        if (((motor_parameters[MOTOR_A].position == FORWARD_LIMIT_SW) &&
             (drive == FORWARD_DRIVE)) ||
            ((motor_parameters[MOTOR_A].position == REVERSE_LIMIT_SW) &&
             (drive == REVERSE_DRIVE)))
            return;

        /* Prepare motor PWM signals */
        timer2_pwm_set_duty_cycle(duty_cycle_a, duty_cycle_b);

        /* Set enable pins accordingly */
        if (drive == COAST)
            PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        else
            PORTB |= 1 << PORTB4; /* PB4 (Motor A) set to high */

        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        /* Conditional updates */
        if (drive == BRAKE || drive == COAST)
        {
            adc_select_analog_input(GND); /* ADC capture source */
            motor_parameters[MOTOR_A].current = 0;
            motor_parameters[MOTOR_A].speed = 0;
            active_motor = NONE;
        }
        else
        {
            adc_select_analog_input(ADC0); /* ADC capture source */
            motor_parameters[MOTOR_A].speed = speed;
            active_motor = MOTOR_A;
        }

        motor_parameters[MOTOR_A].drive = drive;

        /* Update the state for the other motors */
        motor_parameters[MOTOR_B].drive = COAST;
        motor_parameters[MOTOR_B].speed = 0;
        motor_parameters[MOTOR_B].current = 0;
        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;
        motor_parameters[MOTOR_C].current = 0;

        break;

    case MOTOR_B:
        /* Abort if the appropriate limit switch is activated */
        if (((motor_parameters[MOTOR_B].position == FORWARD_LIMIT_SW) &&
             (drive == FORWARD_DRIVE)) ||
            ((motor_parameters[MOTOR_B].position == REVERSE_LIMIT_SW) &&
             (drive == REVERSE_DRIVE)))
            return;

        /* Prepare motor PWM signals */
        timer2_pwm_set_duty_cycle(duty_cycle_a, duty_cycle_b);

        /* Set enable pins accordingly */
        if (drive == COAST)
            PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        else
            PORTD |= 1 << PORTD7; /* PD7 (Motor B) set to high */

        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        /* Conditional updates */
        if (drive == BRAKE || drive == COAST)
        {
            adc_select_analog_input(GND); /* ADC capture source */
            motor_parameters[MOTOR_B].current = 0;
            motor_parameters[MOTOR_B].speed = 0;
            active_motor = NONE;
        }
        else
        {
            adc_select_analog_input(ADC1); /* ADC capture source */
            motor_parameters[MOTOR_B].speed = speed;
            active_motor = MOTOR_B;
        }

        motor_parameters[MOTOR_B].drive = drive;

        /* Update the state for the other motors */
        motor_parameters[MOTOR_A].drive = COAST;
        motor_parameters[MOTOR_A].speed = 0;
        motor_parameters[MOTOR_A].current = 0;
        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;
        motor_parameters[MOTOR_C].current = 0;

        break;

    case MOTOR_C:
        /* Abort if the appropriate limit switch is activated */
        if (((motor_parameters[MOTOR_C].position == FORWARD_LIMIT_SW) &&
             (drive == FORWARD_DRIVE)) ||
            ((motor_parameters[MOTOR_C].position == REVERSE_LIMIT_SW) &&
             (drive == REVERSE_DRIVE)))
            return;

        /* Prepare motor PWM signals */
        timer2_pwm_set_duty_cycle(duty_cycle_a, duty_cycle_b);

        /* Set enable pins accordingly */
        if (drive == COAST)
            PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */
        else
            PORTD |= 1 << PORTD2; /* PD2 (Motor C) set to high */

        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */

        /* Conditional updates */
        if (drive == BRAKE || drive == COAST)
        {
            adc_select_analog_input(GND); /* ADC capture source */
            motor_parameters[MOTOR_C].current = 0;
            motor_parameters[MOTOR_C].speed = 0;
            active_motor = NONE;
        }
        else
        {
            adc_select_analog_input(ADC2); /* ADC capture source */
            motor_parameters[MOTOR_C].speed = speed;
            active_motor = MOTOR_C;
        }

        motor_parameters[MOTOR_C].drive = drive;

        /* Update the state for the other motors */
        motor_parameters[MOTOR_A].drive = COAST;
        motor_parameters[MOTOR_A].speed = 0;
        motor_parameters[MOTOR_A].current = 0;
        motor_parameters[MOTOR_B].drive = COAST;
        motor_parameters[MOTOR_B].speed = 0;
        motor_parameters[MOTOR_B].current = 0;

        break;

    default: /* invalid option */
        timer2_pwm_set_duty_cycle(0, 0);

        /* Change ADC capture source to GND */
        adc_select_analog_input(GND);

        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_A].drive = COAST;
        motor_parameters[MOTOR_A].speed = 0;
        motor_parameters[MOTOR_A].current = 0;
        motor_parameters[MOTOR_B].drive = COAST;
        motor_parameters[MOTOR_B].speed = 0;
        motor_parameters[MOTOR_B].current = 0;
        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;
        motor_parameters[MOTOR_C].current = 0;

        /* Identify current motor */
        active_motor = NONE;
    }

    /* Enable indicator LED */
    if (active_motor != NONE)
        indicator_led_set_state(MOTOR, LED_ON);
    else
        indicator_led_set_state(MOTOR, LED_OFF);

    return;
}

/*
 * tbd
 */
void motor_lim_sw_process(void)
{
    /* Update motor position */
    motor_update_position();

    /* Take appropriate action if motor direction and limit switch coincide */
    switch (active_motor)
    {
    case MOTOR_A:
        /* stop motor if limit is reached */
        if (((motor_parameters[MOTOR_A].position == FORWARD_LIMIT_SW) &&
             (motor_parameters[MOTOR_A].drive == FORWARD_DRIVE)) ||
            ((motor_parameters[MOTOR_A].position = REVERSE_LIMIT_SW) &&
             (motor_parameters[MOTOR_A].drive == REVERSE_DRIVE)))
        {
            motor_drive(MOTOR_A, BRAKE, 0);
        }
        break;

    case MOTOR_B:
        /* stop motor if limit is reached */
        if (((motor_parameters[MOTOR_B].position == FORWARD_LIMIT_SW) &&
             (motor_parameters[MOTOR_B].drive == FORWARD_DRIVE)) ||
            ((motor_parameters[MOTOR_B].position == REVERSE_LIMIT_SW) &&
             (motor_parameters[MOTOR_B].drive == REVERSE_DRIVE)))
        {
            motor_drive(MOTOR_B, BRAKE, 0);
        }
        break;

    case MOTOR_C:
        /* stop motor if limit is reached */
        if (((motor_parameters[MOTOR_C].position == FORWARD_LIMIT_SW) &&
             (motor_parameters[MOTOR_C].drive == FORWARD_DRIVE)) ||
            ((motor_parameters[MOTOR_C].position == REVERSE_LIMIT_SW) &&
             (motor_parameters[MOTOR_C].drive == REVERSE_DRIVE)))
        {
            motor_drive(MOTOR_C, BRAKE, 0);
        }
        break;

    default:
        break;
    }

    return;
}

/*
 * tbd
 */
void motor_current_process(void)
{
    uint16_t adc_reading, prev_adc_reading;

    /* Get an ADC reading of the current channel */
    adc_reading = adc_get_capture();

    /* Update the active motor status */
    switch (active_motor)
    {
    case MOTOR_A:
        /* Low pass filter current readings */
        prev_adc_reading = motor_parameters[MOTOR_A].current;
        motor_parameters[MOTOR_A].current =
            (prev_adc_reading * MUL_CONST_1 + adc_reading * MUL_CONST_2) << DIV_CONST;

        /* Check for current overload */
        if (motor_parameters[MOTOR_A].current > motor_parameters[MOTOR_A].max_current)
        {
            motor_drive(MOTOR_A, BRAKE, 0);
            indicator_led_set_state(MOTOR_OLERLOAD, LED_PULSE_ONCE);
        }
        break;

    case MOTOR_B:
        /* Low pass filter current readings */
        prev_adc_reading = motor_parameters[MOTOR_B].current;
        motor_parameters[MOTOR_B].current =
            (prev_adc_reading * MUL_CONST_1 + adc_reading * MUL_CONST_2) << DIV_CONST;

        /* Check for current overload */
        if (motor_parameters[MOTOR_B].current > motor_parameters[MOTOR_B].max_current)
        {
            motor_drive(MOTOR_B, BRAKE, 0);
            indicator_led_set_state(MOTOR_OLERLOAD, LED_PULSE_ONCE);
        }
        break;

    case MOTOR_C:
        /* Low pass filter current readings */
        prev_adc_reading = motor_parameters[MOTOR_C].current;
        motor_parameters[MOTOR_C].current =
            (prev_adc_reading * MUL_CONST_1 + adc_reading * MUL_CONST_2) << DIV_CONST;

        /* Check for current overload */
        if (motor_parameters[MOTOR_C].current > motor_parameters[MOTOR_C].max_current)
        {
            motor_drive(MOTOR_C, BRAKE, 0);
            indicator_led_set_state(MOTOR_OLERLOAD, LED_PULSE_ONCE);
        }
        break;

    default: /* No active motor */
        return;
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
    case CURRENT_MOTOR:
        if (active_motor == MOTOR_A || active_motor == MOTOR_B || active_motor == MOTOR_C)
            return &motor_parameters[active_motor];
        else
            return NULL;
    default:
        return NULL;
    }
}

/*
 * Perform motor interface initializations.
 */
static void motor_update_position(void)
{
    uint8_t lim_sw_inputs;

    /* Get current limit switches state */
    limit_switch_get_state(&lim_sw_inputs);

    /* Update limit switch status for motor A */
    if ((lim_sw_inputs & _BV(FORWARD_LIMIT_SW_A)) != 0)
        motor_parameters[MOTOR_A].position = FORWARD_LIMIT_SW;
    else if ((lim_sw_inputs & _BV(REVERSE_LIMIT_SW_A)) != 0)
        motor_parameters[MOTOR_A].position = REVERSE_LIMIT_SW;
    else
        motor_parameters[MOTOR_A].position = LIMIT_SW_OFF;

    /* Update limit switch status for motor B */
    if ((lim_sw_inputs & _BV(FORWARD_LIMIT_SW_B)) != 0)
        motor_parameters[MOTOR_B].position = FORWARD_LIMIT_SW;
    else if ((lim_sw_inputs & _BV(REVERSE_LIMIT_SW_B)) != 0)
        motor_parameters[MOTOR_B].position = REVERSE_LIMIT_SW;
    else
        motor_parameters[MOTOR_B].position = LIMIT_SW_OFF;

    /* Update limit switch status for motor C */
    if ((lim_sw_inputs & _BV(FORWARD_LIMIT_SW_A)) != 0)
        motor_parameters[MOTOR_C].position = FORWARD_LIMIT_SW;
    else if ((lim_sw_inputs & _BV(REVERSE_LIMIT_SW_A)) != 0)
        motor_parameters[MOTOR_C].position = REVERSE_LIMIT_SW;
    else
        motor_parameters[MOTOR_C].position = LIMIT_SW_OFF;

    /* Update LED status */
    if (motor_parameters[MOTOR_A].position != LIMIT_SW_OFF ||
        motor_parameters[MOTOR_B].position != LIMIT_SW_OFF ||
        motor_parameters[MOTOR_C].position != LIMIT_SW_OFF)
    {
        indicator_led_set_state(MOTOR_LIMIT_SWITCH, LED_ON);
    }
    else
        indicator_led_set_state(MOTOR_LIMIT_SWITCH, LED_OFF);

    return;
}

#include "motor_control.h"
#include "../cli/cli.h"
#include "../pca9535/pca9535.h"
#include "../../hal/timer2_pwm.h"

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
    uint8_t max_speed; /* Motor max allowed duty cycle in % */
    uint8_t min_speed; /* Motor min allowed duty cycle in % */
    uint8_t max_rate;  /* Motor allowed duty cycle rate of change % */
} motor_parameters_t;

static void motor_drive(motor_t motorID, motor_drive_t drive, uint8_t speed);

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

static void motor_drive(motor_t motorID, motor_drive_t drive, uint8_t speed)
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

    /* Activate motor enable lines */
    switch (motorID)
    {
    case MOTOR_A:
        PORTB |= 1 << PORTB4;    /* PB4 (Motor A) set to high */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */
        break;
    case MOTOR_B:
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD |= 1 << PORTD7;    /* PD7 (Motor B) set to high */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */
        break;
    case MOTOR_C:
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD |= 1 << PORTD2;    /* PD2 (Motor C) set to high */
        break;
    default:                     /* invalid option */
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */
    }
}

// setMaxSpeed {A, B, C}motorID (int)maxSpeed
cli_status_t setMaxSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"setMaxSpeed\" command sets the maximum speed that motorID can reach.\r\n"
              "It expects the following arguments:\r\n"
              "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
              "    maxSpeed - Has range [0, 100] and represents the speed maximum absolute value.\r\n"
              "It showld be called as follows:\r\n"
              "    setMaxSpeed motorID maxSpeed\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// getMaxSpeed {A, B, C}motorID
cli_status_t getMaxSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"getMaxSpeed\" command gets the maximum speed that motorID can reach.\r\n"
              "It expects the following arguments:\r\n"
              "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
              "It showld be called as follows:\r\n"
              "    getMaxSpeed motorID maxSpeed\r\n"
              "and will print the following if successful.",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// setMinSpeed {A, B, C}motorID (int)minSpeed
cli_status_t setMinSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// getMinSpeed {A, B, C}motorID
cli_status_t getMinSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// setRate {A, B, C}motorID (int)acc
cli_status_t setRate_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// getRate {A, B, C}motorID
cli_status_t getRate_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// setSpeed {A, B, C}motorID (int)speed
cli_status_t setSpeed_func(int argc, char **argv)
{
    motor_t motorID;
    uint8_t speed;
    motor_drive_t drive;

    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    /* Identify motorID */
    if (strcmp(argv[1], "A"))
        motorID = MOTOR_A;
    else if (strcmp(argv[1], "B"))
        motorID = MOTOR_B;
    else if (strcmp(argv[1], "C"))
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS;

    /* Identify selected speed */
    speed = atoi(argv[2]);

    if (speed == 0)
        drive = BRAKE;

    motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// getSpeed {A, B, C}motorID
cli_status_t getSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    return CLI_OK;
}

// getLimitSw {A, B, C}motorID
cli_status_t getLimitSw_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// limitSw {A, B, C}motorID (bool)swState (bool)direction
cli_status_t limitSw_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strcmp(argv[1], "help") == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commads actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

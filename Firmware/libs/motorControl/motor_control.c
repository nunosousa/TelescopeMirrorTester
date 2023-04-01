#include "motor_control.h"
#include "../cli/cli.h"
#include "../pca9535/pca9535.h"
#include "../../hal/timer2_pwm.h"

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER_OF_MOTORS 3

/* Define help strings */
const char help_command[] = "help";
const char setMaxSpeed_help[] =
    "\"setMaxSpeed\" command sets the maximum speed that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "    maxSpeed - Has range [0, 100] and represents the speed maximum absolute value.\r\n"
    "It showld be called as follows:\r\n"
    "    setMaxSpeed motorID maxSpeed\r\n";
const char getMaxSpeed_help[] =
    "\"getMaxSpeed\" command gets the maximum speed that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getMaxSpeed motorID maxSpeed\r\n"
    "and will print the following if successful:\r\n"
    "    maxSpeed\r\n";
const char setMinSpeed_help[] =
    "\"setMinSpeed\" command prints a list of the available commands "
    "and a brief summary.\r\nTakes no arguments.\r\n";
const char getMinSpeed_help[] =
    "\"getMinSpeed\" command prints a list of the available commands "
    "and a brief summary.\r\nTakes no arguments.\r\n";
const char setRate_help[] =
    "\"setRate\" command prints a list of the available commands "
    "and a brief summary.\r\nTakes no arguments.\r\n";
const char getRate_help[] =
    "\"getRate\" command prints a list of the available commands "
    "and a brief summary.\r\nTakes no arguments.\r\n";
const char setSpeed_help[] =
    "\"setSpeed\" command sets motorID current speed.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "    speed - Must be an integer value in the range [-100%, 100%] representing\r\n"
    "        the motor speed.\r\n"
    "It showld be called as follows:\r\n"
    "    setSpeed motorID speed\r\n";
const char getSpeed_help[] =
    "\"getSpeed\" command gets motorID current speed.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getSpeed motorID\r\n"
    "and will print the following if successful:\r\n"
    "    speed, drive state\r\n";

typedef struct
{
    uint8_t max_speed;   /* Motor max allowed duty cycle in % */
    uint8_t min_speed;   /* Motor min allowed duty cycle in % */
    uint8_t max_rate;    /* Motor allowed duty cycle rate of change %/s */
    uint8_t speed;       /* Motor current duty cycle */
    motor_drive_t drive; /* Motor current drive status */

} motor_parameters_t;

static motor_parameters_t motor_parameters[NUMBER_OF_MOTORS] =
    {{100, 0, 100, 0, COAST},
     {100, 0, 100, 0, COAST},
     {100, 0, 100, 0, COAST}};

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

    /* Activate motor enable lines and update motor status */
    switch (motorID)
    {
    case MOTOR_A:
        PORTB |= 1 << PORTB4;    /* PB4 (Motor A) set to high */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_A].drive = drive;
        motor_parameters[MOTOR_A].speed = speed;

        break;

    case MOTOR_B:
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD |= 1 << PORTD7;    /* PD7 (Motor B) set to high */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_B].drive = drive;
        motor_parameters[MOTOR_B].speed = speed;

        break;

    case MOTOR_C:
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD |= 1 << PORTD2;    /* PD2 (Motor C) set to high */

        motor_parameters[MOTOR_C].drive = drive;
        motor_parameters[MOTOR_C].speed = speed;

        break;

    default:                     /* invalid option */
        PORTB &= ~(1 << PORTB4); /* PB4 (Motor A) set to low */
        PORTD &= ~(1 << PORTD7); /* PD7 (Motor B) set to low */
        PORTD &= ~(1 << PORTD2); /* PD2 (Motor C) set to low */

        motor_parameters[MOTOR_C].drive = COAST;
        motor_parameters[MOTOR_C].speed = 0;

        timer2_pwm_set_duty_cycle(0, 0);
    }

    return;
}

/*
 * Command: setMaxSpeed {A, B, C}motorID (int)maxSpeed
 */
cli_status_t setMaxSpeed_func(int argc, char **argv)
{
    motor_t motorID;
    int speed;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(setMaxSpeed_help, stdout);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Identify selected speed */
    speed = atoi(argv[2]);

    if (speed < 0 || speed > 100)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_parameters[motorID].max_speed = speed;

    return CLI_OK;
}

/*
 * Command: getMaxSpeed {A, B, C}motorID
 */
cli_status_t getMaxSpeed_func(int argc, char **argv)
{
    char speed_string[10];
    motor_t motorID;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(getMaxSpeed_help, stdout);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    /* Identify motorID and print its speed value */
    memset(speed_string, 0x00, 10);

    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    itoa(motor_parameters[motorID].max_speed, speed_string, 10);
    fputs(speed_string, stdout);

    return CLI_OK;
}

// setMinSpeed {A, B, C}motorID (int)minSpeed
cli_status_t setMinSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(setMinSpeed_help, stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// getMinSpeed {A, B, C}motorID
cli_status_t getMinSpeed_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(getMinSpeed_help, stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// setRate {A, B, C}motorID (int)acc
cli_status_t setRate_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(setRate_help, stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// getRate {A, B, C}motorID
cli_status_t getRate_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(getRate_help, stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

/*
 * Command: setSpeed {A, B, C}motorID (int)speed
 */
cli_status_t setSpeed_func(int argc, char **argv)
{
    motor_t motorID;
    int speed;
    motor_drive_t drive;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(setSpeed_help, stdout);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS; /* Invalid number of arguments */

    /* Perform commands actions */
    /* Identify motorID */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Identify selected speed */
    speed = atoi(argv[2]);

    if (speed == 0)
        drive = BRAKE;
    else if (speed > 0 && speed <= 100)
        drive = FORWARD_DRIVE;
    else if (speed >= -100 && speed < 0)
    {
        speed = -speed;
        drive = REVERSE_DRIVE;
    }
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Drive motor */
    motor_drive(motorID, drive, speed);

    return CLI_OK;
}

/*
 * Command: getSpeed {A, B, C}motorID
 */
cli_status_t getSpeed_func(int argc, char **argv)
{
    char speed_string[10];
    motor_t motorID;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs(getSpeed_help, stdout);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    /* Identify motorID and print its speed value */
    memset(speed_string, 0x00, 10);

    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE))
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    itoa(motor_parameters[motorID].speed, speed_string, 10);
    fputs(speed_string, stdout);

    switch (motor_parameters[motorID].drive)
    {
    case FORWARD_DRIVE:
        fputs("%, forward drive\r\n", stdout);
        break;
    case REVERSE_DRIVE:
        fputs("%, reverse drive\r\n", stdout);
        break;
    case BRAKE:
        fputs("%, brake\r\n", stdout);
        break;
    case COAST:
        fputs("%, coast\r\n", stdout);
        break;
    default:
        break;
    }

    return CLI_OK;
}

// getLimitSw {A, B, C}motorID
cli_status_t getLimitSw_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

// limitSw {A, B, C}motorID (bool)swState (bool)direction
cli_status_t limitSw_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        fputs("\"help\" command prints a list of the available commands "
              "and a brief summary.\r\nTakes no arguments.\r\n",
              stdout);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    // motor_drive(motorID, drive, speed);

    return CLI_OK;
}

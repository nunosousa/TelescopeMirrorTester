#include "motor_control.h"
#include "../cli/cli.h"
#include "../pca9535/pca9535.h"
#include "../../hal/timer2_pwm.h"

#include <avr/io.h>
#include <stdio.h>
#include <string.h>

void motor_init(void)
{
    /* Initialize PWM */
    timer2_pwm_init();

    /* Configure motor select pins */
    /* PB5 PCINT5 (Pin Change Interrupt 5) */
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

// setMaxSpeed {A, B, C}motorID (int)maxSpeed
static cli_status_t setMaxSpeed_func(int argc, char **argv)
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

    /* Perform commans actions */

    return CLI_OK;
}

// getMaxSpeed {A, B, C}motorID
static cli_status_t getMaxSpeed_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// setMinSpeed {A, B, C}motorID (int)minSpeed
static cli_status_t setMinSpeed_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// getMinSpeed {A, B, C}motorID
static cli_status_t getMinSpeed_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// setAcc {A, B, C}motorID (int)acc
static cli_status_t setAcc_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// getAcc {A, B, C}motorID
static cli_status_t getAcc_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// setDec {A, B, C}motorID (int)dec
static cli_status_t setDec_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// getDec {A, B, C}motorID
static cli_status_t getDec_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// setSpeed {A, B, C}motorID (int)speed
static cli_status_t setSpeed_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// getSpeed {A, B, C}motorID
static cli_status_t getSpeed_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// getLimitSw {A, B, C}motorID
static cli_status_t getLimitSw_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}

// limitSw {A, B, C}motorID (bool)swState (bool)direction
static cli_status_t limitSw_func(int argc, char **argv)
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

    /* Print help information */
    fputs("For help on a command on the following list, type help "
          "command-name:\r\n",
          stdout);

    return CLI_OK;
}
#include "../libs/cli/cli.h"
#include "../libs/versionInfo/firmwareBuildInfo.h"
#include "../libs/motorControl/motor_control.h"

#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define help strings and store them in program memory */
const char help_command[] =
    "help";
const char help_help[] PROGMEM =
    "\"help\" command prints a list of the available commands\r\n"
    "and a brief summary.\r\n"
    "It showld be called as follows:\r\n"
    "    help\r\n";
const char help_response[] PROGMEM =
    "For help on a command on the following list, type help command-name:\r\n"
    "  help            This command.\r\n"
    "  version         Prints firmware version info.\r\n"
    "  setMaxSpeed     Sets motor max speed.\r\n"
    "  getMaxSpeed     Gets motor max speed.\r\n"
    "  setMinSpeed     Sets motor min speed.\r\n"
    "  getMinSpeed     Gets motor min speed.\r\n"
    "  setSpeed        Command motor speed.\r\n"
    "  getSpeed        Gets motor current speed.\r\n"
    "  getLimitSw      Gets limit switches current state.\r\n"
    "  setMaxCurrent   Sets motor max limiting current.\r\n"
    "  getMaxCurrent   Gets motor max limiting current.\r\n"
    "  getCurrent      Gets motor current.\r\n";

const char version_help[] PROGMEM =
    "\"version\" command prints the system info.\r\n"
    "It showld be called as follows:\r\n"
    "    version\r\n";
const char version_response[] PROGMEM =
    "Position controler [Author: Nuno Sousa, "
    "Firmware version: ";
const char setMaxSpeed_help[] PROGMEM =
    "\"setMaxSpeed\" command sets the maximum speed that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "    maxSpeed - Has range [0%, 100%] and represents the speed maximum absolute value.\r\n"
    "It showld be called as follows:\r\n"
    "    setMaxSpeed motorID maxSpeed\r\n";
const char getMaxSpeed_help[] PROGMEM =
    "\"getMaxSpeed\" command gets the maximum speed that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getMaxSpeed motorID maxSpeed\r\n"
    "and will print the following if successful:\r\n"
    "    maxSpeed\r\n";
const char setMinSpeed_help[] PROGMEM =
    "\"setMinSpeed\" command sets the minimum speed that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "    minSpeed - Has range [0%, 100%] and represents the speed minimum absolute value.\r\n"
    "It showld be called as follows:\r\n"
    "    setMinSpeed motorID minSpeed\r\n";
const char getMinSpeed_help[] PROGMEM =
    "\"getMinSpeed\" command gets the minimum speed that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getMinSpeed motorID minSpeed\r\n"
    "and will print the following if successful:\r\n"
    "    minSpeed\r\n";
const char setSpeed_help[] PROGMEM =
    "\"setSpeed\" command sets motorID current speed.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "    speed - Must be an integer value in the range [-100%, 100%] representing\r\n"
    "        the motor speed.\r\n"
    "It showld be called as follows:\r\n"
    "    setSpeed motorID speed\r\n";
const char getSpeed_help[] PROGMEM =
    "\"getSpeed\" command gets motorID current speed.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getSpeed motorID\r\n"
    "and will print the following if successful:\r\n"
    "    speed, drive state\r\n";
const char getLimitSw_help[] PROGMEM =
    "\"getLimitSw\" command gets motorID current limit switch status.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getLimitSw motorID\r\n"
    "and will print one the following if successful:\r\n"
    "    Forward limit\r\n"
    "    Reverse limit\r\n"
    "    Free\r\n";
const char setMaxCurrent_help[] PROGMEM =
    "\"setMaxCurrent\" command sets the maximum current that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "    maxCurrent - Has range [0mA, 1000mA] and represents the current maximum value.\r\n"
    "It showld be called as follows:\r\n"
    "    setMaxCurrent motorID maxCurrent\r\n";
const char getMaxCurrent_help[] PROGMEM =
    "\"getMaxCurrent\" command gets the maximum current that motorID can reach.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getMaxCurrent motorID\r\n"
    "and will print the following if successful:\r\n"
    "    maxCurrent\r\n";
const char getCurrent_help[] PROGMEM =
    "\"getCurrent\" command gets the current on motorID.\r\n"
    "It expects the following arguments:\r\n"
    "    motorID - Must be one of {A, B, C} and represents which motor to select.\r\n"
    "It showld be called as follows:\r\n"
    "    getCurrent motorID\r\n"
    "and will print the following if successful:\r\n"
    "    Current\r\n";

/*
 * tbd.
 */
static void print_progmem_string(const char *string);

/*
 * tbd.
 */
static cli_status_t help_func(int argc, char **argv);

/*
 * tbd.
 */
static cli_status_t version_func(int argc, char **argv);

/*
 * Command: setMaxSpeed {A, B, C}motorID (int)maxSpeed
 */
static cli_status_t setMaxSpeed_func(int argc, char **argv);

/*
 * Command: getMaxSpeed {A, B, C}motorID
 */
static cli_status_t getMaxSpeed_func(int argc, char **argv);

/*
 * Command: setMinSpeed {A, B, C}motorID (int)maxSpeed
 */
static cli_status_t setMinSpeed_func(int argc, char **argv);

/*
 * Command: getMinSpeed {A, B, C}motorID
 */
static cli_status_t getMinSpeed_func(int argc, char **argv);

/*
 * Command: setSpeed {A, B, C}motorID (int)speed
 */
static cli_status_t setSpeed_func(int argc, char **argv);

/*
 * Command: getSpeed {A, B, C}motorID
 */
static cli_status_t getSpeed_func(int argc, char **argv);

/*
 * Command: getLimitSw {A, B, C}motorID
 */
static cli_status_t getLimitSw_func(int argc, char **argv);

/*
 * Command: setMaxCurrent {A, B, C}motorID (int)maxCurrent
 */
static cli_status_t setMaxCurrent_func(int argc, char **argv);

/*
 * Command: getMaxCurrent {A, B, C}motorID
 */
static cli_status_t getMaxCurrent_func(int argc, char **argv);

/*
 * Command: getCurrent {A, B, C}motorID
 */
static cli_status_t getCurrent_func(int argc, char **argv);

/*
 * Available command line commands
 * The contents of the array should be in ascending sorted order of the cmd field
 * according to the comparison function strcmp
 * Use the search function bsearch
 */
cmd_t cmd_tbl[] = {
    {.cmd = "help",
     .func = help_func},
    {.cmd = "version",
     .func = version_func},
    {.cmd = "setMaxSpeed",
     .func = setMaxSpeed_func},
    {.cmd = "getMaxSpeed",
     .func = getMaxSpeed_func},
    {.cmd = "setMinSpeed",
     .func = setMinSpeed_func},
    {.cmd = "getMinSpeed",
     .func = getMinSpeed_func},
    {.cmd = "setSpeed",
     .func = setSpeed_func},
    {.cmd = "getSpeed",
     .func = getSpeed_func},
    {.cmd = "getLimitSw",
     .func = getLimitSw_func},
    {.cmd = "setMaxCurrent",
     .func = setMaxCurrent_func},
    {.cmd = "getMaxCurrent",
     .func = getMaxCurrent_func},
    {.cmd = "getCurrent",
     .func = getCurrent_func}};

/*
 * tbd
 */
void cli_commands_init(cli_t *cli)
{
    /* Command line interface enable */
    cli->cmd_tbl = cmd_tbl;
    cli->cmd_cnt = sizeof(cmd_tbl) / sizeof(cmd_t);
}

/*
 * tbd.
 */
static void print_progmem_string(const char *string)
{
    char c;

    for (size_t i = 0; i < strlen_P(string); i++)
    {
        c = pgm_read_byte_near(string + i);
        putchar(c);
    }
}

/*
 * tbd
 */
static cli_status_t help_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(help_help);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Print help information */
    print_progmem_string(help_response);

    return CLI_OK;
}

/*
 * tbd
 */
static cli_status_t version_func(int argc, char **argv)
{
    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(version_help);
        return CLI_OK;
    }
    else if (argc != 1)
        return CLI_E_INVALID_ARGS;

    /* Print firmware version info */
    print_progmem_string(version_response);
    fputs(getFirmwareVersion(), stdout);
    fputs("].\r\n", stdout);

    return CLI_OK;
}

/*
 * Command: setMaxSpeed {A, B, C}motorID (int)maxSpeed
 */
static cli_status_t setMaxSpeed_func(int argc, char **argv)
{
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;
    int speed;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(setMaxSpeed_help);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Identify selected speed */
    speed = atoi(argv[2]);

    if (speed < 0 || speed > 100)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state->max_speed = speed;

    return CLI_OK;
}

/*
 * Command: getMaxSpeed {A, B, C}motorID
 */
static cli_status_t getMaxSpeed_func(int argc, char **argv)
{
    char speed_string[10];
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(getMaxSpeed_help);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    /* Identify motorID and print its speed value */
    memset(speed_string, 0x00, 10);

    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    itoa(motor_state->max_speed, speed_string, 10);
    fputs(speed_string, stdout);
    fputs("\r\n", stdout);

    return CLI_OK;
}

/*
 * Command: setMinSpeed {A, B, C}motorID (int)maxSpeed
 */
static cli_status_t setMinSpeed_func(int argc, char **argv)
{
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;
    int speed;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(setMinSpeed_help);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Identify selected speed */
    speed = atoi(argv[2]);

    if (speed < 0 || speed > 100)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state->min_speed = speed;

    return CLI_OK;
}

/*
 * Command: getMinSpeed {A, B, C}motorID
 */
static cli_status_t getMinSpeed_func(int argc, char **argv)
{
    char speed_string[10];
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(getMinSpeed_help);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    /* Identify motorID and print its speed value */
    memset(speed_string, 0x00, 10);

    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    itoa(motor_state->min_speed, speed_string, 10);
    fputs(speed_string, stdout);
    fputs("\r\n", stdout);

    return CLI_OK;
}

/*
 * Command: setSpeed {A, B, C}motorID (int)speed
 */
static cli_status_t setSpeed_func(int argc, char **argv)
{
    motor_t motorID;
    motor_drive_t drive;
    int speed;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(setSpeed_help);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS; /* Invalid number of arguments */

    /* Perform commands actions */
    /* Identify motorID */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
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
static cli_status_t getSpeed_func(int argc, char **argv)
{
    char speed_string[10];
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(getSpeed_help);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    /* Identify motorID and print its speed value */
    memset(speed_string, 0x00, 10);

    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    itoa(motor_state->speed, speed_string, 10);
    fputs(speed_string, stdout);

    switch (motor_state->drive)
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
        fputs("\r\n", stdout);
        break;
    }

    return CLI_OK;
}

/*
 * Command: getLimitSw {A, B, C}motorID
 */
static cli_status_t getLimitSw_func(int argc, char **argv)
{
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(getLimitSw_help);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Get limit switch status */
    switch (motor_state->position)
    {
    case FORWARD_LIMIT_SW:
        fputs("Forward limit\r\n", stdout);
        break;
    case REVERSE_LIMIT_SW:
        fputs("Reverse limit\r\n", stdout);
        break;
    case LIMIT_SW_OFF:
        fputs("Free\r\n", stdout);
        break;

    default:
        break;
    }

    return CLI_OK;
}

/*
 * Command: setMaxCurrent {A, B, C}motorID (int)maxCurrent
 */
static cli_status_t setMaxCurrent_func(int argc, char **argv)
{
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;
    int current;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(setMaxCurrent_help);
        return CLI_OK;
    }
    else if (argc != 3)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Identify selected speed */
    current = atoi(argv[2]);

    if (current < 0 || current > 1000)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state->max_current = current;

    return CLI_OK;
}

/*
 * Command: getMaxCurrent {A, B, C}motorID
 */
static cli_status_t getMaxCurrent_func(int argc, char **argv)
{
    char current_string[10];
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(getMaxCurrent_help);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    memset(current_string, 0x00, 10);

    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    itoa(motor_state->max_current, current_string, 10);
    fputs(current_string, stdout);
    fputs("\r\n", stdout);

    return CLI_OK;
}

/*
 * Command: getCurrent {A, B, C}motorID
 */
static cli_status_t getCurrent_func(int argc, char **argv)
{
    motor_t motorID;
    motor_parameters_t *motor_state = NULL;
    float current_float;

    /* Check for correct argument's list */
    if ((argc == 2) && (strncmp(argv[1], help_command, MAXIMUM_TOKEN_SIZE) == 0))
    {
        print_progmem_string(getCurrent_help);
        return CLI_OK;
    }
    else if (argc != 2)
        return CLI_E_INVALID_ARGS;

    /* Perform commands actions */
    if (strncmp(argv[1], "A", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_A;
    else if (strncmp(argv[1], "B", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_B;
    else if (strncmp(argv[1], "C", MAXIMUM_TOKEN_SIZE) == 0)
        motorID = MOTOR_C;
    else
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    motor_state = get_motor_state(motorID);
    if (motor_state == NULL)
        return CLI_E_INVALID_ARGS; /* Invalid argument */

    /* Convert ADC value to floating point number in units of mA */
    current_float = ((float)motor_state->current / 1024.0) * 1000.0;
    printf("%.3f [mA]\r\n", current_float);

    return CLI_OK;
}

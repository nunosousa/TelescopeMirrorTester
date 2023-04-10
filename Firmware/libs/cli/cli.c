/*! @file cli.c
 * @brief Implementation of command-line interface.
 */
#include "cli.h"
#include "../../hal/uart.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define CMD_BUFSIZE RX_BUFSIZE + 1

static char cmd_buf[CMD_BUFSIZE]; /* CLI command buffer */

const char cli_prompt[] = ">> "; /* CLI prompt displayed to the user */
const char cli_cmd_unrecog[] = "\" is not recognized as a command.\r\n"
                               "Type \"help\" for a list of the available commands.\r\n";
const char cli_arg_unrecog[] = "Given command's argument(s) are not recognized.\r\n"
                               "Type \"command help\" for a list of the available command's arguments.\r\n";

/*!
 * @brief This API initialises the command-line interface.
 */
cli_status_t cli_init(void)
{
    /* UART interface setup */
    uart_init();

    /* Print the CLI prompt. */
    fputs(cli_prompt, stdout);

    return CLI_OK;
}

/*! @brief This API must be periodically called by the user to process and execute
 *         any commands received.
 */
cli_status_t cli_process(cli_t *cli)
{
    uint8_t argc = 0;
    char *argv[30];
    cli_status_t return_value = CLI_E_CMD_NOT_FOUND;

    /* Copy string to command buffer for processing. */
    fgets(cmd_buf, CMD_BUFSIZE, stdin);

    /* Get the first token (cmd name) */
    argv[argc] = strtok(cmd_buf, CMD_TOKEN_DELIMITERS);

    if (argv[0] == '\0')
    {
        /* No command. Print the CLI prompt to the user. */
        fputs(cli_prompt, stdout);
        return CLI_OK;
    }

    /* Walk through the other tokens (parameters) */
    while ((argv[argc] != '\0') && (argc < 30))
    {
        argv[++argc] = strtok(NULL, CMD_TOKEN_DELIMITERS);
    }

    /* Search the command table for a matching command, using argv[0]
     * which is the command name. */
    for (uint8_t i = 0; i < cli->cmd_cnt; i++)
    {
        if (strncmp(argv[0], cli->cmd_tbl[i].cmd, MAXIMUM_TOKEN_SIZE) == 0)
        {
            /* Found a match, execute the associated function. */
            return_value = cli->cmd_tbl[i].func(argc, argv);
        }
    }

    switch (return_value)
    {
    case CLI_E_CMD_NOT_FOUND:
        /* Command not found, print error message. */
        fputc('\"', stdout);
        fputs(argv[0], stdout);
        fputs(cli_cmd_unrecog, stdout);
        /* Print the CLI prompt to the user. */
        fputs(cli_prompt, stdout);
        break;
    case CLI_E_INVALID_ARGS:
        /* Command's argument not recognised, print error message. */
        fputs(cli_arg_unrecog, stdout);
        /* Print the CLI prompt to the user. */
        fputs(cli_prompt, stdout);
        break;
    default:
        /* Print the CLI prompt to the user. */
        fputs(cli_prompt, stdout);
    }

    return return_value;
}

/*
 * MIT License
 *
 * Copyright (c) 2019 Sean Farrelly
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * File        cli.c
 * Created by  Sean Farrelly
 * Version     1.0
 *
 */

/*! @file cli.c
 * @brief Implementation of command-line interface.
 */
#include "cli.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

static uint8_t cmd_buf[MAX_BUF_SIZE]; /* CLI command buffer */

const char cli_prompt[] = ">> "; /* CLI prompt displayed to the user */
const char cli_unrecog[] = "CMD: Command not recognised\r\n";

/*!
 * @brief This API initialises the command-line interface.
 */
cli_status_t cli_init(cli_t *cli)
{
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

    /* Copy string to command buffer for processing. */
    fgets(cmd_buf, MAX_BUF_SIZE, stdin);       

    /* Get the first token (cmd name) */
    argv[argc] = strtok(cmd_buf, " \r\n");

    /* Walk through the other tokens (parameters) */
    while ((argv[argc] != NULL) && (argc < 30))
    {
        argv[++argc] = strtok(NULL, " \r\n");
    }

    /* Search the command table for a matching command, using argv[0]
     * which is the command name. */
    for (size_t i = 0; i < cli->cmd_cnt; i++)
    {
        if (strcmp(argv[0], cli->cmd_tbl[i].cmd) == 0)
        {
            /* Found a match, execute the associated function. */
            cli_status_t return_value = cli->cmd_tbl[i].func(argc, argv);
            fputs(cli_prompt, stdout); /* Print the CLI prompt to the user. */
            return return_value;
        }
    }

    /* Command not found */
    fputs(cli_unrecog, stdout);

    fputs(cli_prompt, stdout); /* Print the CLI prompt to the user. */

    return CLI_E_CMD_NOT_FOUND;
}

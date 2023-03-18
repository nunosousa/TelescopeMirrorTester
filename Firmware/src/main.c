#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>

#include "../hal/uart.h"
#include "../libs/versionInfo/firmwareBuildInfo.h"
#include "../libs/cli/cli.h"

static void init(void);
static cli_status_t help_func(int argc, char **argv);
static cli_status_t version_func(int argc, char **argv);

FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
cli_t cli;

cmd_t cmd_tbl[] = {
	{.cmd = "help",
	 .func = help_func},
	{.cmd = "version",
	 .func = version_func}};

/*
 * Do all the startup-time peripheral initializations.
 */
static void init(void)
{
	stdout = &uart_stream;
	stdin = &uart_stream;
	stderr = &uart_stream;

	uart_init();

	cli.cmd_tbl = cmd_tbl;
	cli.cmd_cnt = sizeof(cmd_tbl) / sizeof(cmd_t);
	cli_init(&cli);
}

int main(void)
{
	init();

	while (1)
	{
		if (uart_rx_event)
		{
			uart_rx_event = false;
			uart_process(stdout);
		}

		if (uart_new_line_event)
		{
			uart_new_line_event = false;
			cli_process(&cli);
		}

		// kick_wd();
	}

	return 0; // will never return
}

static cli_status_t help_func(int argc, char **argv)
{
	/* Check for correct argument's list */
	if ((argc == 2) && (strcmp(argv[1], "help") == 0))
		fputs("\"help\" command prints a list of the available commands "
			  "and a brief summary.\r\nTakes no arguments.",
			  stdout);
	else if (argc != 1)
		return CLI_E_INVALID_ARGS;

	/* Print help information*/
	fputs("For help on a command on the following list, type help "
		  "command-name:\r\n",
		  stdout);
	fputs("cmd1   Gets something...\r\n", stdout);
	fputs("cmd2   Sets something...\r\n", stdout);

	return CLI_OK;
}

static cli_status_t version_func(int argc, char **argv)
{
	/* Check for correct argument's list */
	if ((argc == 2) && (strcmp(argv[1], "help") == 0))
		fputs("\"version\" command prints the system info. Takes no arguments.", stdout);
	else if (argc != 1)
		return CLI_E_INVALID_ARGS;

	/* Print firmware version info */
	fputs("Position controler [Author: Nuno Sousa, Firmware version: ", stdout);
	fputs(getFirmwareVersion(), stdout);
	fputs("].\r\n", stdout);

	return CLI_OK;
}

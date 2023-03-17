#include <stdbool.h>
#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>

#include "../hal/uart.h"
#include "../libs/versionInfo/firmwareBuildInfo.h"
#include "../libs/cli/cli.h"

static void init(void);
static cli_status_t help_func(int argc, char **argv);
static cli_status_t version_func(int argc, char **argv);

FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
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
	uart_init();
	// init perif a

	stdout = &uart_str;
	stdin = &uart_str;
	stderr = &uart_str;

	cli.cmd_tbl = cmd_tbl;
	cli.cmd_cnt = sizeof(cmd_tbl) / sizeof(cmd_t);
	cli_init(&cli);
}

static cli_status_t help_func(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return CLI_OK;
}

static cli_status_t version_func(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return CLI_OK;
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

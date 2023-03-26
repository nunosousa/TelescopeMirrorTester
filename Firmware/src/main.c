#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <avr/wdt.h>

#include "../hal/uart.h"
#include "../libs/versionInfo/firmwareBuildInfo.h"
#include "../libs/cli/cli.h"
#include "../libs/pca9535/pca9535.h"

/* Local function prototypes */
static void sys_init(void);
static cli_status_t help_func(int argc, char **argv);
static cli_status_t version_func(int argc, char **argv);

/* Data structure */
FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
cli_t cli;

/*
 * tbd
 */
cmd_t cmd_tbl[] = {
	{.cmd = "help",
	 .func = help_func},
	{.cmd = "version",
	 .func = version_func}};

/*
 * Do all the startup-time peripheral initializations.
 */
static void sys_init(void)
{
	/* Set WDT witl long period for initial setup */
	wdt_enable(WDTO_1S);

	/* stdio streams */
	stdout = &uart_stream;
	stdin = &uart_stream;
	stderr = &uart_stream;

	/* UART interface setup needed for cmd line interface */
	uart_init();

	/* Command line interface enable */
	cli.cmd_tbl = cmd_tbl;
	cli.cmd_cnt = sizeof(cmd_tbl) / sizeof(cmd_t);
	cli_init();

	/* Pin extended setup */
	pca9535_init();

	/* set WDT with normal period */
	wdt_enable(WDTO_30MS);
}

/*
 * tbd
 */
int main(void)
{
	/* Initialize all required peripherals or libraries */
	sys_init();

	/* Main super loop */
	while (1)
	{
		/* Process a pin extender pin change event */
		if (pca9535_event)
		{
			pca9535_event = false;
			// do something
		}

		/* Process a new received character event */
		if (uart_rx_event)
		{
			uart_rx_event = false;
			uart_process(stdout);
		}

		/* Process a new received full line evtn */
		if (uart_new_line_event)
		{
			uart_new_line_event = false;
			cli_process(&cli);
		}

		/* Keep the watchdog timer on check */
		wdt_reset();
	}

	return 0; /* Will never return */
}

/*
 * tbd
 */
static cli_status_t help_func(int argc, char **argv)
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

	/* Print help information*/
	fputs("For help on a command on the following list, type help "
		  "command-name:\r\n",
		  stdout);
	fputs("cmd1   Gets something...\r\n", stdout);
	fputs("cmd2   Sets something...\r\n", stdout);

	return CLI_OK;
}

/*
 * tbd
 */
static cli_status_t version_func(int argc, char **argv)
{
	/* Check for correct argument's list */
	if ((argc == 2) && (strcmp(argv[1], "help") == 0))
	{
		fputs("\"version\" command prints the system info. "
			  "Takes no arguments.\r\n",
			  stdout);
		return CLI_OK;
	}
	else if (argc != 1)
		return CLI_E_INVALID_ARGS;

	/* Print firmware version info */
	fputs("Position controler [Author: Nuno Sousa, "
		  "Firmware version: ",
		  stdout);
	fputs(getFirmwareVersion(), stdout);
	fputs("].\r\n", stdout);

	return CLI_OK;
}

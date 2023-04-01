#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <avr/wdt.h>

#include "../hal/timer0_clk.h"
#include "../hal/timer1_rc5.h"
#include "../hal/uart.h"
#include "../libs/cli/cli.h"
#include "../libs/motorControl/motor_control.h"
#include "../libs/pca9535/pca9535.h"
#include "../libs/versionInfo/firmwareBuildInfo.h"

/* Local function prototypes */
static void sys_init(void);
static cli_status_t help_func(int argc, char **argv);
static cli_status_t version_func(int argc, char **argv);

/* Data structure */
FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
cli_t cli;

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
	 .func = version_func}};

/*
 * Do all the startup-time peripheral initializations.
 */
static void sys_init(void)
{
	/* Set WDT */
	wdt_enable(WDTO_30MS);

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

	/* Set time keeping clock */
	timer0_clk_init();

	/* Configure the IR receiver */
	timer1_rc5_init();

	/* Motors PWM setup */
	motor_init();

	/* Reset WD before jumping to normal operation */
	wdt_reset();
}

/*
 * tbd
 */
int main(void)
{
	/* Initialize all required peripherals or libraries */
	sys_init();

	/* Main super loop */
	while (true)
	{
		/* Process a periodic 16ms timer event */
		if (timer0_clk_event)
		{
			timer0_clk_event = false;
			// do something
		}

		/* Process the received RC-5 command event */
		if (rc5_ready_event)
		{
			rc5_ready_event = false;
			// do something
		}

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

		/* Process a new received full line event */
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

	/* Print help information */
	fputs("For help on a command on the following list, type help "
		  "command-name:\r\n",
		  stdout);
	fputs("cmd1   Gets something...\r\n", stdout);
	fputs("cmd2   Sets something...\r\n", stdout);
	// call libx help information function

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

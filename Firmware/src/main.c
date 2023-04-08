#include <stdbool.h>
#include <stdio.h>

#include <avr/io.h>
#include <avr/wdt.h>

#include "../hal/adc.h"
#include "../hal/timer0_clk.h"
#include "../hal/timer1_rc5.h"
#include "../hal/uart.h"
#include "../libs/cli/cli.h"
#include "../libs/motorControl/motor_control.h"
#include "../libs/pca9535/pca9535.h"
#include "cli_commands.h"

/* Local function prototypes */
static void sys_init(void);

/* Set up default io streams */
FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

/* Command line structure */
cli_t cli;

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

	/* Enable the cli interface */
	cli_init();

	/* Create cli commands */
	cli_commands_init(&cli);

	/* Pin extended setup */
	pca9535_init();

	/* Set time keeping clock */
	timer0_clk_init();

	/* Configure the IR receiver */
	timer1_rc5_init();

	/* Motors PWM setup */
	motor_init();

	/* Configure ADC */
	adc_init();

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
			// do something motor
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

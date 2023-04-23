#include <stdbool.h>
#include <stdio.h>

#include <avr/io.h>
#include <avr/wdt.h>

#include "../hal/adc.h"
#include "../hal/timer0_clk.h"
#include "../hal/timer1_nec.h"
#include "../hal/uart.h"
#include "../libs/cli/cli.h"
#include "../libs/motorControl/motor_control.h"
#include "../libs/necIr/nec_ir.h"
#include "../libs/pca9535/pca9535.h"
#include "../libs/indicatorLED/indicator_led.h"
#include "cli_commands.h"

/* Number of 16ms clock0 periods to give a period of ~500ms */
#define LED_PROCESS_PERIOD 31

/* Local function prototypes */
static void sys_init(void);

/* Set up default io streams */
FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

/* Command line structure */
cli_t cli;

/* Time counter for LED blink logic */
uint8_t timeLed = 0;

/*
 * Do all the startup-time peripheral initializations.
 */
static void sys_init(void)
{
	/* Set WDT */
	wdt_enable(WDTO_2S);

	/* stdio streams */
	stdout = &uart_stream;
	stdin = &uart_stream;
	stderr = &uart_stream;

	/* Enable the cli interface */
	cli_init();

	/* Create cli commands - depends on cli_init */
	cli_commands_init(&cli);

	/* Pin extended setup */
	pca9535_init();

	/* Configure LEDs - depends on pca9535_init */
	indicator_led_init();

	/* Motors PWM setup - depends on pca9535_init */
	motor_init();

	/* Configure the IR receiver */
	timer1_nec_init();

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

			/* Start ADC capture */
			adc_start_capture();

			/* Process LED */
			++timeLed;
			if (timeLed == LED_PROCESS_PERIOD)
			{
				timeLed = 0;
				indicator_led_process();
			}
		}

		/* Process the ADC reading event */
		if (adc_event)
		{
			adc_event = false;
			motor_current_process();
		}

		/* Process a pin extender pin change event */
		if (pca9535_event)
		{
			pca9535_event = false;
			motor_lim_sw_process();
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

		/* Process the received NEC IR command event */
		if (timer1_nec_event)
		{
			timer1_nec_event = false;
			nec_ir_process();
		}

		/* Keep the watchdog timer on check */
		wdt_reset();
	}

	return 0; /* Will never return */
}

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, UART implementation
 *
 * $Id: uart.c 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */
#include "uart.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <avr/io.h>
#include <avr/interrupt.h>

bool uart_rx_event = false;

bool new_line_event = false;

static uint8_t new_char;

/*
 * New received character interrrupt handler
 */
ISR(USART_RX_vect)
{
	/* Check for errors before reading received char */
	if (UCSR0A & (_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	{
		/* If error, read UDR0 until the RXC0 Flag is cleared */
		while (UCSR0A & _BV(RXC0))
			new_char = UDR0;

		return;
	}

	/* Read new char to clear interrupt flag RXC0 and flag event */
	new_char = UDR0;
	uart_rx_event = true;

	return;
}

/*
 * Initialize the UART to 9600 Bd, tx/rx, 8N1.
 */
void uart_init(void)
{
	uint16_t ubrr;

	uart_rx_event = false;
	new_line_event = false;

	ubrr = (F_CPU / (16UL * BAUD)) - 1;

	/* Disable general interrupts during setup */
	cli();

	/* Set baud rate */
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;

	/* USART normal speed */
	UCSR0A = 0;

	/* Enable receiver, transmitter and interrupt on received character */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

	/* Set frame format: 8data, 2stop bit, odd parity */
	UCSR0C = (3 << UPM00) | (1 << USBS0) | (3 << UCSZ00);

	/* Enable general interrupts during setup */
	sei();
}

/*
 * Send character c down the UART Tx, wait until tx holding register
 * is empty.
 */
uint16_t uart_putchar(uint8_t c, FILE *stream)
{
	if (c == '\n')
		uart_putchar('\r', stream);

	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;

	return 0; /* success */
}

/*
 * Receive a character from the UART Rx.
 *
 * This features a simple line-editor that allows to delete and
 * re-edit the characters entered, until either CR or NL is entered.
 * Printable characters entered will be echoed using uart_putchar().
 *
 * Editing characters:
 *
 * . \b (BS) delete the previous character
 * . \t will be replaced by a single space
 *
 * All other control characters will be ignored.
 *
 * The internal line buffer is RX_BUFSIZE (80) characters long, which
 * includes the terminating \n (but no terminating \0).  If the buffer
 * is full (i. e., at RX_BUFSIZE-1 characters in order to keep space for
 * the trailing \n), any further input attempts will send a \a to
 * uart_putchar() (BEL character), although line editing is still
 * allowed.
 *
 * Input errors while talking to the UART will cause an immediate
 * return of -1 (error indication).  Notably, this will be caused by a
 * framing error (e. g. serial line "break" condition), by an input
 * overrun, and by a parity error (if parity was enabled and automatic
 * parity recognition is supported by hardware).
 *
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied again.
 */
void uart_process_char(FILE *stream)
{
	uint8_t c;
	uint8_t *cp;
	static uint8_t rx_buffer[RX_BUFSIZE];
	static uint8_t *rxp;

	for (cp = rx_buffer;;)
	{

		c = UDR0;

		/* behaviour similar to Unix stty ICRNL */
		if (c == '\r')
			c = '\n';

		if (c == '\n')
		{
			*cp = c;
			uart_putchar(c, stream);
			rxp = rx_buffer;
			break;
		}

		if ((c >= (uint8_t)' ') && (c <= (uint8_t)'~'))
		{
			if (cp < rx_buffer + RX_BUFSIZE - 1)
				*cp++ = c;
			uart_putchar(c, stream);
		}
		continue;

		if (c == '\b')
		{
			if (cp > rx_buffer)
			{
				uart_putchar('\b', stream);
				uart_putchar(' ', stream);
				uart_putchar('\b', stream);
				cp--;
			}
		}
	}

	return;
}

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
uint16_t uart_getchar(FILE *stream)
{
	uint8_t c;

	// get char from internal circular buffer
	// if no more characters, send _FDEV_EOF

	return c;
}

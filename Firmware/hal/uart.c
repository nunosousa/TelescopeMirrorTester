#include "uart.h"
#include "cbuffer.h"

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <util/atomic.h>

bool uart_rx_event = false;

bool uart_new_line_event = false;

static volatile char rx_char;
static cbuffer rx_cbuffer;
static char rx_buffer[RX_BUFSIZE];

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
			rx_char = UDR0;

		return;
	}

	/* Read new char to clear interrupt flag RXC0 and flag event */
	rx_char = UDR0;
	uart_rx_event = true;

	return;
}

/*
 * Initialize the UART to 9600 Bd, tx/rx, 8N1.
 */
void uart_init(void)
{
	uart_rx_event = false;
	uart_new_line_event = false;

	/* Disable general interrupts during setup */
	cli();

	/* Set baud rate */
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	/* USART speed */
#if USE_2X
	UCSR0A = _BV(U2X0);
#else
	UCSR0A = 0;
#endif

	/* Enable receiver, transmitter and interrupt on received character */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

	/* Set frame format: 8data, 1stop bit, odd parity */
	UCSR0C = (3 << UPM00) | (3 << UCSZ00);

	/* Enable general interrupts after setup */
	sei();

	/* Setup circular buffer for the received characters */
	cb_init(&rx_cbuffer, (size_t)RX_BUFSIZE, sizeof(char), rx_buffer);
}

/*
 * Send character c down the UART Tx, wait until tx holding register
 * is empty.
 */
int uart_putchar(char c, FILE *stream)
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
void uart_process(FILE *stream)
{
	char rx_char_copy;

	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		rx_char_copy = rx_char;
	}

	/* Behaviour similar to Unix stty ICRNL */
	if (rx_char_copy == '\r')
		rx_char_copy = '\n';

	if (rx_char_copy == '\n')
	{
		cb_push(&rx_cbuffer, &rx_char_copy);
		uart_putchar(rx_char_copy, stream);
		uart_new_line_event = true;
		return;
	}

	/* Printable character */
	if ((rx_char_copy >= (char)' ') && (rx_char_copy <= (char)'~'))
	{
		cb_push(&rx_cbuffer, &rx_char_copy);
		uart_putchar(rx_char_copy, stream);
		return;
	}

	/* Backspace */
	if (rx_char_copy == '\b')
	{
		if (cb_count(&rx_cbuffer) > 0)
		{
			uart_putchar('\b', stream);
			uart_putchar(' ', stream);
			uart_putchar('\b', stream);
			cb_undo_push(&rx_cbuffer, &rx_char_copy);
		}
		return;
	}

	return;
}

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
int uart_getchar(FILE *stream)
{
	char c;

	(void)stream; /* Keeping the compiler from flagging this variable as unused */

	/* Get char from internal circular buffer.
	If no more characters, send _FDEV_EOF.*/
	if (cb_count(&rx_cbuffer) > 0)
		cb_pop(&rx_cbuffer, &c);
	else
		c = _FDEV_EOF;

	return c;
}

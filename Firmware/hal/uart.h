#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * Received character event
 */
extern bool volatile uart_rx_event;

/*
 * Received full line event
 */
extern bool uart_new_line_event;

/*
 * Perform UART startup initialization.
 */
void uart_init(void);

/*
 * Send one character to the UART.
 */
int uart_putchar(char c, FILE *stream);

/*
 * Send one character to the UART.
 */
void uart_process(FILE *stream);

/*
 * Receive one character from the UART.  The actual reception is
 * line-buffered, and one character is returned from the buffer at
 * each invokation.
 */
int uart_getchar(FILE *stream);

#endif /* UART_H */

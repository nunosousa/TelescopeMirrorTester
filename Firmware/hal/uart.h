/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, UART declarations
 *
 * $Id: uart.h 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */
#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * Received character event
 */
extern bool uart_rx_event;

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
void uart_process_char(FILE *stream);

/*
 * Receive one character from the UART.  The actual reception is
 * line-buffered, and one character is returned from the buffer at
 * each invokation.
 */
int uart_getchar(FILE *stream);

#endif /* UART_H */

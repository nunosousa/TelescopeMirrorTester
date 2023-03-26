#ifndef PCA9535_H
#define PCA9535_H

#include <stdint.h>
#include <stdbool.h>

/*
 * tbd
 */
extern bool pca9535_event;

/*
 * PCA9535 registers definition.
 * The chip contain 16 bidirectional lines divided between two ports. It has
 * 4 groups of two registers, one for each port. Ports controls direction of
 * each pin, you can read current state of input pins, set state of output pins
 * or invert logic of given pins.
 */

typedef enum
{
    PORT_0 = 0,
    PORT_1 = 1
} pca_port_t;

/*
 * tbd
 */
void pca9535_init(void);

/*
 * Set direction of given port. As PCA9535 has two ports, we can
 * give them numbers like 0 and 1. This function excpects 0 for the first
 * port of the chip and 1 for the second one.
 */
void pca9535_setPortDir(uint8_t address, pca_port_t port, uint8_t value);

/*
 * Return current direction register value.
 */
uint8_t pca9535_getPortDir(uint8_t address, pca_port_t port);

/*
 * Set output lines of the port to given value. Bits in given value for
 * lines set as input will be ignored.
 */
void pca9535_setPortOutput(uint8_t address, pca_port_t port, uint8_t value);

/*
 * Return current output register value for given port.
 */
uint8_t pca9535_getPortOutput(uint8_t address, pca_port_t port);

/*
 * Set polarity inversion of given port. All lines set for inverse logic will
 * have reverse polarity, which means 1 write to output will cause the line
 * to go to low state and 1 if 0 is written.
 */
void pca9535_setPortPolarity(uint8_t address, pca_port_t port, uint8_t value);

/*
 * Get polarity inversion register value
 */
uint8_t pca9535_getPortPolarity(uint8_t address, pca_port_t port);

/*
 * Function return current state of lines of port set as input.
 * Lines set as output will be ignored. You should mask those bits
 * in tyour code.
 */
uint8_t pca9535_getPortInput(uint8_t address, pca_port_t port);

#endif /* PCA9535_H */

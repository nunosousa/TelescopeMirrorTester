#ifndef PCA9535_H
#define PCA9535_H

#include <stdint.h>
#include <stdbool.h>

#define INPUT_PORT_0 0x00 /* Port 0 input value */
#define INPUT_PORT_1 0x01 /* Port 1 input value */
#define I0 0
#define I1 1
#define I2 2
#define I3 3
#define I4 4
#define I5 5
#define I6 6

#define OUTPUT_PORT_0 0x02 /* Port 0 output value */
#define OUTPUT_PORT_1 0x03 /* Port 1 output value */
#define O0 0
#define O1 1
#define O2 2
#define O3 3
#define O4 4
#define O5 5
#define O6 6

#define POLARITY_INVERSION_PORT_0 0x04 /* Port 0 inversion logic register */
#define POLARITY_INVERSION_PORT_1 0x05 /* Port 1 inversion logic register */
#define N0 0
#define N1 1
#define N2 2
#define N3 3
#define N4 4
#define N5 5
#define N6 6

#define CONFIGURATION_PORT_0 0x06 /* Direction control register for Port 0 */
#define CONFIGURATION_PORT_1 0x07 /* Direction control register for Port 1 */
#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define C4 4
#define C5 5
#define C6 6

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

typedef enum
{
    PCA9535_OK,             /* API execution successful. */
    PCA9535_E_INVALID_ARGS, /* Invalid function parameters/arguments. */
    PCA9535_E_COMS          /* TWI communication error. */
} pca9535_status_t;

/*
 * tbd
 */
void pca9535_init(void);

/*
 * Set direction of given port. As PCA9535 has two ports, we can
 * give them numbers like 0 and 1. This function excpects 0 for the first
 * port of the chip and 1 for the second one.
 */
pca9535_status_t pca9535_set_port_dir(uint8_t address,
                                      pca_port_t port, uint8_t direction);

/*
 * Return current direction register value.
 */
pca9535_status_t pca9535_get_port_dir(uint8_t address,
                                      pca_port_t port, uint8_t *direction);

/*
 * Set output lines of the port to given value. Bits in given value for
 * lines set as input will be ignored.
 */
pca9535_status_t pca9535_set_port_output(uint8_t address,
                                         pca_port_t port, uint8_t output);

/*
 * Return current output register value for given port.
 */
pca9535_status_t pca9535_get_port_output(uint8_t address,
                                         pca_port_t port, uint8_t *output);

/*
 * Set polarity inversion of given port. All lines set for inverse logic will
 * have reverse polarity, which means 1 write to output will cause the line
 * to go to low state and 1 if 0 is written.
 */
pca9535_status_t pca9535_set_port_polarity(uint8_t address,
                                           pca_port_t port, uint8_t polarity);

/*
 * Get polarity inversion register value
 */
pca9535_status_t pca9535_get_port_polarity(uint8_t address,
                                           pca_port_t port, uint8_t *polarity);

/*
 * Function return current state of lines of port set as input.
 * Lines set as output will be ignored. You should mask those bits
 * in tyour code.
 */
pca9535_status_t pca9535_get_port_input(uint8_t address,
                                        pca_port_t port, uint8_t *input);

#endif /* PCA9535_H */

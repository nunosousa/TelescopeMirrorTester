#include "pca9535.h"
#include "../../hal/twi_master.h"

#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define INPUT_PORT0 0  /**< Port 0 input value */
#define INPUT_PORT1 1  /**< Port 1 input value */
#define OUTPUT_PORT0 2 /**< Port 0 output value */
#define OUTPUT_PORT1 3 /**< Port 1 output value */
#define POLINV0 4      /**< Port 0 inversion logic register */
#define POLINV1 5      /**< Port 1 inversion logic register */
#define CONF_PORT0 6   /**< Direction control register for Port 0 */
#define CONF_PORT1 7   /**< Direction control register for Port 1 */

bool pca9535_event = false;

/*
 * tbd
 */
ISR(PCINT0_vect)
{
    /* Check for low level active pin state */
    if ((PINB & (1 << PINB5)) == 0)
        pca9535_event = true;

    return;
}

/*
 * tbd
 */
void pca9535_init(void)
{
    /* Setup up I2C interface */
    twi_init(TWI_FREQ_100K, false);

    /* Set interrupt */
    // PB5 PCINT5 (Pin Change Interrupt 5)
    PORTB &= ~(1 << PORTB5); /* Pull-up resistor off on PB5 */
    DDRB &= ~(1 << DDB5);    /* Configure PB5 as input */
    PCICR |= 1 << PCIE0;     /* Enable PCI0 */
    PCMSK0 |= 1 << PCINT5;   /* Configure PB5 as interrupt source */

    /* Enable general interrupts after setup */
    sei();
}

/*
 * tbd
 */
void pca9535_setPortDir(uint8_t address, pca_port_t port, uint8_t direction)
{
    uint8_t p_data[2];

    p_data[0] = CONF_PORT0 + port;
    p_data[1] = direction;

    twi_master_transmit(address, p_data, 2, false);

    return;
}

/*
 * tbd
 */
uint8_t pca9535_getPortDir(uint8_t address, pca_port_t port)
{
    uint8_t p_data;

    p_data = CONF_PORT0 + port;

    twi_master_transmit(address, &p_data, 1, true);

    return twi_master_receive(address, &p_data, 1);
}

/*
 * tbd
 */
inline void pca9535_setPortOutput(uint8_t address, pca_port_t port, uint8_t value)
{
    uint8_t p_data[2];

    p_data[0] = OUTPUT_PORT0 + port;
    p_data[1] = value;

    twi_master_transmit(address, p_data, 2, false);

    return;
}

/*
 * tbd
 */
uint8_t pca9535_getPortOutput(uint8_t address, pca_port_t port)
{
    uint8_t p_data;

    p_data = OUTPUT_PORT0 + port;

    twi_master_transmit(address, &p_data, 1, true);

    return twi_master_receive(address, &p_data, 1);
}

/*
 * tbd
 */
void pca9535_setPortPolarity(uint8_t address, pca_port_t port, uint8_t value)
{
    uint8_t p_data[2];

    p_data[0] = POLINV0 + port;
    p_data[1] = value;

    twi_master_transmit(address, p_data, 2, false);

    return;
}

/*
 * tbd
 */
uint8_t pca9535_getPortPolarity(uint8_t address, pca_port_t port)
{
    uint8_t p_data;

    p_data = POLINV0 + port;

    twi_master_transmit(address, &p_data, 1, true);

    return twi_master_receive(address, &p_data, 1);
}

/*
 * tbd
 */
uint8_t pca9535_getPortInput(uint8_t address, pca_port_t port)
{
    uint8_t p_data;

    p_data = INPUT_PORT0 + port;

    twi_master_transmit(address, &p_data, 1, true);

    return twi_master_receive(address, &p_data, 1);
}

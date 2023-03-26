#include "pca9535.h"
#include "../../hal/twi_master.h"

/*
 * tbd
 */
void pca9535_init(void)
{
    /* Setup up I2C interface */
    twi_init(TWI_FREQ_100K, false);
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

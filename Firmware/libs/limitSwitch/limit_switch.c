#include "limit_switch.h"
#include "../pca9535/pca9535.h"
#include "../../src/main.h"

#include <avr/io.h>
#include <stdint.h>

/*
 * tbd.
 */
void limit_switch_init(void)
{
    uint8_t port_config;

    /* Configure inputs 0, 1, 2, 3, 4 and 5 as inputs */
    port_config = _BV(C0) | _BV(C1) | _BV(C2) | _BV(C3) | _BV(C4) | _BV(C5);

    /* Configure limit switches as inputs on the pin expander */
    pca9535_set_port_dir(PIN_EXPANDER_ADDRESS, PORT_0, port_config);
}

/*
 * tbd.
 */
void limit_switch_get_state(uint8_t *lim_sw_inputs)
{
    pca9535_get_port_input(PIN_EXPANDER_ADDRESS, PORT_0, lim_sw_inputs);
}

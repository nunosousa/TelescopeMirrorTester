#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <stdint.h>

/* Limit switch bit value */
#define FORWARD_LIMIT_SW_A 5
#define REVERSE_LIMIT_SW_A 4
#define FORWARD_LIMIT_SW_B 0
#define REVERSE_LIMIT_SW_B 1
#define FORWARD_LIMIT_SW_C 3
#define REVERSE_LIMIT_SW_C 2

/*
 * tbd.
 */
void limit_switch_init(void);

/*
 * tbd.
 */
void limit_switch_get_state(uint8_t *lim_sw_inputs);

#endif /* LIMIT_SWITCH_H */

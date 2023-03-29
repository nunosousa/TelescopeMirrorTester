#ifndef TIMER0_CLK_H
#define TIMER0_CLK_H

#include <stdbool.h>

/*
 * Timer event
 */
extern bool volatile timer0_clk_event;

void timer0_clk_init(void);

#endif /* TIMER0_CLK_H */

#ifndef TIMER1_NEC_H
#define TIMER1_NEC_H

#include <stdbool.h>

extern volatile bool edge[100];
extern volatile uint32_t edge_time[100];
extern volatile uint16_t edge_counter;

/*
 * NEC event
 */
extern volatile bool timer1_nec_event;

void timer1_nec_init(void);

#endif /* TIMER1_NEC_H */

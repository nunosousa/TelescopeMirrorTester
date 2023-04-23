#ifndef TIMER1_NEC_H
#define TIMER1_NEC_H

#include <stdbool.h>
#include <stdint.h>

#define NEC_START_TIME 27000    /* NEC burst start - 13.5 ms */
#define NEC_REPEAT_TIME 22500   /* NEC burst repeat - 11.5 ms */
#define NEC_BURST_TOLERANCE 200 /* 100 us tolerance */
#define NEC_HIGH_TIME 4500      /* NEC logical 1 - 2.25 ms */
#define NEC_LOW_TIME 2240       /* NEC logical 0 - 1.12 ms */
#define NEC_BIT_TOLERANCE 50    /* 25 us tolerance */

extern volatile bool edge[100];
extern volatile uint32_t edge_time[100];
extern volatile uint16_t edge_counter;

/*
 * tbd
 */
extern volatile bool timer1_nec_event;

/*
 * tbd
 */
void timer1_nec_init(void);

/*
 * tbd
 */
int8_t timer1_nec_get_capture(uint32_t *capture);

#endif /* TIMER1_NEC_H */

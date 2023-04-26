#ifndef TIMER1_NEC_H
#define TIMER1_NEC_H

#include <stdbool.h>
#include <stdint.h>

/*
 * timer 1 TCNT1 counter values considering a prescaler value of 8,
 * i.e. a counter lsb of 0.5 us
 */
#define NEC_START_BURST_TIME 27000  /* NEC burst start - 13.5 ms */
#define NEC_HIGH_TOLERANCE 500      /* 250 us tolerance */
#define NEC_ONE_TIME 4480           /* NEC logical 1 - 2.24 ms */
#define NEC_ZERO_TIME 2240          /* NEC logical 0 - 1.12 ms */
#define NEC_LOW_TOLERANCE 50        /* 25 us tolerance */

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

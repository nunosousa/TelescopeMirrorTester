#ifndef TIMER1_RC5_H
#define TIMER1_RC5_H

#include <stdbool.h>

extern volatile bool rc5_ready_event;

void timer1_rc5_init(void);

#endif /* TIMER1_RC5_H */

#ifndef TIMER2_PWM_H
#define TIMER2_PWM_H

#include <stdint.h>

void timer2_pwm_init(void);
void timer2_pwm_set_duty_cycle(uint16_t duty_cycle_a, uint16_t duty_cycle_b);

#endif /* TIMER2_PWM_H */

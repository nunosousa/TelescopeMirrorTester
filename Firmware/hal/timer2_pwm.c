#include "timer2_pwm.h"

#include <avr/io.h>

// PWM 1 pin 11 PB3 OC2A (Timer/Counter2 Output Compare Match A Output)
// PWM 2 pin 3  PD3 OC2B (Timer/Counter2 Output Compare Match B Output)

/*
 * tbd
 */
void timer2_pwm_init(void)
{
    /* Configure Output Compare pins as outputs */
    DDRB |= 1 << DDB3;
    DDRD |= 1 << DDD3;

    /* Configure Output Compare pins to low (0) */
    PORTB &= ~(1 << PORTB3);
    PORTD &= ~(1 << PORTD3);

    
}

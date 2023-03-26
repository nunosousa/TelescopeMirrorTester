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

    // Set Timer1 to fast PWM mode with TOP at 0xFF
    TCCR1A |= (1 << WGM10) | (1 << WGM11);
    TCCR1B |= (1 << WGM12) | (1 << WGM13);

    // Set prescaler to 64, resulting in 976.5625 Hz PWM frequency
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Set PB3 and PD3 to non-inverted PWM mode
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
}

void timer2_pwm_set_duty_cycle(int duty_cycle_a, int duty_cycle_b)
{
    // Convert duty cycles from percentage (0-100) to OCR1A/OCR1B values (0-255)
    int ocr1a_value = (duty_cycle_a * 255) / 100;
    int ocr1b_value = (duty_cycle_b * 255) / 100;

    // Set OCR1A and OCR1B to the calculated values
    OCR1A = ocr1a_value;
    OCR1B = ocr1b_value;
}

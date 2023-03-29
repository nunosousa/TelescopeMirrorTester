#include "timer2_pwm.h"

#include <avr/io.h>
#include <stdint.h>

/*
 * tbd
 */
void timer2_pwm_init(void)
{
    /* Configure Output Compare pins to low (0) */
    PORTB &= ~(1 << PORTB3);
    PORTD &= ~(1 << PORTD3);

    /* Configure Output Compare pins as outputs */
    DDRB |= 1 << DDB3;
    DDRD |= 1 << DDD3;

    /* Set Timer2 to fast PWM mode with TOP at 0xFF */
    TCCR2A |= (1 << WGM20) | (1 << WGM21);

#if (F_CPU == 16000000)
    /* Set prescaler to 8, resulting in 7812,5 Hz PWM frequency */
    TCCR2B |= 1 << CS21;
#else
#error "No timer values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    /* Set PB3 and PD3 to non-inverted PWM mode */
    TCCR2A |= (1 << COM2A1) | (1 << COM2B1);
}

void timer2_pwm_set_duty_cycle(uint16_t duty_cycle_a, uint16_t duty_cycle_b)
{
    uint8_t ocr2a_value;
    uint8_t ocr2b_value;

    /* Convert duty cycles from percentage (0-100) to OCR2A/OCR2B values (0-255) */
    ocr2a_value = (duty_cycle_a * 255) / 100;
    ocr2b_value = (duty_cycle_b * 255) / 100;

    if (duty_cycle_a > 100)
        ocr2a_value = 255;

    if (duty_cycle_b > 100)
        ocr2b_value = 255;

    /* Set OCR2A and OCR2B to the calculated values */
    OCR2A = ocr2a_value;
    OCR2B = ocr2b_value;
}

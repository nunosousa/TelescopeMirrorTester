#include "adc.h"
#include "timer0_clk.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * tbd
 */
volatile bool adc_event = false;

/*
 * tbd
 */
static volatile uint16_t adc_val;

/*
 * tbd
 */
ISR(ADC_vect)
{
    /* Read ADC value */
    adc_val = 0;
    adc_val = ADCL;
    adc_val |= ADCH << 8;

    adc_event = true;
}

/*
 * tbd
 */
void adc_init(void)
{
    /* Disable general interrupts during setup */
    cli();

    /* Set reference voltage to AVcc */
    ADMUX |= _BV(REFS0);

    /* Set input channel to 0V (GND) */
    ADMUX |= _BV(MUX0) | _BV(MUX1) | _BV(MUX2) | _BV(MUX3);

#if (F_CPU == 16000000)
    /* Set ADC prescaler to 128 */
    ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
#else
#error "No prescaler values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    /* Enable auto trigger source to Timer/Counter0 Compare Match A */
    ADCSRB |= _BV(ADTS1) | _BV(ADTS0);

    /* Enable ADC and ADC interrupt, and start capture */
    ADCSRA |= _BV(ADEN) | _BV(ADIE) | _BV(ADSC);

    /* Enable general interrupts after setup */
    sei();

    /* Default option - set source to Temperature sensor */
    adc_select_analog_input(GND);

    /* Set time keeping clock */
    timer0_clk_init();
}

/*
 * tbd
 */
void adc_select_analog_input(adc_input_t input)
{
    switch (input)
    {
    case ADC0: /* Set input channel to ADC0. */
        ADMUX &= ~(_BV(MUX0) | _BV(MUX1) | _BV(MUX2) | _BV(MUX3));
        break;
    case ADC1: /* Set input channel to ADC1. */
        ADMUX &= ~(_BV(MUX1) | _BV(MUX2) | _BV(MUX3));
        ADMUX |= _BV(MUX0);
        break;
    case ADC2: /* Set input channel to ADC2. */
        ADMUX &= ~(_BV(MUX0) | _BV(MUX2) | _BV(MUX3));
        ADMUX |= _BV(MUX1);
        break;
    default: /* Set input channel to 0V (GND) */
        ADMUX |= _BV(MUX0) | _BV(MUX1) | _BV(MUX2) | _BV(MUX3);
        break;
    }

    return;
}

/*
 * tbd
 */
uint16_t adc_get_capture(void)
{
    return adc_val;
}

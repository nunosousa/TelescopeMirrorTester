#include "adc.h"

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
    adc_val = ADC; // Read ADC value
    adc_event = true;
}

/*
 * tbd
 */
void adc_init(void)
{
    /* Disable general interrupts during setup */
    cli();

    // Set up ADC
    ADMUX |= (1 << REFS0); // Set reference voltage to AVcc
    ADMUX |= (1 << MUX0);  // Set input channel to ADC0

#if (F_CPU == 16000000)
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128
#else
#error "No prescaler values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    ADCSRA |= (1 << ADIE); // Enable ADC interrupt

    /* Enable general interrupts after setup */
    sei();

    /* Default option - set source to Temperature sensor */
    adc_select_analog_input(TEMP);
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
    case TEMP: /* Set input channel to ADC8 - Temperature Sensor. */
        ADMUX &= ~(_BV(MUX0) | _BV(MUX1) | _BV(MUX2));
        ADMUX |= _BV(MUX3);
        break;
    case BG_1V1: /* Set input channel to 1.1V (V_BG) */
        ADMUX &= ~_BV(MUX0);
        ADMUX |= _BV(MUX1) | _BV(MUX2) | _BV(MUX3);
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
void adc_start_capture(void)
{
    ADCSRA |= (1 << ADSC); // Start ADC conversion

    return;
}

/*
 * tbd
 */
uint16_t adc_get_capture(void)
{
    return adc_val;
}

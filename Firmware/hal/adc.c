#include "adc.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdbool.h>
#include <stdint.h>

#define ADC_BUFFER_SIZE 10

/*
 * tbd
 */
static volatile uint16_t adc_buffer[ADC_BUFFER_SIZE + 1];

/*
 * tbd
 */
static volatile uint8_t adc_buffer_counter = 0;

/*
 * tbd
 */
volatile bool adc_event = false;

/*
 * tbd
 */
ISR(ADC_vect)
{
    /* Read ADC value and update counter */
    adc_buffer[adc_buffer_counter] = ADC;
    adc_buffer_counter += 1;

    /* Check if the required number of samples was acquired */
    if (adc_buffer_counter >= ADC_BUFFER_SIZE)
    {
        /* Stop capture */
        ADCSRA &= ~(_BV(ADATE));

        /* Flag that a set of captures was complete */
        adc_event = true;
    }
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

#if (F_CPU == 16000000)
    /* Set ADC prescaler to 32 */
    ADCSRA |= _BV(ADPS2) | _BV(ADPS0);
#else
#error "No prescaler values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    /* Enable trigger source to Free Running mode */
    ADCSRB &= ~(_BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0));

    /* Enable ADC and ADC interrupt */
    ADCSRA |= _BV(ADEN) | _BV(ADIE);

    /* Disable the digital input buffers */
    DIDR0 |= _BV(ADC2D) | _BV(ADC1D) | _BV(ADC0D);

    /* Enable general interrupts after setup */
    sei();

    /* Set ADC source to the default */
    adc_select_analog_input(GND);
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
void adc_start_capture(void)
{
    /* Reset sample counter */
    adc_buffer_counter = 0;

    /* Activate auto trigger */
    ADCSRA |= _BV(ADATE);

    /* Start capture */
    ADCSRA |= _BV(ADSC);

    return;
}

/*
 * tbd
 */
uint16_t adc_get_capture(void)
{
    uint16_t adc_val = 0;
    uint16_t sum = 0;

    // calculate true RMS
    for (uint8_t i = 0; i < ADC_BUFFER_SIZE; i++)
        sum += adc_buffer[i];

    adc_val = sum / ADC_BUFFER_SIZE;

    return adc_val;
}

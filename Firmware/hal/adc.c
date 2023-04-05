#include "adc.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define THRESHOLD 512 // set threshold to 2.5V (assuming Vref=5V)

ISR(ADC_vect)
{
    uint16_t adc_val = ADC; // Read ADC value
    if (adc_val > THRESHOLD)
    {
        // Do something when voltage exceeds threshold
    }
}

/*
 * tbd
 */
void adc_init(void)
{
    /* Disable general interrupts during setup */
    cli();

    // Set up ADC
    ADMUX |= (1 << REFS0);                                // Set reference voltage to AVcc
    ADMUX |= (1 << MUX0);                                 // Set input channel to ADC0
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128
    ADCSRA |= (1 << ADIE);                                // Enable ADC interrupt

    /* Enable general interrupts after setup */
    sei();
}

/*
// Main loop
while (1)
{
    ADCSRA |= (1 << ADSC); // Start ADC conversion
    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC))
        ;
}
*/

#include "timer0_clk.h"

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect)
{
    // Your code here
}

void timer0_clk_init(void)
{
    /* Disable general interrupts during setup */
    cli();

    TCCR0A = 0x00; // Clear TCCR0A register
    TCCR0B = 0x00; // Clear TCCR0B register
    TCNT0 = 0x00;  // Clear counter value

    OCR0A = 124; // Set compare match value for 50ms period
                 // Formula: Compare Match Value = [(Desired Interrupt Frequency) * (1 / Prescaler) * (1 / Timer0 Clock Period)] - 1
                 // For 50ms period: Compare Match Value = (50 * 10^-3 * 16 * 10^6) / (1024 * 0.0625) - 1 = 124

    TCCR0A |= (1 << WGM01);              // Set CTC mode
    TCCR0B |= (1 << CS02) | (1 << CS00); // Set prescaler to 1024
    TIMSK0 |= (1 << OCIE0A);             // Enable Timer0 Compare Match A interrupt

    /* Enable general interrupts after setup */
    sei();
}

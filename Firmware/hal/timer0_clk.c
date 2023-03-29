#include "timer0_clk.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

bool volatile timer0_clk_event;

ISR(TIMER0_COMPA_vect)
{
    timer0_clk_event = true;
}

void timer0_clk_init(void)
{
    timer0_clk_event = false;

    /* Disable general interrupts during setup */
    cli();

    /* Set compare match value for 16ms period
    Formula: Compare Match Value =
    [(Timer0 Clock Frequency) * (1 / Prescaler) * (1 / Desired Interrupt Frequency)] - 1 */

#if (F_CPU == 16000000)
    /* For 16ms period (or 62.5Hz frequency) and 16000000Hz Timer0 Clock Frequency:
    Compare Match Value = (16000000) / (1024 * 62.5) - 1 = 249 */
    OCR0A = 249;

    TCCR0A |= (1 << WGM01);              /* Set CTC mode */
    TCCR0B |= (1 << CS02) | (1 << CS00); /* Set prescaler to 1024 */
    TIMSK0 |= (1 << OCIE0A);             /* Enable Timer0 Compare Match A interrupt */
#else
#error "No timer values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    /* Enable general interrupts after setup */
    sei();
}

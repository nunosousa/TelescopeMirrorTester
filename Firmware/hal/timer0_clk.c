#include "timer0_clk.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

volatile bool timer0_clk_event;

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
    TCCR0B |= _BV(CS02) | _BV(CS00); /* Set prescaler to 1024 */
#else
#error "No timer values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    TCCR0A |= _BV(WGM01);  /* Set CTC mode */
    TIMSK0 |= _BV(OCIE0A); /* Enable Timer0 Compare Match A interrupt */

    /* Enable general interrupts after setup */
    sei();
}

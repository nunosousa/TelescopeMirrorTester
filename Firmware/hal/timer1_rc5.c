#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

// RC-5 protocol variables
volatile uint16_t rc5_command = 0;
volatile uint8_t rc5_toggle_bit = 0;
volatile bool rc5_ready_event = false;

// Timer1 overflow counter
volatile uint16_t timer1_ovf_count = 0;

// Interrupt Service Routine for Timer1 Input Capture
ISR(TIMER1_CAPT_vect)
{
    static uint16_t last_capture = 0;
    uint16_t capture = ICR1;
    uint16_t pulse_duration = capture - last_capture;

    // Check if this is a valid RC-5 pulse
    if (pulse_duration > 8000 && pulse_duration < 12000)
    {
        uint8_t bit_value = (pulse_duration > 10000);

        // Process the RC-5 bit
        if (rc5_ready_event)
        {
            // Start of a new RC-5 frame
            rc5_ready_event = false;
            rc5_command = 0;
            rc5_toggle_bit = 0;
        }
        else
        {
            // Add the RC-5 bit to the command
            if (bit_value)
            {
                rc5_command |= (1 << (13 - (timer1_ovf_count % 14)));
            }
        }

        // Toggle the RC-5 toggle bit every other bit
        if (timer1_ovf_count % 2 == 0)
        {
            rc5_toggle_bit = bit_value;
        }

        // Check if this is the last RC-5 bit
        if ((timer1_ovf_count % 14) == 13)
        {
            rc5_ready_event = true;
        }
    }

    last_capture = capture;
}

// Interrupt Service Routine for Timer1 overflow
ISR(TIMER1_OVF_vect)
{
    timer1_ovf_count++;
}

/*
 * tbd
 */
void timer1_rc5_init(void)
{
    /* Disable general interrupts during setup */
    cli();

    /* PB0 ICP1 (Timer/Counter1 Input Capture Input) */
    /* Configure ICP1 pin as input with the pull up disabled */
    DDRB &= ~(1 << DDB0);
    PORTB &= ~(1 << PORTB0);

    /* Initialize Timer1 in Input Capture mode with a prescaler of 8 */
    TCCR1B |= (1 << ICES1) | (1 << CS11);
    TIMSK1 |= (1 << ICIE1) | (1 << TOIE1);
    TCNT1 = 0;

    /* Enable general interrupts after setup */
    sei();
}

/* on main

    while (1)
    {
        // Check if an RC-5 command is ready
        if (rc5_ready_event)
        {
            // Process the RC-5 command
            // ...

            // Reset the RC-5 protocol variables
            rc5_ready_event = false;
            rc5_command = 0;
            rc5_toggle_bit = 0;
        }
*/

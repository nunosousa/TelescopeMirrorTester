#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NEC_CAPTURE_BUFFER 150 /* Note that buffer counters are 8 bit */

/*
 * tbd
 */
volatile bool timer1_nec_event = false;

/*
 * tbd
 */
static volatile uint32_t last_capture;

/*
 * tbd
 */
static volatile uint8_t timer_overflow_counter = 0;

/*
 * tbd
 */
static volatile uint32_t capture_buffer[MAX_NEC_CAPTURE_BUFFER];
static volatile uint8_t capture_counter = 0;
static volatile uint8_t capture_in = 0;
static uint8_t capture_out = 0;

/*
 * Interrupt Service Routine for Timer1 Input Capture
 */
ISR(TIMER1_CAPT_vect)
{
    uint16_t capture;
    uint16_t bit_duration;

    /* Get IR capture timer count and apply extra resolution from oveflow counter */
    capture = ICR1;
    capture += ((uint32_t)timer_overflow_counter) << 16;

    /* Adjust for wrap arround in time difference calculation */
    if (capture >= last_capture)
        bit_duration = capture - last_capture;
    else
        bit_duration = capture - last_capture + 0x01000000;

    /* Update previous counter value */
    last_capture = capture;

    /* Update counter array and buffer counters */
    if (capture_counter < MAX_NEC_CAPTURE_BUFFER)
    {
        capture_buffer[capture_in] = bit_duration;
        capture_counter++;

        capture_in++;

        if (capture_in >= MAX_NEC_CAPTURE_BUFFER)
            capture_in = 0;
    }

    /* Flag IR receiving activity */
    timer1_nec_event = true;
}

/*
 * Interrupt Service Routine for Timer1 overflow
 */
ISR(TIMER1_OVF_vect)
{
    /* Flag new sequence */
    timer_overflow_counter += 1;
}

/*
 * tbd
 */
void timer1_nec_init(void)
{
    /* Disable general interrupts during setup */
    cli();

    /* PB0 ICP1 (Timer/Counter1 Input Capture Input) */
    /* Configure ICP1 pin as input with the pull up disabled */
    DDRB &= ~(_BV(DDB0));
    PORTB &= ~(_BV(PORTB0));

    /* Initialize Timer1 in Input Capture mode */
#if (F_CPU == 16000000)
    TCCR1B |= _BV(CS11); /* prescaler of 8 */
#else
#error "No timer values were calculated for the selected CPU frequency (F_CPU)!"
#endif

    /* Capture falling edge */
    TCCR1B &= ~(_BV(ICES1));

    /* Noise Canceler */
    TCCR1B |= _BV(ICNC1);

    /* Raise interrupt on input capture and on counter overflow */
    TIMSK1 |= _BV(ICIE1) | _BV(TOIE1);

    /* Enable general interrupts after setup */
    sei();
}

/*
 * tbd
 */
int8_t timer1_nec_get_capture(uint32_t *capture)
{
    /* Get counter capture and update buffer counters */
    if (capture_counter > 0)
    {
        *capture = capture_buffer[capture_out];
        capture_counter--;
        capture_out++;

        if (capture_out >= MAX_NEC_CAPTURE_BUFFER)
            capture_out = 0;

        return 0; /* success */
    }

    return -1; /* no data */
}

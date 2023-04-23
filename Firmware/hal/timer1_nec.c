#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define NEC_START_TIME 27000    /* NEC burst start - 13.5 ms */
#define NEC_REPEAT_TIME 22500   /* NEC burst repeat - 11.5 ms */
#define NEC_BURST_TOLERANCE 200 /* 100 us tolerance */
#define NEC_HIGH_TIME 4500      /* NEC logical 1 - 2.25 ms */
#define NEC_LOW_TIME 2240       /* NEC logical 0 - 1.12 ms */
#define NEC_BIT_TOLERANCE 50    /* 25 us tolerance */

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
static volatile bool new_command = false;

/*
 * tbd
 */
static volatile bool repeat_command = false;

volatile bool edge[100];
volatile uint32_t edge_time[100];
volatile uint16_t edge_counter = 0;

/*
 * Interrupt Service Routine for Timer1 Input Capture
 */
ISR(TIMER1_CAPT_vect)
{
    edge[edge_counter] = (TCCR1B >> ICES1) & 1;
    edge_time[edge_counter] = ICR1;
    edge_time[edge_counter] += ((uint32_t)timer_overflow_counter) << 16;
    edge_counter++;
    if (edge_counter >= 100)
        edge_counter = 0;

    // TCCR1B ^= _BV(ICES1);

    //-----------------
    uint16_t capture;
    uint16_t bit_duration;

    capture = ICR1;
    capture += ((uint32_t)timer_overflow_counter) << 16;

    if (capture >= last_capture)
        bit_duration = capture - last_capture;
    else
        bit_duration = capture - last_capture + 16777215;

    if (bit_duration >= (NEC_START_TIME - NEC_BURST_TOLERANCE) ||
        bit_duration <= (NEC_START_TIME + NEC_BURST_TOLERANCE))
        new_command = true;

    if (bit_duration >= (NEC_REPEAT_TIME - NEC_BURST_TOLERANCE) ||
        bit_duration <= (NEC_REPEAT_TIME + NEC_BURST_TOLERANCE))
        repeat_command = true;

    if (new_command == false)
        return;
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

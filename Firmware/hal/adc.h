#ifndef ADC_H
#define ADC_H

#include <stdbool.h>
#include <stdint.h>

/*
 * tbd
 */
typedef enum
{
    ADC0,
    ADC1,
    ADC2,
    GND
} adc_input_t;

/*
 * tbd
 */
extern volatile bool adc_event;

/*
 * tbd
 */
void adc_init(void);

/*
 * tbd
 */
void adc_select_analog_input(adc_input_t input);

/*
 * tbd
 */
void adc_start_capture(void);

/*
 * tbd
 */
uint16_t adc_get_capture(void);

#endif /* ADC_H */

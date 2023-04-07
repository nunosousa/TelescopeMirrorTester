#ifndef ADC_H
#define ADC_H

typedef enum
{
    ADC0,
    ADC1,
    ADC2,
    TEMP,
    BG_1V1,
    GND
} adc_input_t;

/*
 * tbd
 */
void adc_init(void);

/*
 * tbd
 */
void adc_select_analog_input(adc_input_t input);

#endif /* ADC_H */

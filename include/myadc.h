#ifndef ADC_H
#define ADC_H

static const unsigned short adc_max = 0x3FFF;

void adc_initialize();

unsigned short adc_busy_read();

#endif // ADC_H

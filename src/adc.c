#include "myadc.h"

#include <p18f23k22.h>

void adc_initialize()
{
	// ADC
	TRISAbits.TRISA0 = 1;
	ANSELAbits.ANSA0 = 1;

	// ADC Range
	ADCON1bits.PVCFG = 0;
	ADCON1bits.NVCFG = 0;

	// ADC channel select
	ADCON0bits.CHS = 0;

	ADCON2bits.ADFM = 1;

	// ADC aqquisition time
	ADCON2bits.ACQT0 = 1;
	ADCON2bits.ACQT1 = 0;
	ADCON2bits.ACQT2 = 0;

	ADCON0bits.ADON = 1;
}

unsigned short adc_busy_read()
{
	ADCON0bits.GO = 1;
	while(ADCON0bits.GO );
	
	return ADRES;
}

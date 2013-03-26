#include "led.h"
#include <p18f23k22.h>

void led_initialize()
{
	// Digital Output
	TRISAbits.TRISA4 = 0;
	TRISCbits.TRISC0 = 0;
	TRISCbits.TRISC1 = 0;
}

void led_set_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	if(g) {
		PORTAbits.RA4 = 1;
	}
	else {
		PORTAbits.RA4 = 0;
	}

	if(r) {
		PORTCbits.RC0 = 1;
	}
	else {
		PORTCbits.RC0 = 0;
	}

	if(b) {
		PORTCbits.RC1 = 1;
	}
	else {
		PORTCbits.RC1 = 0;
	}
	
}

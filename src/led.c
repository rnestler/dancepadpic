#include <p18f23k22.h>
#include "led.h"
#include "pwm.h"

void led_initialize()
{
	// Digital Output

	TRISAbits.TRISA4 = 0;
	TRISBbits.TRISB5 = 0;
	TRISCbits.TRISC1 = 0;
	PORTAbits.RA4 = 0;
	PORTBbits.RB5 = 0;
	PORTCbits.RC1 = 0;


	// @TODO: wir wollen selber bitbangen, nicht komische library
	// funktionen verwenden ;)
	OpenPWM5(50,1);
	OpenEPWM2(50,1);
	OpenEPWM3(50,1);
}

void led_set_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	// @TODO: wir wollen selber bitbangen, nicht komische library
	// funktionen verwenden ;)
	SetDCEPWM3(r);
	SetDCPWM5(g);
	SetDCEPWM2(b);
}

#define _XTAL_FREQ 1600000
#include <p18f23k22.h>
#include "myadc.h"
#include "led.h"

void main(void) {

	adc_initialize();
	led_initialize();

	while(1) {
		uint16_t ad=0;
	
		ad = adc_busy_read();
		
		if(ad>0x5000) {
			led_set_rgb(1,0,0);
		}
		else if( ad > 0x4000 ) {
			led_set_rgb(0,1,1);
		}
		else if( ad > 0x3000 ) {
			led_set_rgb(0,0,1);

		}
		else {
			led_set_rgb(0,0,0);
		}
	}
}
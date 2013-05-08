#define _XTAL_FREQ 1600000
#include <p18f23k22.h>
#include "myspi.h"
#include "myadc.h"
#include "led.h"
#include "state.h"

#define TEILER (8)
#define DELAYTIME (TEILER*10)
#define MAX (32)

void main(void) {
	//FOSC = 28;
	adc_initialize();
	led_initialize();

	uint8_t max = MAX;
	uint8_t r=0, g=0, b=0;


	for(r=0; r<max;r++) {
		led_set_rgb(TEILER*r,TEILER*g,TEILER*b);
		__delay_ms(DELAYTIME);
	}
/*
	for(g=0; g<max;g+=1) {
		led_set_rgb(r,g,b);
		r-=1;
		__delay_ms(DELAYTIME);
	}
	for(b=0; b<max;b+=1) {
		led_set_rgb(r,g,b);
		g-=1;
		__delay_ms(DELAYTIME);
	}
	for(r=0; r<max;r+=1) {
		led_set_rgb(r,g,b);
		b-=1;
		__delay_ms(DELAYTIME);
	}
	for(r=max-1; r>0;r--) {
		led_set_rgb(TEILER*r,TEILER*g,TEILER*b);
		__delay_ms(DELAYTIME);
	}
*/

	led_set_rgb(0,0,0);
	r=255; g=0; b=0;
	uint8_t flag = 0;
	State state = stateTest;
	while(1) {
		switch(state) {
		case stateIndpendent: {
			uint16_t ad=0;
		
			ad = adc_busy_read();
	
			if( ad > 0x0180 ) {
				ad-=0x0180;
				led_set_rgb(ad,ad,ad);
			}
			else {
				led_set_rgb(0,0,0);
			}
		} break;
		case stateSPI: {
			uint16_t input = spi_readWord();
			if(input&0x8000) {
				uint8_t r,g,b;
				r = (input&0x7C00)>>10;
				g = (input&0x03E0)>>10;
				b = (input&0x001F);
				led_set_rgb(r,g,b);
			}
			else {
			}
		} break;	
		case stateTest: {
			uint16_t ad=0;
		
			ad = adc_busy_read();
	
			if( ad > 0x0140 && flag==0 ) {
				uint8_t tmp = b;
				b = g;
				g = r;
				r = tmp;
				flag = 1;
				//ad-=0x0180;
				led_set_rgb(r,g,b);
			}
			else if(flag!=0 && ad < 0x0135) {
				flag=0;
			}
		} break;
		}

	}
}
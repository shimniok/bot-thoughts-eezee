/*
* Light_WS2812 library example - RGB_blinky
*
* cycles one LED through red, green, blue
*
* This example is configured for a ATtiny85 with PLL clock fuse set and
* the WS2812 string connected to PB4.
*/

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "light_ws2812.h"

#define DELAY 30
#define COLSTEP 2    // steps between color changes
#define MINCOLOR 0   // lowest color setting (0-255)
#define MAXCOLOR 40  // highest color setting (0-255)

struct cRGB led[1];
uint8_t r, g, b;

int main(void)
{

  #ifdef __AVR_ATtiny10__
  CCP=0xD8;		// configuration change protection, write signature
  CLKPSR=0;		// set cpu clock prescaler =1 (8Mhz) (attiny 4/5/9/10)
  #else
  CLKPR=_BV(CLKPCE);
  CLKPR=0;			// set clock prescaler to 1 (attiny 25/45/85/24/44/84/13/13A)
  #endif

  while(1) {
	// Red to Red+Blue to Blue
	for (r = MAXCOLOR, b = MINCOLOR; b < MAXCOLOR; r -= COLSTEP, b += COLSTEP) {
		led[0].r = r;
		led[0].g = 0;
		led[0].b = b;
		ws2812_setleds(led, 1);
		_delay_ms(DELAY);
	}
	// Blue to Blue+Green to Green
	for (b = MAXCOLOR, g = MINCOLOR; g < MAXCOLOR; b -= COLSTEP, g += COLSTEP) {
		led[0].r = 0;
		led[0].g = g;
		led[0].b = b;
		ws2812_setleds(led, 1);
		_delay_ms(DELAY);
	}
	// Green to Red+Green to Red
	for (g = MAXCOLOR, r = MINCOLOR; r < MAXCOLOR; g -= COLSTEP, r += COLSTEP) {
		led[0].r = r;
		led[0].g = g;
		led[0].b = 0;
		ws2812_setleds(led, 1);
		_delay_ms(DELAY);
	}
  }
}

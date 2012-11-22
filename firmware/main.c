/** Test program for eeZee Tiny
 * 
 * Cycles through set of patterns on available output pins PB0-PB4
 *
 * Author: Michael Shimniok 
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


/* These are the LED patterns */
#define MAXPAT 28
char pattern[MAXPAT] = { _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(3), _BV(2), _BV(1), _BV(0),
						 _BV(0)|_BV(1), _BV(1)|_BV(2), _BV(2)|_BV(3), _BV(3)|_BV(4), _BV(3)|_BV(2), _BV(2)|_BV(1), _BV(1)|_BV(0),
						 _BV(0)|_BV(2), _BV(1)|_BV(3), _BV(2)|_BV(4), _BV(3)|_BV(1), _BV(2)|_BV(0),
						 _BV(0)|_BV(1), _BV(1)|_BV(2), _BV(2)|_BV(3), _BV(3)|_BV(4), _BV(3)|_BV(2), _BV(2)|_BV(1), _BV(1)|_BV(0), };

int main()
{
	int i;

	DDRB = _BV(0)|_BV(1)|_BV(2)|_BV(3)|_BV(4); 	// enable PB0-4 as output pins
	
	while (1) {
		for (i=0; i < MAXPAT; i++) {			// Cycle through the patterns
			PORTB = pattern[i];
			 _delay_ms(300);
		}
	}
}

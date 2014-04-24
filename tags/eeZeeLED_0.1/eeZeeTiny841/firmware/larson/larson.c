/** ATtiny841 test
 * 
 * Author: Michael Shimniok (www.bot-thoughts.com)
 * Description: Sequentially turns on a single pin on PA0-7 and PB0-2. PB3 is reset, PB0, PB1 are XTAL
 *   but still usable if fuses are set to use internal oscillator. Assumes Tiny is sourcing current
 *   to LED (active high)
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DELAY 80

int main()
{
	int i;

	// All PORTA as output
	DDRA=0xff;   
	// PB0-2, PB3 is reset, PB0, PB1 are XTAL
	DDRB=0x07;
	
	PORTA=0;
	PORTB=0;

	while (1) {
		for (i = 0; i < 8; i++) {
			PORTA = (1 << i);
			_delay_ms(DELAY);
		}
		PORTA = 0;
		for (i = 0; i < 3; i++) {
			PORTB = (1 << i);
			_delay_ms(DELAY);
		}
		for (i = 2; i >= 0; i--) {
			PORTB = (1 << i);
			_delay_ms(DELAY);
		}
		PORTB = 0;
		for (i = 7; i >= 0; i--) {
			PORTA = (1 << i);
			_delay_ms(DELAY);
		}
	}

}

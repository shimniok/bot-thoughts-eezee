#include <avr/io.h>
#include <util/delay.h>

/* Simple hello world blinky LED demo for ATtiny841.
 * Michael Shimniok - www.bot-thoughts.com
 * Assumes 16MHz crystal and CKDIV8 disabled, so
 * HFUSE=0xdf
 * LFUSE=0xcf
 * EFUSE=0xff
 */

#define LED PB2

int main() {
	DDRB |= (1<<LED);     // configure pin for output

	while (1) {
  		PINB |= (1<<LED); // toggle pin
  		_delay_ms(100);   // delay 100ms
	}
}

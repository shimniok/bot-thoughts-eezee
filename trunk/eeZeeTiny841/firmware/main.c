#include <avr/io.h>
#include <util/delay.h>

int main() {
	DDRB |= (1<<PB0);

	while (1) {
  		PINB |= (1<<PB0);
  		_delay_ms(1000);
	}
}

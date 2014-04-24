/** Pin test for ATtiny2313
 *
 * Author: Michael Shimniok (www.bot-thoughts.com)
 * Description: Sequentially turns on each pin on PA0-1, PB0-7 and PD0-6
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main()
{
  char i;

  PORTA=0;
  PORTB=0;
  PORTD=0;
  DDRA=0x03;  // PA0-1 (PA2 == ~reset)
  DDRB=0xff;  // PB0-7
  DDRD=0x7f;  // PD0-6

  while (1) {
    for (i = 0 ; i < 2; i++) {
      PORTA = (1 << i);
      _delay_ms(300);
    }
    PORTA = 0;

    for (i = 0; i < 8; i++) {
      PORTB = (1 << i);
      _delay_ms(300);
    }
    PORTB = 0;

    for (i = 0; i < 7; i++) {
      PORTD = (1 << i);
      _delay_ms(300);
    }
    PORTD = 0;

  }

}

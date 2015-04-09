<img src='https://d3ffynyi1lxfcp.cloudfront.net/thumbs/products/522/2013-10-22-17-56-53/IMG_8198.JPG.620x349_q85_crop-smart.jpg' align='right' width='400' />

# Introduction #

After breadboarding a bunch of ATtinys I built these boards so I didn't have to look up the AVR ISP pinout every time.

# Features #

  * AVR ISP header included to save time
  * All 14 pins exposed
  * Included 16MHz crystal and caps++
  * 0.1uF and 10uF (or larger) filtering capacitors
  * Reset switch and pull-up resistor included
  * Works with ATtiny24, ATtiny44, ATtiny84
  * Compact board
  * Works with Arduino IDE - [here's how](TinyArduino.md).

++ You can order it without these if you want.

# Assembly #

  * Solder on each 10-pin header
  * Solder on the 20-pin DIP socket
    * Align the notch with the board silkscreen
    * Notch is farthest from ISP and reset
  * Solder on the 2x3-pin AVR ISP pin header on top
  * Solder on the reset switch
  * Insert your MCU into the socket

# Writing Software #

To write code for ATtiny, you can use:

  * [AVR Studio](http://www.atmel.com/tools/STUDIOARCHIVE.aspx)
  * [Atmel Studio](http://www.atmel.com/microsite/atmel_studio6/)
  * Eclipse and the [AVR Plugin](http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_Eclipse_Plugin)
  * Arduino IDE - [here's how](TinyArduino.md). (Tiny85, 84, 2313 families)

# Programming (Flashing) Your Chip #

The Pololu AVR Programmer is my preferred programmer for most ATtiny projects. Buy the Pololu AVR Programmer at [pololu.com](http://www.pololu.com/product/1300). Follow the instructions in the [User's Guide pdf](http://www.pololu.com/docs/0J36)

You can also use an AVRISP MkII, your Arduino ([here's how](http://arduino.cc/en/Tutorial/ArduinoISP)), or other AVR ISP compatible hardware.

## ISP Header ##

When it's time to plug in your 6-pin programming cable, locate the white rectangle next to the ISP header pin 1.  The cable should have a red stripe marking pin 1 and/or a bump adjacent to pin 3.

![http://www.batsocks.co.uk/img/info_isp/ISP%206%20way%20pinout.png](http://www.batsocks.co.uk/img/info_isp/ISP%206%20way%20pinout.png)

# Example Code #

This example sequentially turns on a single pin on PA0-7 and PB0-2. Connect LEDs and enjoy the light show. [Repository](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZee_medium_tiny%2Ffirmware), [main.c](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZee_medium_tiny/firmware/main.c), [test.hex](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZee_medium_tiny/firmware/eeZeeMedTinyTest.hex)

```
/** ATtiny84 test
 * 
 * Author: Michael Shimniok (www.bot-thoughts.com)
 * Description: Sequentially turns on a single pin on PA0-7 and PB0-2 (PB3 is reset)
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main()
{ 
  char i;
  
  PORTA=0;
  PORTB=0;
  DDRA=0xff;   // All PORTA as output
  DDRB=0x07;   // PB0-2, PB3 is reset
  
  while (1) {
    for (i = 0 ; i < 8; i++) {
      PORTA = (1 << i);
      _delay_ms(300);
    }
    PORTA = 0;
    
    for (i = 2; i < 3; i++) {
      PORTB = (1 << i);
      _delay_ms(300);
    }
    PORTB = 0;
  }

}
```

# Operating Conditions #

Please use your ATtiny breakout boards with regulated supplies of 5V or less, with minimal ripple, at temperatures around 25C (77F). Do not use the boards in higher temperature conditions.
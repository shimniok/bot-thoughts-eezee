<img src='https://lh3.googleusercontent.com/-Q976tG-X9F4/UVBlx2VxQmI/AAAAAAAAIag/Z1cW76fJNAU/s1153/IMG_8226.JPG' align='right' width='400' />

# Introduction #

After breadboarding a bunch of ATtinys I built these boards so I didn't have to look up the AVR ISP pinout every time.

# Features #

  * AVR ISP header included to save time
  * All 20 pins exposed
  * Included 16MHz crystal and caps++
  * 0.1uF and 10uF (or larger) filtering capacitors
  * Reset switch and pull-up resistor included
  * Works with ATtiny2313, ATtiny4313
  * Compact board
  * Works with Arduino - [here's how](TinyArduino.md).

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
  * Arduino IDE - [here's how](TinyArduino.md) (Tiny85, 84, 4313 families)

# Programming (Flashing) Your Chip #

The Pololu AVR Programmer is my preferred programmer for most ATtiny projects. Buy the Pololu AVR Programmer at [pololu.com](http://www.pololu.com/product/1300). Follow the instructions in the [User's Guide pdf](http://www.pololu.com/docs/0J36)

You can also use an AVRISP MkII, your Arduino ([here's how](http://arduino.cc/en/Tutorial/ArduinoISP)), or other AVR ISP compatible hardware.

## ISP Header ##

When it's time to plug in your 6-pin programming cable, locate the white rectangle next to the ISP header pin 1.  The cable should have a red stripe marking pin 1 and/or a bump adjacent to pin 3.

![http://www.batsocks.co.uk/img/info_isp/ISP%206%20way%20pinout.png](http://www.batsocks.co.uk/img/info_isp/ISP%206%20way%20pinout.png)

# Example Code #

This example code sequentially turns on one of each of the Tiny's pins. [Repository](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/#trunk%2FeeZee_big_tiny%2Ffirmware), [main.c](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZee_big_tiny/firmware/main.c), [text.hex](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZee_big_tiny/firmware/eeZeeMedTinyTest.hex)

```
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
```

# Schematics and Layout #

[Eagle files and Gerbers](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/#trunk%2FeeZee_big_tiny%2Felectronics)

# Operating Conditions #

Please use your ATtiny breakout boards with regulated supplies of 5V or less, with minimal ripple, at temperatures around 25C (77F). Do not use the boards in higher temperature conditions or with higher sustained voltages.

# How to Buy #

You can [purchase the eeZee Big Tiny on Tindie](https://tindie.com/shops/bot_thoughts/eezee-attiny2313-target-board/)
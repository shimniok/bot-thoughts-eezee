<img src='https://d3ffynyi1lxfcp.cloudfront.net/thumbs/products/330/2013-08-26-20-55-56/Tiny_wSymbols_noXTAL.JPG.620x349_q85_crop-smart.jpg' align='right' width='400' />

# Introduction #

After breadboarding a bunch of ATtinys I built these boards so I didn't have to look up the AVR ISP pinout every time.

# Features #

  * AVR ISP header included to save time
  * All 8 pins exposed
  * Tiny 1 sq-in. board
  * 0.1uF and 10uF (or larger) filtering capacitors
  * Reset switch and pull-up resistor included
  * Works with ATtiny13,13A, ATtiny25,45,85, ATtiny11, ATtiny12
  * ATtiny 85 works with Arduino - [here's how](TinyArduino.md).

# Assembly #

All you have to do is...

  * Break the 8-pin header in half
  * Solder on these two 4-pin headers
  * Solder on the 8-pin DIP socket on the top
    * Align the notch with the board silkscreen
  * Solder on the 2x3-pin AVR ISP pin header on top
  * Solder on the reset switch
  * Insert your 8-pin ATtiny into the socket

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

This program cycles through a series of patterns on PB0-PB4. Hook up some LEDs and enjoy the light show. [repository](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZee_tiny/firmware/#firmware), [main.c](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZee_tiny/firmware/main.c),  [test.hex](http://bot-thoughts-eezee.googlecode.com/svn/trunk/eeZee_tiny/firmware/default/eeZeeTinyTest1.hex)

```
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

        DDRB = _BV(0)|_BV(1)|_BV(2)|_BV(3)|_BV(4);      // enable PB0-4 as output pins
        
        while (1) {
                for (i=0; i < MAXPAT; i++) {                    // Cycle through the patterns
                        PORTB = pattern[i];
                         _delay_ms(300);
                }
        }
}
```


# Schematics and Layouts #

  * [Eagle Files](http://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZee_tiny%2Felectronics)

# Operating Conditions #

Please use your ATtiny breakout boards with regulated supplies of 5V or less, with minimal ripple, at temperatures around 25C (77F). Do not use the boards in higher temperature conditions or with higher sustained voltages.

# Where to Buy #

You can [Purchase the eeZee Tiny on Tindie](https://tindie.com/shops/bot_thoughts/eezee-tiny-breakout-programming-board-kit/)
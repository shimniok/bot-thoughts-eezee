<img src='https://lh5.googleusercontent.com/-kIaax9B3ZnQ/UyjAYEJ66hI/AAAAAAAAJ80/f9sgkqmFhB0/w916-h610-no/IMG_9950.JPG' align='right' width='400' />

# Introduction #

Now you can use the new, powerful ATtiny841 on your breadboard.

# Features #

  * ATtiny841, 8KB flash, 512B RAM, 512B EEPROM
    * 2 Full Duplex USARTs with Start Frame Detection
    * 1 Master/Slave SPI Serial Interface
    * 1 Slave I2C Serial Interface
    * 1 8-bit (2) 16-bit Timer/Counters w/ (2) PWM Channels,
    * 10-bit Analog to Digital Converter with
      * 12 External and 5 Internal, Single-ended Input Channels
      * 46 Differential ADC Channel Pairs with Programmable Gain (1x / 20x / 100x)
    * 2 On-chip Analog Comparators
  * AVR ISP header included to save time
  * All 14 pins exposed
  * Optionally includes 16MHz crystal and caps
  * 0.1uF and 10uF (or larger) filtering capacitors
  * Reset switch and pull-up resistor included
  * Compact board

# Pinout #

<img src='https://lh3.googleusercontent.com/-79y4iADArvU/UyjAsn_qN7I/AAAAAAAAJ88/ZwvZMlQdhfo/w845-h161-no/Tiny841_pinout.png' />

# Assembly #

  * Solder on each 10-pin header
  * Solder on the 2x3-pin AVR ISP pin header on top
  * Solder on the reset switch

# IDE #

To write code for ATtiny, you can use the following IDEs:

  * [AVR Studio](http://www.atmel.com/tools/STUDIOARCHIVE.aspx)
  * [Atmel Studio](http://www.atmel.com/microsite/atmel_studio6/)
  * Eclipse and the [AVR Plugin](http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_Eclipse_Plugin)
  * Arduino IDE? Not yet. I'm porting [arduino-tiny core](https://github.com/shimniok/arduino-tiny). Want to help?

# Toolchain #

  * Install  [ATmel AVR Toolchain](http://www.atmel.com/products/microcontrollers/avr/tinyAVR.aspx?tab=tools) for either Windows or Linux.
  * Install the latest avrdude.
  * As of Nov 26, 2014, you must still add the contents of [add\_to\_avrdude.conf](https://bot-thoughts-eezee.googlecode.com/svn/trunk/eeZeeTiny841/setup/add_to_avrdude.conf) to your avrdude.conf.

# Programmer #

I use and recommend the following programmers:

  * [pololu.com Pololu AVR Programmer](http://www.pololu.com/product/1300). Follow the instructions in the [User's Guide pdf](http://www.pololu.com/docs/0J36)
  * AVR Dragon

You can also use an AVRISP MkII, your Arduino ([here's how](http://arduino.cc/en/Tutorial/ArduinoISP)), or other AVR ISP compatible hardware.

## ISP Header ##

When it's time to plug in the eeZee Tiny board, locate the white rectangle next to the ISP header which marks pin 1.

<img src='https://lh5.googleusercontent.com/-wPFxKrqw4eo/VHZXhOeSnPI/AAAAAAAAKlI/Hc-qc09wAYA/w893-h571-no/AVRISP6.jpg' width='300' />

<img src='http://www.batsocks.co.uk/img/info_isp/ISP%206%20way%20pinout.png' />

# Example Code #

This example implements a Larson scanner, individually turning on pins PA0-7, PB0-2. Connect LEDs and enjoy the light show. Source: [larson.c](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZeeTiny841/firmware/larson/larson.c). Binary: [larson.hex](https://code.google.com/p/bot-thoughts-eezee/source/browse/trunk/eeZeeTiny841/firmware/larson/larson.hex)

```
/** ATtiny841 test
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

Please use your ATtiny breakout boards with regulated supplies of 5V or less, with minimal ripple, at temperatures around 25C (77F). Do not use the boards in high temperature conditions.

# Source #
  * [source](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZeeTiny841)
  * [electronics](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZeeTiny841%2Felectronics)
  * [firmware demos](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZeeTiny841%2Ffirmware)
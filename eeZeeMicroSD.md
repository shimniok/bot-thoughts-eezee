# Features #

  * It's pin-compatible with your breadbaord ATmega328P.
  * Just plug it into the breadboard and go!
  * Power it from 5V or 3.3V.
  * Add pin headers to plug into the breadboard power strip directly
  * or use the main pin rows. Works safely with 5V logic signals.

Designed, fabricated, and assembled in the United States of America.

All you need to do is solder in the pin headers.

[Order one](https://tindie.com/shops/bot_thoughts/eezee-microsd-breakout-4/) from my [store](https://tindie.com/shops/bot_thoughts/) on Tindie

# Power Options #

Power options abound.

The breakout board has an onboard regulator that you can use or bypass.

  * Regulator
    * Select/solder "REG" on the bottom solder jumper
    * feed 5V into the power pins, 3.3V reaches the microSD card.
  * Regulator Bypass
    * Select/solder "BYP" on the bottom solder jumper
    * feed 3.3V into the power pins, 3.3V reaches the microSD card.

You can power the board off of your breadboard power strip, or using jumpers.

  * Jumpers
    * solder pin headers to the 5V/GND pads at the board edge
    * use jumpers to supply these pins with 5V and GND.
  * Breadboards with dual rail power strips come in two primary forms:
    * Power rail pins aligned to the other breadboard pins. Use the central 5V/GND pin pads
    * Power rail pins offset 0.05" from the other breadboard pins. Use the remaining set of 5V/GND pin pads.

# Code Examples and Documentation #

  * [Arduino SD library reference](http://arduino.cc/en/Reference/SD)
  * [My Arduino Test Programs](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZee_microSD%2Fexamples%2FArduino)
  * Example sketches are available in the Arduino IDE.

Open the Arduino IDE. From the File menu, select Examples, and then select the SD submenu. Under this menu are the examples (e.g.,  Datalogger, DumpFile, Files, ReadWrite and CardInfo)
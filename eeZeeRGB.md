The WS2812B is the latest smart RGB module with onboard microcontroller.

# 3.3V Devices #

  * Care should be taken with 3.3V devices.
  * Use 5V tolerant pins or a level shifter.
  * The 10K pull-up resistor on DIN ensures correct logic levels.
  * This resistor limits current through 3.3V device clamping diodes.
  * Parallax Propeller can tolerate this current.

# Assembly #

  * Install the pin headers on the board so the LED is facing up
  * Connect VDD to 5V capable of driving 60mA per module
  * Connect GND to ground
  * Connect DIN to a pin on your microcontroller

## Current Draw ##

I recommend conservatively estimating a maximum 61mA per board, 60mA for the module and 1mA for the pull-up resistor.

Adafruit has a good [power supply guide](https://learn.adafruit.com/adafruit-neopixel-uberguide/power) available.

Each board has a 10K pull-up resistor (5% tolerance) plus regulator variation (say 10% to be safe), so 0.8mA per board  with a bit extra margin just in case. Round up to 1mA to be really safe.

Your GPIO pin should only see 1mA through the first module's pull-up when pulling down DIN.

## Connecting additional RGB modules ##

  * Connect VDD and GND as described above
  * Connect the first module's DIN to the microcontroller
  * Connect its DOUT to the next module's DIN
  * Repeat for each module

# Arduino: Quick Start #

  * Grab a copy of the [Adafruit NeoPixel Library](http://github.com/adafruit/Adafruit_NeoPixel/)
  * Follow instructions at the link above to install the NeoPixel library
  * You can find my [example code here](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftrunk%2FeeZeeRGB%2Ffirmware)
  * Connect DIN to Arduino D8
  * Compile and download the firmware to your Arduino

# ATtiny: Quick Start #

  * Grab a copy of the Light [WS2812 library](https://github.com/cpldcpu/light_ws2812)
  * Look in the light\_ws2812\_AVR folder
  * Use make to compile the example programs
  * Flash an example hex file to yourATtiny
  * Connect PB1 to DI on the eeZee RGB
  * To change pins, ports, edit ws2812\_config.h and re-make

# Propeller #

You can find a WS2812B driver [here](http://obex.parallax.com/object/703). I have not tested the code myself.

# mbed #

[Example](http://mbed.org/users/okini3939/code/LEDTape_WS2812/). I have not tested the code myself.

# Datasheet #

[WS2812B\_preliminary.pdf](http://www.mikrocontroller.net/attachment/180459/WS2812B_preliminary.pdf)
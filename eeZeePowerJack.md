# Introduction #

A simple, small, low-cost, breadboard power adapter.

Sick of hunting around for something to power your projects? I was. No longer.

  * 6-12V DC input
  * Common 2.1mm power jack, center positive, like Arduino
  * 5V, 500mA or 1.5A MAX output meets nearly all breadboard needs
  * Not just for breadboards, either!
  * Small; only takes up a tiny corner of the breadboard
  * Two sets of output pins for stable installation
  * 100uF 10V and 0.1uF 16V filtering capacitors on the output
  * 10uF 25V and 0.1uF 25V filtering caps on the regulator input
  * All SMT components populated

All you have to do is add pin headers.

Designed and assembled in the United States of America.

# Installation #

  1. Break your breakway header into two 2-pin headers
  1. Solder in the two 2-pin headers for Vcc/GND output, long end down
  1. Use a 6-12V wall-wart power supply with 2.1mm jack and center-positive polarity

# Current Capacity #

The limiting factor on any linear regulator's sustained current capacity is heat. Both chips have internal thermal and current limits so if they get too hot or too much power is drawn, they'll turn off.

Even though the regulator is rated to deliver a maximum of 500mA (in the case of the [LF50](http://datasheet.octopart.com/LF50CDT-TR-STMicroelectronics-datasheet-10887915.pdf)) or 1.5A (with the [LD29150](http://datasheet.octopart.com/LD29150DT33R-STMicroelectronics-datasheet-10540807.pdf)), without adequate cooling it may be unable to do so indefinitely.

Bottom line, keep an eye on the board and chip temperature.

# Which Version Do I Have? #

Boards with a little yellow dot have the LF50 (500mA, max). If there's no yellow dot, it has the LD29150 (1.5A, max).
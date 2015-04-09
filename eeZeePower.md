# Introduction #

A simple, small, low-cost, USB breadboard power adapter.

Sick of hunting around for something to power your projects? I was. No longer.

Plug in your USB mini-B, select 3.3V or 5V (USB voltage), plug it into a dual-rail breadboard, and you have power.

  * Selectable 3.3V / VUSB (5V) output
  * USB Mini-B input
  * Stable: two sets of output pins for stable installation
  * Small; only takes up a tiny corner of the breadboard
  * 100uF and 0.1uF filtering capacitors on the output
  * 10uF and 0.1uF filtering caps on the regulator input
  * All SMT components populated

All you have to do is add pin headers and jumper.

Designed and assembled in the United States of America.

# Installation #

  1. Break your breakway header into one 3-pin and two 2-pin headers
  1. Solder in the 3-pin header for the VUSB/3.3V output selector, long end up
  1. Solder in the two 2-pin headers for Vcc/GND output, long end down
  1. Proceed to the Configuration section.

# Configuration #

3.3V: place the jumper nearest the 3.3V label
5V: place the jumper nearest the VUSB label

# Ratings #

## Rev 0.5 ##

  * All capacitors are rated >10V
  * Vin MAX = 6V (absolute max, 6.3V)
  * Vin MIN = 3.3V + 0.65V @ 500mA (less at lower current)
  * The onboard regulator is a 3.3V Microchip TC1262 ([TC1262.pdf](http://ww1.microchip.com/downloads/en/DeviceDoc/21373C.pdf)) in SOT-223
    * Regulation typically within 0.5%
    * Load current MAX = 500mA continuous
    * Power MAX > 1.5W, given 500mA, 35C
    * The entire board and USB connector act as the heatsink
    * current limit and thermal shutdown protection.

## Rev 0.4 ##

  * All capacitors are rated >10V in this revision.
    * It's designed to be run off of **5V** supplies
  * The onboard regulator is a 3.3V On Semi NCP1117ST33T3G in SOT-223
    * rated at 800mA
    * current limit, safe operating and thermal shutdown protection.
    * Datasheet: [NCP1117ST33T3G.pdf](http://datasheet.octopart.com/NCP1117ST33T3G-ON-Semiconductor-datasheet-11536806.pdf)
    * The regulator uses an integrated 1cm<sup>2</sup> pcb heatsink.

## Older Revs ##

  * All capacitors are rated >6.3V in this revision.
    * It's designed to be run off of **5V** supplies
  * The onboard regulator is a 3.3V On Semi NCP1117ST33T3G in SOT-223
    * rated at **800mA**
    * current limit, safe operating and thermal shutdown protection.
    * Datasheet: [NCP1117ST33T3G.pdf](http://datasheet.octopart.com/NCP1117ST33T3G-ON-Semiconductor-datasheet-11536806.pdf)
    * The regulator uses an integrated 1cm<sup>2</sup> pcb heatsink.
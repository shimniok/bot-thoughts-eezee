<img src='https://lh3.googleusercontent.com/-xr2oeWmwMg8/UMbfGIW8IFI/AAAAAAAAHrI/ekIxMVEdYhE/s1025/IMG_8070.JPG' height='250' /> <img src='https://lh3.googleusercontent.com/-wDnneI9pO6g/UMbfE89JJKI/AAAAAAAAHrA/lMX0mEGxrog/s1023/IMG_8068.JPG' height='250' />

# Introduction #

If you have a Rev0.3 board or higher, see [the current documentation](eeZeeProp.md)

The Parallax Propeller is truly a unique and amazing chip, with 8 cogs running simultaneously and many innovative features and incredible flexibility.

The eeZee Prop brings that power to the breadboard a budget-friendly breakout board ideal for prototyping.

Program it with your existing FTDI or Prop Plug programmer.

The board has a reset button and a power LED, and nothing else to get in the way of your creativity.

# Features #

  * Works with your existing 5V FTDI and Prop Plug programmers
  * A Propeller in breadboard-friendly 36-DIP form factor, 0.8" wide
  * Low cost without unneeded add-ons, perfect for prototyping
  * Onboard 3.3V LDO regulator, flexible power options
  * Includes 5MHz crystal, 256Kbit EEPROM, Reset switch, Power LED
  * Exposes reset pin
  * Selectable BOE with solder jumper
  * Fabricated and assembled in the USA

# Pinout #

![https://lh5.googleusercontent.com/-dQ7OgN6uLnw/UQfzotUKfvI/AAAAAAAAH6s/yRyhdUmMK9o/s674/eeZeePropPinout.jpg](https://lh5.googleusercontent.com/-dQ7OgN6uLnw/UQfzotUKfvI/AAAAAAAAH6s/yRyhdUmMK9o/s674/eeZeePropPinout.jpg)

# Programming #

You can either use an FTDI or Prop Plug to program your eeZee Prop.

  * Prop Plug: provide power through the VIN pin
  * FTDI 3.3V -> power externally through VIN
  * FTDI 5V -> powers the prop plug

## Other Serial Programmers ##

Other serial adapters can be made to work, you just need a programmer with DTR, RX, TX, and GND.

  * Vcc -> (opt) tie to power, or see Power below
  * RXI -> tie to receive (prop out, pc in)
  * TXO -> tie to transmit (prop in, pc out)
  * DTR -> this resets the prop
  * GND -> ground

# Reset #

**Caution:** please don't hold the reset button down with the FTDI connected. The Rev 0.2 board lacks a transistor circuit for the FTDI DTR pin and so pressing the reset button shorts DTR to ground. This seems ok for the occasional, brief reset, according to my tests.

# BOE #

BOE is pulled to ground on the Rev 0.2 boards.

# Power #

Input Voltage: 5.0V-8.0V, room temperature.

Note: lower input voltages are typically possible but not guaranteed in all cases. You may also be able to get away with higher input voltage. The limiting factor is the 10V rating on the input bypass capacitor.

The eeZee Prop can be powered in several ways
  * 3.3V Pin: Connect external 3.3V source (don't connect power to Vin or FTDI)
  * VIN: Connect power, can also have voltage in on FTDI Vcc pin, 3.3V is output
  * FTDI 5V pin: Connect power, can also have voltage on VIN, 3.3V is output

# Source #

This project is Open Source Hardware. Here are the [Eagle Files](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftags%2FeeZee_Prop_0.2).

# Other Propeller Boards #

Other existing programming boards include the [Propeller Board of Education](http://www.parallax.com/Store/Microcontrollers/PropellerDevelopmentBoards/tabid/514/CategoryID/73/List/0/Level/a/ProductID/802/Default.aspx?SortField=ProductName%2cProductName), [PropStick USB](http://www.parallax.com/Store/Microcontrollers/PropellerDevelopmentBoards/tabid/514/CategoryID/73/List/0/catpageindex/2/Level/a/ProductID/411/Default.aspx?SortField=ProductName%2cProductName), [SchmartBoard SchmartModule](http://www.schmartboard.com/index.asp?page=products_populated&id=205), [Propeller QuickStart](http://www.parallax.com/Store/Microcontrollers/PropellerDevelopmentBoards/tabid/514/CategoryID/73/List/0/Level/a/ProductID/748/Default.aspx?SortField=ProductName%2cProductName) board, and others.

The eeZee Prop is breadboard friendly like the PropStick USB, but budget friendly like the QuickStart.  It doesn't add another virtual com port to your system because you use your existing programmer as with the SchmartBoard and others.
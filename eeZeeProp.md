<img src='https://lh3.googleusercontent.com/-xr2oeWmwMg8/UMbfGIW8IFI/AAAAAAAAHrI/ekIxMVEdYhE/s1025/IMG_8070.JPG' height='250' /> <img src='https://lh3.googleusercontent.com/-wDnneI9pO6g/UMbfE89JJKI/AAAAAAAAHrA/lMX0mEGxrog/s1023/IMG_8068.JPG' height='250' />

# Introduction #

Order on [Tindie](https://tindie.com/shops/bot_thoughts/eezee-propeller/)

If you have an older, Rev 0.2 board, see [the Rev 0.2 documentation](eeZeePropRev2.md)

The Parallax Propeller is truly a unique and amazing chip, with 8 cogs running simultaneously and many innovative features and incredible flexibility.

The eeZee Prop brings that power to the breadboard a budget-friendly breakout board ideal for prototyping.

Program it with your existing FTDI or Prop Plug programmer.

The board has a reset button and a power LED, and nothing else to get in the way of your creativity.

# Features #

  * Works with your existing FTDI and Prop Plug programmers
  * A Propeller in breadboard-friendly 36-DIP form factor, 0.8" wide
  * Low cost without unneeded add-ons, perfect for prototyping
  * Onboard 3.3V LDO regulator, flexible power options
  * Includes 5MHz crystal, 32KB EEPROM, Reset switch, Power LED
  * Correctly implemented reset circuitry
  * Exposes reset pin
  * Selectable BOE with solder jumper
  * Fabricated and assembled in the USA

# Pinout #

![https://lh5.googleusercontent.com/-dQ7OgN6uLnw/UQfzotUKfvI/AAAAAAAAH6s/yRyhdUmMK9o/s674/eeZeePropPinout.jpg](https://lh5.googleusercontent.com/-dQ7OgN6uLnw/UQfzotUKfvI/AAAAAAAAH6s/yRyhdUmMK9o/s674/eeZeePropPinout.jpg)

# IDE #

The following are recommended IDEs for Propeller programming:

  * [PropellerIDE](https://lamestation.atlassian.net/wiki/display/PI/Downloads) for Spin/PASM development
  * [SimpleIDE](http://learn.parallax.com/propeller-c-set-simpleide) and [PropGCC](http://code.google.com/p/propgcc/) for writing in C

# Chip Programming #

You can either use a 5V FTDI, 3.3V FTDI or Prop Plug to program your eeZee Prop.

## Other Serial Programmers ##

Other serial adapters can be made to work, you just need a programmer with DTR, RX, TX, and GND.

  * Vcc -> (opt) tie to power, or see Power below
  * RXI -> tie to receive (prop out, pc in)
  * TXO -> tie to transmit (prop in, pc out)
  * DTR -> this resets the prop
  * GND -> ground

# Power #

VIN Pin input voltage: 4.8V-6.0V @ 800mA; 4.7V-6.0V @ 100mA, room temperature. Lower input voltages are typically possible but not guaranteed in all cases. You may also be able to get away with a higher input voltage but the limiting factor is the 10V rating on the 10uF input decoupling capacitor.

Schottky diodes prevent current flowing from one supply (FTDI or VIN) back into the other.

## 5V FTDI ##

  * The 5V FTDI powers the board
  * 3.3V Pin is output, supplying 3.3V to other circuits
  * You can either
    * Connect a 5V supply to the VIN Pin to power the board when the FTDI is disconnected. Unsolder the BYPASS jumper.
    * Make the VIN pin a 5V output pin, powering other circuits from the 5V FTDI. To do so, solder the BYPASS jumper.

Note: with Bypass soldered, never power the board on VIN with FTDI 5V pin connected.

## 3.3V FTDI ##

  * You can either
    * Power the board by applying 5V to VIN Pin. The 3.3V Pin is output, supplying 3.3V to other circuits. Rev 0.5 only: disconnect the 3V3FTDI solder jumper.
    * Power the board by applying 3.3V to the 3V3 Pin. DO NOT connect anything to VIN. Rev 0.5 only: disconnect the 3V3FTDI solder jumper.
    * Rev 0.5 only: Power the board directly from the 3.3V FTDI. Connect the 3V3FTDI solder jumper.

## External 3.3V ##

  * Power the board by applying a 3.3V supply to the 3.3V Pin. DO NOT connect a 5V FTDI when power is applied to the 3.3V pin.

## External 5V ##

  * Connect a 5V supply to the VIN Pin to power the board when the FTDI is disconnected. Unsolder the BYPASS jumper.
  * 3.3V Pin is output, supplying 3.3V to other circuits
  * You can connect a 3.3V FTDI or 5V FTDI at any time

# BOE #

Be sure to solder the BOE solder jumper on the bottom of the board to select the Brown Out Enable mode you prefer.

# Source #

This project is Open Source Hardware. Here are the [Eagle Files](https://code.google.com/p/bot-thoughts-eezee/source/browse/#svn%2Ftags%2FeeZee_Prop_0.2).

# Other Propeller Boards #

Other existing programming boards include the [Propeller Board of Education](http://www.parallax.com/Store/Microcontrollers/PropellerDevelopmentBoards/tabid/514/CategoryID/73/List/0/Level/a/ProductID/802/Default.aspx?SortField=ProductName%2cProductName), [PropStick USB](http://www.parallax.com/Store/Microcontrollers/PropellerDevelopmentBoards/tabid/514/CategoryID/73/List/0/catpageindex/2/Level/a/ProductID/411/Default.aspx?SortField=ProductName%2cProductName), [SchmartBoard SchmartModule](http://www.schmartboard.com/index.asp?page=products_populated&id=205), [Propeller QuickStart](http://www.parallax.com/Store/Microcontrollers/PropellerDevelopmentBoards/tabid/514/CategoryID/73/List/0/Level/a/ProductID/748/Default.aspx?SortField=ProductName%2cProductName) board, and others.

The eeZee Prop is breadboard friendly like the PropStick USB but budget friendly like the QuickStart.  It doesn't add another virtual com port to your system because you use your existing programmer as with the SchmartBoard and others.
# Introduction #

It's possible to use the Arduino IDE to program your ATtiny85, ATtiny84, and ATtiny2313 boards. Here's how.

# Arduino IDE #

Next, you'll need to

  * First you need to download the Arduino IDE
  * Create a folder `hardware` in your Arduino sketchbook folder.
    * `~/Arduino`, `My Documents\Arduino`, or `~Documents/Arduino` depending on platform.
  * Download the [arduino-tiny core](https://code.google.com/p/arduino-tiny/)
  * Unzip the archive into `Arduino/hardware` resulting in a folder `tiny`

# Configuring eeZee Tiny Boards #

Create a file `boards.txt` for your eeZee Tiny boards (85, 84, and 4313, the latter two come in 16MHz crystal and 8MHz internal oscillator versions):

```
###########################################################################
attiny4313at16.name=ATtiny4313 @ 16 MHz  (external crystal; 4.3 V BOD)

#attiny4313at16.upload.using=tiny:arduinoisp
#attiny4313at16.upload.using=tiny:dragon
attiny4313at16.upload.using=tiny:avrispv2
attiny4313at16.upload.maximum_size=4096

# Frequency 16.0- MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
# Brown-out detection level at VCC=4.3 V
# Preserve EEPROM memory through the Chip Erase cycle
# Serial program downloading (SPI) enabled

attiny4313at16.bootloader.low_fuses=0x7F
attiny4313at16.bootloader.high_fuses=0x99
attiny4313at16.bootloader.extended_fuses=0xFF
attiny4313at16.bootloader.path=empty
attiny4313at16.bootloader.file=empty4313at16.hex

attiny4313at16.build.mcu=attiny4313
attiny4313at16.build.f_cpu=16000000L
attiny4313at16.build.core=tiny

###########################################################################
###########################################################################
attiny4313at8.name=ATtiny4313 @ 8 MHz  (internal oscillator; BOD disabled)

#attiny4313at8.upload.using=tiny:arduinoisp
#attiny4313at8.upload.using=tiny:dragon
attiny4313at8.upload.using=tiny:avrispv2
attiny4313at8.upload.maximum_size=4096

# Frequency 8.0- MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
# Brown-out detection disabled
# Preserve EEPROM memory through the Chip Erase cycle
# Serial program downloading (SPI) enabled

attiny4313at8.bootloader.low_fuses=0xE4
attiny4313at8.bootloader.high_fuses=0x9F
attiny4313at8.bootloader.extended_fuses=0xFF
attiny4313at8.bootloader.path=empty
attiny4313at8.bootloader.file=empty4313at8.hex

attiny4313at8.build.mcu=attiny4313
attiny4313at8.build.f_cpu=16000000L
attiny4313at8.build.core=tiny

###########################################################################
###########################################################################
attiny84at16.name=ATtiny84 @ 16 MHz  (external crystal; 4.3 V BOD)

#attiny84at16.upload.using=tiny:arduinoisp
#attiny84at16.upload.using=tiny:dragon
attiny84at16.upload.using=tiny:avrispv2
attiny84at16.upload.maximum_size=8192

# Frequency 16.0MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms;
# Brown-out detection level at VCC=4.3 V;
# Preserve EEPROM memory through the Chip Erase cycle;
# Serial program downloading (SPI) enabled;
attiny84at16.bootloader.low_fuses=0xFF
attiny84at16.bootloader.high_fuses=0xD4
attiny84at16.bootloader.extended_fuses=0xFF
attiny84at16.bootloader.path=empty
attiny84at16.bootloader.file=empty84at16.hex

attiny84at16.build.mcu=attiny84
attiny84at16.build.f_cpu=16000000L
attiny84at16.build.core=tiny

###########################################################################
###########################################################################
attiny84at8.name=ATtiny84 @ 8 MHz  (internal oscillator; BOD disabled)

#attiny84at8.upload.using=tiny:arduinoisp
#attiny84at8.upload.using=tiny:dragon
attiny84at8.upload.using=tiny:avrispv2
attiny84at8.upload.maximum_size=8192

# Frequency 8.0- MHz; Start-up time PWRDWN/RESET: 16K CK/14 CK + 65 ms
# Brown-out detection level disabled
# Preserve EEPROM memory through the Chip Erase cycle
# Serial program downloading (SPI) enabled

attiny84at8.bootloader.low_fuses=0xE2
attiny84at8.bootloader.high_fuses=0xD7
attiny84at8.bootloader.extended_fuses=0xFF
attiny84at8.bootloader.path=empty
attiny84at8.bootloader.file=empty84at16.hex

attiny84at8.build.mcu=attiny84
attiny84at8.build.f_cpu=16000000L
attiny84at8.build.core=tiny

###########################################################################
###########################################################################

attiny85at8.name=ATtiny85 @ 8 MHz  (internal oscillator; BOD disabled)

#attiny85at8.upload.using=tiny:arduinoisp
#attiny85at8.upload.using=tiny:dragon
attiny85at8.upload.using=tiny:avrispv2
attiny85at8.upload.maximum_size=8192

# Default clock (slowly rising power; long delay to clock; 8 MHz internal)
# Int. RC Osc. 8 MHz; Start-up time PWRDWN/RESET: 6 CK/14 CK + 64 ms; [CKSEL=0010 SUT=10]; default value
# Brown-out detection disabled; [BODLEVEL=111]
# Preserve EEPROM memory through the Chip Erase cycle; [EESAVE=0]

attiny85at8.bootloader.low_fuses=0xE2
attiny85at8.bootloader.high_fuses=0xD7
attiny85at8.bootloader.extended_fuses=0xFF
attiny85at8.bootloader.path=empty
attiny85at8.bootloader.file=empty85at8.hex

attiny85at8.build.mcu=attiny85
attiny85at8.build.f_cpu=8000000L
attiny85at8.build.core=tiny

###########################################################################

```

# Configuring Programmer #

You'll need to configure a programmer for the ATtiny boards if you don't have one of the ones listed in the IDE. Create a `programmers.txt` file and put it in `Arduino/hardware/tiny`. For Pololu AVR Programmer, use AVRISPv2.

```
avrispv2.name=AVR ISP v2
avrispv2.communication=serial
avrispv2.protocol=avrispv2

jtag2isp.name=JTAGICE MkII ISP
jtag2isp.communication=usb
jtag2isp.protocol=jtag2isp
jtag2isp.speed=115200

dragon.name=AVR Dragon ISP mode
dragon.communication=usb
dragon.protocol=dragon_isp

```

That's it. Now you can write Arduino sketches for your eeZee Tiny boards!
###############################################################################
# Makefile for the project eeZeeTinyTest1
###############################################################################

## General Flags
PROJECT 		= test
MCU 			= attiny841
PORT 			= usb
PROGRAMMER 		= dragon_isp
F_CPU 			= 8000000UL
TARGET 			= $(PROJECT).elf
AVRBIN 			= /opt/avr/bin
CC 				= $(AVRBIN)/avr-gcc
CPP 			= $(AVRBIN)/avr-g++
OBJCOPY			= $(AVRBIN)/avr-objcopy
OBJDUMP			= $(AVRBIN)/avr-objdump
SIZE			= $(AVRBIN)/avr-size
AVRDUDE			= avrdude

# ATtiny841 Fuses
# HFUSE
#     7 RSTDISBL, disable reset (reset enabled=1, reset disabled=0)
#     6 DWEN, enable debugWIRE (disabled=1, enabled=0)
#     5 SPIEN, enable SPI programming (enabled=0, disabled=1)
#     4 WDTON, watchdog timer permanently on (off=1, on=0)
#     3 EESAVE, preserve EEPROM during chip erase (disable=1, enable=0)
#   2:0 BODLEVEL, sets BOD trigger level (1.8V=111, 2.5V=101, 4.3V=100)
HFUSE			= 0xdf
# LFUSE
#     7 CKDIV8, divide clock by 8 (enable=0, disable=1)
#     6 CKOUT, output sys clock on port pin (disable=1, enable=0)
#     5 -
#     4 SUT, system startup time (14CK+16ms, see CKSEL for PD startup time)
#   3:0 CKSEL, select clock source
#        Source             			From PD		SUT|CKSEL
#		 ====================================================
#		 internal 8MHz					6CK			00010
#		 external						6CK			00000
#		 internal 32-512kHz				6CK			00100
#		 LF Xtal Osc					1K CK		00110
#		 LF Xtal Osc					32K			10110
#		 Xtal Osc, Cer Res 0.4-0.9MHz 	258 CK		01000
#		 Xtal Osc, Cer Res 0.4-0.9MHz	1K CK		11000
#		 Xtal Osc, Cer Res 0.4-0.9MHz	16K CK		01001
#		 Xtal Osc, Cer Res 0.9-3MHz		258 CK		01010
# 		 Xtal Osc, Cer Res 0.9-3MHz		1K CK		11010
#		 Xtal Osc, Cer Res 0.9-3MHz		16K CK		01011
#		 Xtal Osc, Cer Res 3-8MHz		258 CK		01100
#		 Xtal Osc, Cer Res 3-8MHz		1K CK		11100
#		 Xtal Osc, Cer Res 3-8MHz		16K CK		01101
#		 Xtal Osc, Cer Res >8MHz		258 CK		01110
#		 Xtal Osc, Cer Res >8MHz		1K CK		11110
#		 Xtal Osc, Cer Res >8MHz		16K CK		01111
LFUSE			= 0xcf
# EFUSE
#	7:5 ULPOSCSEL, ULP Oscillator Select (32kHz=111, 64kHz=110, 128kHz=101, 256kHz=100, 512kHz=011)
# 	4:3 BODPD, Brown Out Disable, Power Down mode (disabled=11, sampled=01, enabled=10)
# 	2:1 BODACT, Brown Out Disable, Active mode (disabled=11, sampled=01, enabled=10)
# 	  0 SELFPRGEN, Self Program Enable (disabled=1, enabled=0)
EFUSE			= 0xff

## Objects that must be built in order to link
OBJECTS = main.o 

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=$(F_CPU) -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=$(PROJECT).map

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss size

## Compile
main.o: main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	$(OBJCOPY) -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-$(OBJCOPY) $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	$(OBJDUMP) -h -S $< > $@

install: $(PROJECT).hex
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -v -U flash:w:$(PROJECT).hex

fuses:
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -v -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

size: ${TARGET}
	@echo
	@$(SIZE) -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(PROJECT).elf dep/* $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss $(PROJECT).map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)


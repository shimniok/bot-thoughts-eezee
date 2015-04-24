################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Tiny84ISP.lss \

FLASH_IMAGE += \
Tiny84ISP.hex \

EEPROM_IMAGE += \
Tiny84ISP.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tiny84ISP.elf secondary-outputs

# Tool invocations
Tiny84ISP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tiny84ISP.map -L"/home/mes/workspace/TinySoftSerial/Release" -mmcu=attiny84a -o "Tiny84ISP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tiny84ISP.lss: Tiny84ISP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tiny84ISP.elf  >"Tiny84ISP.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tiny84ISP.hex: Tiny84ISP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tiny84ISP.elf  "Tiny84ISP.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tiny84ISP.eep: Tiny84ISP.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tiny84ISP.elf  "Tiny84ISP.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tiny84ISP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t Tiny84ISP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tiny84ISP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

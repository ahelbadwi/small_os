################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SL/subdir.mk
-include McAl/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Sos.lss \

FLASH_IMAGE += \
Sos.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Sos.elf secondary-outputs

# Tool invocations
Sos.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Sos.map -mmcu=atmega32 -o "Sos.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Sos.lss: Sos.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Sos.elf  >"Sos.lss"
	@echo 'Finished building: $@'
	@echo ' '

Sos.hex: Sos.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Sos.elf  "Sos.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Sos.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Sos.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Sos.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/ULTRASONIC_SENSOR/subdir.mk
-include HAL/SERVO_MOTOR/subdir.mk
-include HAL/MOTORS_CAR/subdir.mk
-include HAL/LCD/subdir.mk
-include APP/subdir.mk
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
SLAVE_CAR.lss \

FLASH_IMAGE += \
SLAVE_CAR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SLAVE_CAR.elf secondary-outputs

# Tool invocations
SLAVE_CAR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SLAVE_CAR.map -mmcu=atmega32 -o "SLAVE_CAR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SLAVE_CAR.lss: SLAVE_CAR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SLAVE_CAR.elf  >"SLAVE_CAR.lss"
	@echo 'Finished building: $@'
	@echo ' '

SLAVE_CAR.hex: SLAVE_CAR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SLAVE_CAR.elf  "SLAVE_CAR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SLAVE_CAR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SLAVE_CAR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SLAVE_CAR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

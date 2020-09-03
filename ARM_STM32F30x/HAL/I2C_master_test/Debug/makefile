################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
RASP_I2C_test.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RASP_I2C_test.list \

OBJCOPY_BIN += \
RASP_I2C_test.bin \


# All Target
all: RASP_I2C_test.elf secondary-outputs

# Tool invocations
RASP_I2C_test.elf: $(OBJS) $(USER_OBJS) C:\Users\e.anfimov\Documents\RASP_I2C_test\STM32F303VCTX_FLASH.ld
	arm-none-eabi-gcc -o "RASP_I2C_test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\e.anfimov\Documents\RASP_I2C_test\STM32F303VCTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="RASP_I2C_test.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RASP_I2C_test.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RASP_I2C_test.list"
	@echo 'Finished building: $@'
	@echo ' '

RASP_I2C_test.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "RASP_I2C_test.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

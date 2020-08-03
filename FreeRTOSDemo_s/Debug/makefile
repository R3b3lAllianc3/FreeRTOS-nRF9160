################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include SecureInit/subdir.mk
-include SecureHeap/subdir.mk
-include SecureContext/subdir.mk
-include Nordic_Code/mdk/subdir.mk
-include Nordic_Code/arm_m33_core/subdir.mk
-include NSCFunctions/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FreeRTOSDemo_s.axf

# Tool invocations
FreeRTOSDemo_s.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker --cmse-implib -Xlinker --out-implib=FreeRTOSDemo_s_CMSE_lib.o -Xlinker -Map="FreeRTOSDemo_s.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -T ../FreeRTOSDemo_s.ld -Xlinker --out-implib="FreeRTOSDemo_s_CMSE_lib.o" -Xlinker --cmse-implib -o "FreeRTOSDemo_s.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FreeRTOSDemo_s.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "FreeRTOSDemo_s.axf"; # arm-none-eabi-objcopy -v -O binary "FreeRTOSDemo_s.axf" "FreeRTOSDemo_s.bin" ; # checksum -p  -d "FreeRTOSDemo_s.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets

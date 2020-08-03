################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Nordic_Code/mdk/subdir.mk
-include Nordic_Code/libraries/util/subdir.mk
-include Nordic_Code/libraries/uarte/subdir.mk
-include Nordic_Code/libraries/timer/subdir.mk
-include Nordic_Code/libraries/strerror/subdir.mk
-include Nordic_Code/libraries/sortlist/subdir.mk
-include Nordic_Code/libraries/ringbuf/subdir.mk
-include Nordic_Code/libraries/queue/subdir.mk
-include Nordic_Code/libraries/pwr_mgmt/subdir.mk
-include Nordic_Code/libraries/memobj/subdir.mk
-include Nordic_Code/libraries/log/subdir.mk
-include Nordic_Code/libraries/fstorage/subdir.mk
-include Nordic_Code/libraries/fprintf/subdir.mk
-include Nordic_Code/libraries/fds/subdir.mk
-include Nordic_Code/libraries/experimental_section_vars/subdir.mk
-include Nordic_Code/libraries/clock/subdir.mk
-include Nordic_Code/libraries/cli/uart/subdir.mk
-include Nordic_Code/libraries/cli/subdir.mk
-include Nordic_Code/libraries/balloc/subdir.mk
-include Nordic_Code/libraries/atomic_fifo/subdir.mk
-include Nordic_Code/libraries/atomic/subdir.mk
-include Nordic_Code/drivers/subdir.mk
-include Nordic_Code/board_pca10090/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/ARM_CM33/non_secure/subdir.mk
-include FreeRTOS/portable/Common/subdir.mk
-include FreeRTOS/subdir.mk
-include Demos/subdir.mk
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
all: FreeRTOSDemo_ns.axf

# Tool invocations
FreeRTOSDemo_ns.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="FreeRTOSDemo_ns.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -T ../FreeRTOSDemo_ns.ld -o "FreeRTOSDemo_ns.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FreeRTOSDemo_ns.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "FreeRTOSDemo_ns.axf"; # arm-none-eabi-objcopy -v -O binary "FreeRTOSDemo_ns.axf" "FreeRTOSDemo_ns.bin" ; # checksum -p Generic_M33 -d "FreeRTOSDemo_ns.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets

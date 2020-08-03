################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Nordic_Code/libraries/sortlist/nrf_sortlist.c 

OBJS += \
./Nordic_Code/libraries/sortlist/nrf_sortlist.o 

C_DEPS += \
./Nordic_Code/libraries/sortlist/nrf_sortlist.d 


# Each subdirectory must supply rules for building sources it contributes
Nordic_Code/libraries/sortlist/%.o: ../Nordic_Code/libraries/sortlist/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DARM_MATH_CM33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -DNRF9160_XXAA -DAPP_TIMER_V2 -DAPP_TIMER_V2_RTC1_ENABLED -DFREERTOS -DNRF_TRUSTZONE_NONSECURE -I../Config -I../Demos/ -I../Common/ARMv8M/mpu_demo -I../Common/ARMv8M/tz_demo -I../Nordic_Code/board_pca10090/ -I../FreeRTOS/include -I../FreeRTOS/portable/GCC/ARM_CM33/secure -I../FreeRTOS/portable/GCC/ARM_CM33/non_secure -I../Nordic_Code/sdk_config/ -I../Nordic_Code/CMSIS/ -I../Nordic_Code/drivers/ -I../Nordic_Code/mdk/ -I../Nordic_Code/mdk/hal/ -I../Nordic_Code/libraries/util/ -I../Nordic_Code/libraries/log/ -I../Nordic_Code/libraries/log/src/ -I../Nordic_Code/libraries/uarte/ -I../Nordic_Code/libraries/memobj/ -I../Nordic_Code/libraries/balloc/ -I../Nordic_Code/libraries/experimental_section_vars/ -I../Nordic_Code/libraries/fprintf/ -I../Nordic_Code/libraries/strerror/ -I../Nordic_Code/libraries/ringbuf/ -I../Nordic_Code/libraries/atomic/ -I../Nordic_Code/libraries/delay/ -I../Nordic_Code/libraries/timer/ -I../Nordic_Code/libraries/sortlist/ -I../Nordic_Code/libraries/atomic_fifo/ -I../Nordic_Code/libraries/cli -I../Nordic_Code/libraries/cli/uart -I../Nordic_Code/libraries/queue -I../Nordic_Code/libraries/pwr_mgmt -I../Nordic_Code/libraries/fds -I../Nordic_Code/libraries/clock -I../Nordic_Code/libraries/fstorage -I../Nordic_Code/libraries/experimental_section_vars/ -I../Nordic_Code/nrf_soc_nosd -O0 -fno-common -g -Wall -D __SEMIHOST_HARDFAULT_DISABLE  -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



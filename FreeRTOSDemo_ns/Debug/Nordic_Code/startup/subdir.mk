################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/Nordic_Code/startup/startup_nrf9160.c 

OBJS += \
./Nordic_Code/startup/startup_nrf9160.o 

C_DEPS += \
./Nordic_Code/startup/startup_nrf9160.d 


# Each subdirectory must supply rules for building sources it contributes
Nordic_Code/startup/startup_nrf9160.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/Nordic_Code/startup/startup_nrf9160.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DARM_MATH_CM33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -DNRF9160_XXAA -I../../Config -I../../../../../../Demo/Common/ARMv8M/mpu_demo -I../../../../../../Demo/Common/ARMv8M/tz_demo -I../../../../../../Source/include -I../../../../../../Source/portable/GCC/ARM_CM33/secure -I../../../../../../Source/portable/GCC/ARM_CM33/non_secure -I../../../../Nordic_Code/startup -I../../../../Nordic_Code/CMSIS -O0 -fno-common -g -Wall -D __SEMIHOST_HARDFAULT_DISABLE  -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



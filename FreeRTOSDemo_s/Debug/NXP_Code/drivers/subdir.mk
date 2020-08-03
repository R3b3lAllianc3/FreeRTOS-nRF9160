################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_clock.c \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_common.c \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_flexcomm.c \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_gpio.c \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_power.c \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_reset.c \
C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_usart.c 

OBJS += \
./NXP_Code/drivers/fsl_clock.o \
./NXP_Code/drivers/fsl_common.o \
./NXP_Code/drivers/fsl_flexcomm.o \
./NXP_Code/drivers/fsl_gpio.o \
./NXP_Code/drivers/fsl_power.o \
./NXP_Code/drivers/fsl_reset.o \
./NXP_Code/drivers/fsl_usart.o 

C_DEPS += \
./NXP_Code/drivers/fsl_clock.d \
./NXP_Code/drivers/fsl_common.d \
./NXP_Code/drivers/fsl_flexcomm.d \
./NXP_Code/drivers/fsl_gpio.d \
./NXP_Code/drivers/fsl_power.d \
./NXP_Code/drivers/fsl_reset.d \
./NXP_Code/drivers/fsl_usart.d 


# Each subdirectory must supply rules for building sources it contributes
NXP_Code/drivers/fsl_clock.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_clock.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NXP_Code/drivers/fsl_common.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NXP_Code/drivers/fsl_flexcomm.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_flexcomm.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NXP_Code/drivers/fsl_gpio.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NXP_Code/drivers/fsl_power.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_power.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NXP_Code/drivers/fsl_reset.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_reset.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

NXP_Code/drivers/fsl_usart.o: C:/nordic_local/nordic_local/AWS/FreeRTOSv10.2.1/FreeRTOS/Demo/CORTEX_MPU_Nordic_nRF9160_MCUXpresso/NXP_Code/drivers/fsl_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../../Config -I../../../../NXP_Code -I../../../../NXP_Code/board -I../../../../NXP_Code/source -I../../../../NXP_Code/drivers -I../../../../NXP_Code/CMSIS -I../../../../NXP_Code/device -I../../../../NXP_Code/startup -I../../../../NXP_Code/component/serial_manager -I../../../../NXP_Code/utilities -I../../../../NXP_Code/component/uart -I../../../../NXP_Code/component/lists -I../../../../../../Source/portable/GCC/ARM_CM33/secure -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



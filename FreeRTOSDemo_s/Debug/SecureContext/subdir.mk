################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SecureContext/secure_context.c \
../SecureContext/secure_context_port.c 

OBJS += \
./SecureContext/secure_context.o \
./SecureContext/secure_context_port.o 

C_DEPS += \
./SecureContext/secure_context.d \
./SecureContext/secure_context_port.d 


# Each subdirectory must supply rules for building sources it contributes
SecureContext/%.o: ../SecureContext/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DNRF9160_XXAA -DARM_MATH_CM33 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../Config -I../Nordic_Code/CMSIS/ -I../FreeRTOS/portable/GCC/ARM_CM33/secure/ -I../Nordic_Code/mdk/ -I../User/ -I../../../../../../Source/portable/GCC/ARM_CM33/secure -I../Nordic_Code/board/pca10090/ -I../Nordic_Code/libraries/util/ -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/main_s.c \
../User/tzm_config.c 

OBJS += \
./User/main_s.o \
./User/tzm_config.o 

C_DEPS += \
./User/main_s.d \
./User/tzm_config.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DNRF9160_XXAA -DARM_MATH_CM33 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../Config -I../Nordic_Code/CMSIS/ -I../FreeRTOS/portable/GCC/ARM_CM33/secure/ -I../Nordic_Code/mdk/ -I../User/ -I../../../../../../Source/portable/GCC/ARM_CM33/secure -I../Nordic_Code/board/pca10090/ -I../Nordic_Code/libraries/util/ -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



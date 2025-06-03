################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ADC/adc.c \
../Drivers/ADC/ntc.c 

OBJS += \
./Drivers/ADC/adc.o \
./Drivers/ADC/ntc.o 

C_DEPS += \
./Drivers/ADC/adc.d \
./Drivers/ADC/ntc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ADC/%.o Drivers/ADC/%.su Drivers/ADC/%.cyclo: ../Drivers/ADC/%.c Drivers/ADC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ADC

clean-Drivers-2f-ADC:
	-$(RM) ./Drivers/ADC/adc.cyclo ./Drivers/ADC/adc.d ./Drivers/ADC/adc.o ./Drivers/ADC/adc.su ./Drivers/ADC/ntc.cyclo ./Drivers/ADC/ntc.d ./Drivers/ADC/ntc.o ./Drivers/ADC/ntc.su

.PHONY: clean-Drivers-2f-ADC


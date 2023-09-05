################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Adafruit_GFX/fontconvert/fontconvert.c 

C_DEPS += \
./Core/Inc/Adafruit_GFX/fontconvert/fontconvert.d 

OBJS += \
./Core/Inc/Adafruit_GFX/fontconvert/fontconvert.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Adafruit_GFX/fontconvert/%.o Core/Inc/Adafruit_GFX/fontconvert/%.su: ../Core/Inc/Adafruit_GFX/fontconvert/%.c Core/Inc/Adafruit_GFX/fontconvert/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Adafruit_GFX-2f-fontconvert

clean-Core-2f-Inc-2f-Adafruit_GFX-2f-fontconvert:
	-$(RM) ./Core/Inc/Adafruit_GFX/fontconvert/fontconvert.d ./Core/Inc/Adafruit_GFX/fontconvert/fontconvert.o ./Core/Inc/Adafruit_GFX/fontconvert/fontconvert.su

.PHONY: clean-Core-2f-Inc-2f-Adafruit_GFX-2f-fontconvert


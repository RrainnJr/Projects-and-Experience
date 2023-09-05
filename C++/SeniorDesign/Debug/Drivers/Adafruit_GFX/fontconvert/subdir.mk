################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Adafruit_GFX/fontconvert/fontconvert.c 

C_DEPS += \
./Drivers/Adafruit_GFX/fontconvert/fontconvert.d 

OBJS += \
./Drivers/Adafruit_GFX/fontconvert/fontconvert.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Adafruit_GFX/fontconvert/%.o Drivers/Adafruit_GFX/fontconvert/%.su: ../Drivers/Adafruit_GFX/fontconvert/%.c Drivers/Adafruit_GFX/fontconvert/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Adafruit_GFX-2f-fontconvert

clean-Drivers-2f-Adafruit_GFX-2f-fontconvert:
	-$(RM) ./Drivers/Adafruit_GFX/fontconvert/fontconvert.d ./Drivers/Adafruit_GFX/fontconvert/fontconvert.o ./Drivers/Adafruit_GFX/fontconvert/fontconvert.su

.PHONY: clean-Drivers-2f-Adafruit_GFX-2f-fontconvert


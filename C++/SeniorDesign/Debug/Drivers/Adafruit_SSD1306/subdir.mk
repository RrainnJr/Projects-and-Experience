################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/Adafruit_SSD1306/Adafruit_SSD1306.cpp 

OBJS += \
./Drivers/Adafruit_SSD1306/Adafruit_SSD1306.o 

CPP_DEPS += \
./Drivers/Adafruit_SSD1306/Adafruit_SSD1306.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Adafruit_SSD1306/%.o Drivers/Adafruit_SSD1306/%.su: ../Drivers/Adafruit_SSD1306/%.cpp Drivers/Adafruit_SSD1306/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Adafruit_SSD1306

clean-Drivers-2f-Adafruit_SSD1306:
	-$(RM) ./Drivers/Adafruit_SSD1306/Adafruit_SSD1306.d ./Drivers/Adafruit_SSD1306/Adafruit_SSD1306.o ./Drivers/Adafruit_SSD1306/Adafruit_SSD1306.su

.PHONY: clean-Drivers-2f-Adafruit_SSD1306


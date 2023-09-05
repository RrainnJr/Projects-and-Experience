################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Adafruit_GFX/glcdfont.c 

CPP_SRCS += \
../Core/Inc/Adafruit_GFX/Adafruit_GFX.cpp \
../Core/Inc/Adafruit_GFX/Adafruit_GrayOLED.cpp \
../Core/Inc/Adafruit_GFX/Adafruit_SPITFT.cpp 

C_DEPS += \
./Core/Inc/Adafruit_GFX/glcdfont.d 

OBJS += \
./Core/Inc/Adafruit_GFX/Adafruit_GFX.o \
./Core/Inc/Adafruit_GFX/Adafruit_GrayOLED.o \
./Core/Inc/Adafruit_GFX/Adafruit_SPITFT.o \
./Core/Inc/Adafruit_GFX/glcdfont.o 

CPP_DEPS += \
./Core/Inc/Adafruit_GFX/Adafruit_GFX.d \
./Core/Inc/Adafruit_GFX/Adafruit_GrayOLED.d \
./Core/Inc/Adafruit_GFX/Adafruit_SPITFT.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Adafruit_GFX/%.o Core/Inc/Adafruit_GFX/%.su: ../Core/Inc/Adafruit_GFX/%.cpp Core/Inc/Adafruit_GFX/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Inc/Adafruit_GFX/%.o Core/Inc/Adafruit_GFX/%.su: ../Core/Inc/Adafruit_GFX/%.c Core/Inc/Adafruit_GFX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Adafruit_GFX

clean-Core-2f-Inc-2f-Adafruit_GFX:
	-$(RM) ./Core/Inc/Adafruit_GFX/Adafruit_GFX.d ./Core/Inc/Adafruit_GFX/Adafruit_GFX.o ./Core/Inc/Adafruit_GFX/Adafruit_GFX.su ./Core/Inc/Adafruit_GFX/Adafruit_GrayOLED.d ./Core/Inc/Adafruit_GFX/Adafruit_GrayOLED.o ./Core/Inc/Adafruit_GFX/Adafruit_GrayOLED.su ./Core/Inc/Adafruit_GFX/Adafruit_SPITFT.d ./Core/Inc/Adafruit_GFX/Adafruit_SPITFT.o ./Core/Inc/Adafruit_GFX/Adafruit_SPITFT.su ./Core/Inc/Adafruit_GFX/glcdfont.d ./Core/Inc/Adafruit_GFX/glcdfont.o ./Core/Inc/Adafruit_GFX/glcdfont.su

.PHONY: clean-Core-2f-Inc-2f-Adafruit_GFX


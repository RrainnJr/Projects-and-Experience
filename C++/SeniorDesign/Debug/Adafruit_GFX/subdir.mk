################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Adafruit_GFX/glcdfont.c 

CPP_SRCS += \
../Adafruit_GFX/Adafruit_GFX.cpp \
../Adafruit_GFX/Adafruit_GrayOLED.cpp \
../Adafruit_GFX/Adafruit_SPITFT.cpp 

C_DEPS += \
./Adafruit_GFX/glcdfont.d 

OBJS += \
./Adafruit_GFX/Adafruit_GFX.o \
./Adafruit_GFX/Adafruit_GrayOLED.o \
./Adafruit_GFX/Adafruit_SPITFT.o \
./Adafruit_GFX/glcdfont.o 

CPP_DEPS += \
./Adafruit_GFX/Adafruit_GFX.d \
./Adafruit_GFX/Adafruit_GrayOLED.d \
./Adafruit_GFX/Adafruit_SPITFT.d 


# Each subdirectory must supply rules for building sources it contributes
Adafruit_GFX/%.o Adafruit_GFX/%.su: ../Adafruit_GFX/%.cpp Adafruit_GFX/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Adafruit_GFX/%.o Adafruit_GFX/%.su: ../Adafruit_GFX/%.c Adafruit_GFX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Adafruit_GFX

clean-Adafruit_GFX:
	-$(RM) ./Adafruit_GFX/Adafruit_GFX.d ./Adafruit_GFX/Adafruit_GFX.o ./Adafruit_GFX/Adafruit_GFX.su ./Adafruit_GFX/Adafruit_GrayOLED.d ./Adafruit_GFX/Adafruit_GrayOLED.o ./Adafruit_GFX/Adafruit_GrayOLED.su ./Adafruit_GFX/Adafruit_SPITFT.d ./Adafruit_GFX/Adafruit_SPITFT.o ./Adafruit_GFX/Adafruit_SPITFT.su ./Adafruit_GFX/glcdfont.d ./Adafruit_GFX/glcdfont.o ./Adafruit_GFX/glcdfont.su

.PHONY: clean-Adafruit_GFX


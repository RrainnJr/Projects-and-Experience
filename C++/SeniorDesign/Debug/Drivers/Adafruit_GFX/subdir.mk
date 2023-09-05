################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Adafruit_GFX/glcdfont.c 

CPP_SRCS += \
../Drivers/Adafruit_GFX/Adafruit_GFX.cpp \
../Drivers/Adafruit_GFX/Adafruit_GrayOLED.cpp \
../Drivers/Adafruit_GFX/Adafruit_SPITFT.cpp 

C_DEPS += \
./Drivers/Adafruit_GFX/glcdfont.d 

OBJS += \
./Drivers/Adafruit_GFX/Adafruit_GFX.o \
./Drivers/Adafruit_GFX/Adafruit_GrayOLED.o \
./Drivers/Adafruit_GFX/Adafruit_SPITFT.o \
./Drivers/Adafruit_GFX/glcdfont.o 

CPP_DEPS += \
./Drivers/Adafruit_GFX/Adafruit_GFX.d \
./Drivers/Adafruit_GFX/Adafruit_GrayOLED.d \
./Drivers/Adafruit_GFX/Adafruit_SPITFT.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Adafruit_GFX/%.o Drivers/Adafruit_GFX/%.su: ../Drivers/Adafruit_GFX/%.cpp Drivers/Adafruit_GFX/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/Adafruit_GFX/%.o Drivers/Adafruit_GFX/%.su: ../Drivers/Adafruit_GFX/%.c Drivers/Adafruit_GFX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Adafruit_GFX

clean-Drivers-2f-Adafruit_GFX:
	-$(RM) ./Drivers/Adafruit_GFX/Adafruit_GFX.d ./Drivers/Adafruit_GFX/Adafruit_GFX.o ./Drivers/Adafruit_GFX/Adafruit_GFX.su ./Drivers/Adafruit_GFX/Adafruit_GrayOLED.d ./Drivers/Adafruit_GFX/Adafruit_GrayOLED.o ./Drivers/Adafruit_GFX/Adafruit_GrayOLED.su ./Drivers/Adafruit_GFX/Adafruit_SPITFT.d ./Drivers/Adafruit_GFX/Adafruit_SPITFT.o ./Drivers/Adafruit_GFX/Adafruit_SPITFT.su ./Drivers/Adafruit_GFX/glcdfont.d ./Drivers/Adafruit_GFX/glcdfont.o ./Drivers/Adafruit_GFX/glcdfont.su

.PHONY: clean-Drivers-2f-Adafruit_GFX


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../X-CUBE-AI/App/sine_model.c \
../X-CUBE-AI/App/sine_model_1641213730071.c \
../X-CUBE-AI/App/sine_model_1641213730071_data.c \
../X-CUBE-AI/App/sine_model_data.c \
../X-CUBE-AI/App/tonecrafter.c \
../X-CUBE-AI/App/tonecrafter_data.c 

OBJS += \
./X-CUBE-AI/App/sine_model.o \
./X-CUBE-AI/App/sine_model_1641213730071.o \
./X-CUBE-AI/App/sine_model_1641213730071_data.o \
./X-CUBE-AI/App/sine_model_data.o \
./X-CUBE-AI/App/tonecrafter.o \
./X-CUBE-AI/App/tonecrafter_data.o 

C_DEPS += \
./X-CUBE-AI/App/sine_model.d \
./X-CUBE-AI/App/sine_model_1641213730071.d \
./X-CUBE-AI/App/sine_model_1641213730071_data.d \
./X-CUBE-AI/App/sine_model_data.d \
./X-CUBE-AI/App/tonecrafter.d \
./X-CUBE-AI/App/tonecrafter_data.d 


# Each subdirectory must supply rules for building sources it contributes
X-CUBE-AI/App/%.o: ../X-CUBE-AI/App/%.c X-CUBE-AI/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


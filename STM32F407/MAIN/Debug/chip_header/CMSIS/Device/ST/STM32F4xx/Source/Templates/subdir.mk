################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c 

OBJS += \
./chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o 

C_DEPS += \
./chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.o chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.su chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.cyclo: ../chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.c chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DARM_MATH_CM4 -c -I../Inc -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/DSP/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_header-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates

clean-chip_header-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates:
	-$(RM) ./chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.cyclo ./chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d ./chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o ./chip_header/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.su

.PHONY: clean-chip_header-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates


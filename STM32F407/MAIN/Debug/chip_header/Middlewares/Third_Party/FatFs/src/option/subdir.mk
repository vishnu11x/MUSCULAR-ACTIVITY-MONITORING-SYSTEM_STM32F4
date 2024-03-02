################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.o 

C_DEPS += \
./chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
chip_header/Middlewares/Third_Party/FatFs/src/option/%.o chip_header/Middlewares/Third_Party/FatFs/src/option/%.su chip_header/Middlewares/Third_Party/FatFs/src/option/%.cyclo: ../chip_header/Middlewares/Third_Party/FatFs/src/option/%.c chip_header/Middlewares/Third_Party/FatFs/src/option/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DARM_MATH_CM4 -c -I../Inc -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/DSP/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/Middlewares/Third_Party/FatFs/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_header-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-option

clean-chip_header-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-option:
	-$(RM) ./chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.cyclo ./chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.d ./chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.o ./chip_header/Middlewares/Third_Party/FatFs/src/option/syscall.su

.PHONY: clean-chip_header-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-option


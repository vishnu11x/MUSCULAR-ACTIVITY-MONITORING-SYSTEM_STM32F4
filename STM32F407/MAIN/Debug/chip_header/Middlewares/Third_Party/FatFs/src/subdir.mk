################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_header/Middlewares/Third_Party/FatFs/src/diskio.c \
../chip_header/Middlewares/Third_Party/FatFs/src/ff.c \
../chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c 

OBJS += \
./chip_header/Middlewares/Third_Party/FatFs/src/diskio.o \
./chip_header/Middlewares/Third_Party/FatFs/src/ff.o \
./chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.o 

C_DEPS += \
./chip_header/Middlewares/Third_Party/FatFs/src/diskio.d \
./chip_header/Middlewares/Third_Party/FatFs/src/ff.d \
./chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
chip_header/Middlewares/Third_Party/FatFs/src/%.o chip_header/Middlewares/Third_Party/FatFs/src/%.su chip_header/Middlewares/Third_Party/FatFs/src/%.cyclo: ../chip_header/Middlewares/Third_Party/FatFs/src/%.c chip_header/Middlewares/Third_Party/FatFs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DARM_MATH_CM4 -c -I../Inc -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/DSP/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/Middlewares/Third_Party/FatFs/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_header-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src

clean-chip_header-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src:
	-$(RM) ./chip_header/Middlewares/Third_Party/FatFs/src/diskio.cyclo ./chip_header/Middlewares/Third_Party/FatFs/src/diskio.d ./chip_header/Middlewares/Third_Party/FatFs/src/diskio.o ./chip_header/Middlewares/Third_Party/FatFs/src/diskio.su ./chip_header/Middlewares/Third_Party/FatFs/src/ff.cyclo ./chip_header/Middlewares/Third_Party/FatFs/src/ff.d ./chip_header/Middlewares/Third_Party/FatFs/src/ff.o ./chip_header/Middlewares/Third_Party/FatFs/src/ff.su ./chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.cyclo ./chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.d ./chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.o ./chip_header/Middlewares/Third_Party/FatFs/src/ff_gen_drv.su

.PHONY: clean-chip_header-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src


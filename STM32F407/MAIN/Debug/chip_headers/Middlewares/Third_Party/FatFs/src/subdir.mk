################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../chip_headers/Middlewares/Third_Party/FatFs/src/diskio.c \
../chip_headers/Middlewares/Third_Party/FatFs/src/ff.c \
../chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c 

OBJS += \
./chip_headers/Middlewares/Third_Party/FatFs/src/diskio.o \
./chip_headers/Middlewares/Third_Party/FatFs/src/ff.o \
./chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.o 

C_DEPS += \
./chip_headers/Middlewares/Third_Party/FatFs/src/diskio.d \
./chip_headers/Middlewares/Third_Party/FatFs/src/ff.d \
./chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
chip_headers/Middlewares/Third_Party/FatFs/src/%.o chip_headers/Middlewares/Third_Party/FatFs/src/%.su chip_headers/Middlewares/Third_Party/FatFs/src/%.cyclo: ../chip_headers/Middlewares/Third_Party/FatFs/src/%.c chip_headers/Middlewares/Third_Party/FatFs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DARM_MATH_CM4 -DSTM32F407xx -c -I../Inc -I"D:/PROJECTS/Git/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_headers/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/PROJECTS/Git/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_headers/Drivers/CMSIS/Include" -I"D:/PROJECTS/Git/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_headers/Drivers/CMSIS/DSP/Include" -I"D:/PROJECTS/Git/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_headers/Middlewares/Third_Party/FatFs/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-chip_headers-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src

clean-chip_headers-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src:
	-$(RM) ./chip_headers/Middlewares/Third_Party/FatFs/src/diskio.cyclo ./chip_headers/Middlewares/Third_Party/FatFs/src/diskio.d ./chip_headers/Middlewares/Third_Party/FatFs/src/diskio.o ./chip_headers/Middlewares/Third_Party/FatFs/src/diskio.su ./chip_headers/Middlewares/Third_Party/FatFs/src/ff.cyclo ./chip_headers/Middlewares/Third_Party/FatFs/src/ff.d ./chip_headers/Middlewares/Third_Party/FatFs/src/ff.o ./chip_headers/Middlewares/Third_Party/FatFs/src/ff.su ./chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.cyclo ./chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.d ./chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.o ./chip_headers/Middlewares/Third_Party/FatFs/src/ff_gen_drv.su

.PHONY: clean-chip_headers-2f-Middlewares-2f-Third_Party-2f-FatFs-2f-src


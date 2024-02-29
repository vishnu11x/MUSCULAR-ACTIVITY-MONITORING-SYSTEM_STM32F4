################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/clock.c \
../Src/delayms.c \
../Src/main.c \
../Src/sdcard_spi.c \
../Src/signal_pros.c \
../Src/switch.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart2.c 

OBJS += \
./Src/adc.o \
./Src/clock.o \
./Src/delayms.o \
./Src/main.o \
./Src/sdcard_spi.o \
./Src/signal_pros.o \
./Src/switch.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart2.o 

C_DEPS += \
./Src/adc.d \
./Src/clock.d \
./Src/delayms.d \
./Src/main.d \
./Src/sdcard_spi.d \
./Src/signal_pros.d \
./Src/switch.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart2.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DARM_MATH_CM4 -c -I../Inc -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/DSP/Include" -I"D:/Project/MUSCULAR ACTIVITY MONITORING SYSTEM/MUSCULAR-ACTIVITY-MONITORING-SYSTEM_STM32F4/STM32F407/MAIN/chip_header/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc.cyclo ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/clock.cyclo ./Src/clock.d ./Src/clock.o ./Src/clock.su ./Src/delayms.cyclo ./Src/delayms.d ./Src/delayms.o ./Src/delayms.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/sdcard_spi.cyclo ./Src/sdcard_spi.d ./Src/sdcard_spi.o ./Src/sdcard_spi.su ./Src/signal_pros.cyclo ./Src/signal_pros.d ./Src/signal_pros.o ./Src/signal_pros.su ./Src/switch.cyclo ./Src/switch.d ./Src/switch.o ./Src/switch.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart2.cyclo ./Src/uart2.d ./Src/uart2.o ./Src/uart2.su

.PHONY: clean-Src


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/boot_multicore_slave.c \
../startup/startup_lpc55s69_cm33_core0.c 

C_DEPS += \
./startup/boot_multicore_slave.d \
./startup/startup_lpc55s69_cm33_core0.d 

OBJS += \
./startup/boot_multicore_slave.o \
./startup/startup_lpc55s69_cm33_core0.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DMBEDTLS_CONFIG_FILE='"ksdk_mbedtls_config.h"' -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\component\serial_manager" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\mbedtls\include" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\mbedtls\library" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\mbedtls\port\ksdk" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\board" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\source" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_hello_world_symmetric_algorithms\board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/boot_multicore_slave.d ./startup/boot_multicore_slave.o ./startup/startup_lpc55s69_cm33_core0.d ./startup/startup_lpc55s69_cm33_core0.o

.PHONY: clean-startup


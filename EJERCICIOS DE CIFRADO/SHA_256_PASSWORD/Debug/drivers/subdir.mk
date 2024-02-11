################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_casper.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_flexcomm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_hashcrypt.c \
../drivers/fsl_i2c.c \
../drivers/fsl_power.c \
../drivers/fsl_reset.c \
../drivers/fsl_rng.c \
../drivers/fsl_usart.c 

C_DEPS += \
./drivers/fsl_casper.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_flexcomm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_hashcrypt.d \
./drivers/fsl_i2c.d \
./drivers/fsl_power.d \
./drivers/fsl_reset.d \
./drivers/fsl_rng.d \
./drivers/fsl_usart.d 

OBJS += \
./drivers/fsl_casper.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_flexcomm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_hashcrypt.o \
./drivers/fsl_i2c.o \
./drivers/fsl_power.o \
./drivers/fsl_reset.o \
./drivers/fsl_rng.o \
./drivers/fsl_usart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DMBEDTLS_FREESCALE_HASHCRYPT_SHA1 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DMBEDTLS_CONFIG_FILE='"ksdk_mbedtls_config.h"' -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\serial_manager" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\mbedtls\include" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\mbedtls\library" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\mbedtls\port\ksdk" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\board" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\source" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_casper.d ./drivers/fsl_casper.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_flexcomm.d ./drivers/fsl_flexcomm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_hashcrypt.d ./drivers/fsl_hashcrypt.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_power.d ./drivers/fsl_power.o ./drivers/fsl_reset.d ./drivers/fsl_reset.o ./drivers/fsl_rng.d ./drivers/fsl_rng.o ./drivers/fsl_usart.d ./drivers/fsl_usart.o

.PHONY: clean-drivers


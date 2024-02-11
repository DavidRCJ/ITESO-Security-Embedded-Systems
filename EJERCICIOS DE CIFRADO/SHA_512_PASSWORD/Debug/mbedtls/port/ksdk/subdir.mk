################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mbedtls/port/ksdk/aes_alt.c \
../mbedtls/port/ksdk/des_alt.c \
../mbedtls/port/ksdk/ecp_alt.c \
../mbedtls/port/ksdk/ecp_alt_ksdk.c \
../mbedtls/port/ksdk/ecp_curves_alt.c \
../mbedtls/port/ksdk/ksdk_mbedtls.c 

C_DEPS += \
./mbedtls/port/ksdk/aes_alt.d \
./mbedtls/port/ksdk/des_alt.d \
./mbedtls/port/ksdk/ecp_alt.d \
./mbedtls/port/ksdk/ecp_alt_ksdk.d \
./mbedtls/port/ksdk/ecp_curves_alt.d \
./mbedtls/port/ksdk/ksdk_mbedtls.d 

OBJS += \
./mbedtls/port/ksdk/aes_alt.o \
./mbedtls/port/ksdk/des_alt.o \
./mbedtls/port/ksdk/ecp_alt.o \
./mbedtls/port/ksdk/ecp_alt_ksdk.o \
./mbedtls/port/ksdk/ecp_curves_alt.o \
./mbedtls/port/ksdk/ksdk_mbedtls.o 


# Each subdirectory must supply rules for building sources it contributes
mbedtls/port/ksdk/%.o: ../mbedtls/port/ksdk/%.c mbedtls/port/ksdk/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DMBEDTLS_FREESCALE_HASHCRYPT_SHA1 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DMBEDTLS_CONFIG_FILE='"ksdk_mbedtls_config.h"' -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\component\serial_manager" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\mbedtls\include" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\mbedtls\library" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\mbedtls\port\ksdk" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\board" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\source" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_512_PASSWORD\board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-mbedtls-2f-port-2f-ksdk

clean-mbedtls-2f-port-2f-ksdk:
	-$(RM) ./mbedtls/port/ksdk/aes_alt.d ./mbedtls/port/ksdk/aes_alt.o ./mbedtls/port/ksdk/des_alt.d ./mbedtls/port/ksdk/des_alt.o ./mbedtls/port/ksdk/ecp_alt.d ./mbedtls/port/ksdk/ecp_alt.o ./mbedtls/port/ksdk/ecp_alt_ksdk.d ./mbedtls/port/ksdk/ecp_alt_ksdk.o ./mbedtls/port/ksdk/ecp_curves_alt.d ./mbedtls/port/ksdk/ecp_curves_alt.o ./mbedtls/port/ksdk/ksdk_mbedtls.d ./mbedtls/port/ksdk/ksdk_mbedtls.o

.PHONY: clean-mbedtls-2f-port-2f-ksdk


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/fsl_adapter_usart.c 

C_DEPS += \
./component/uart/fsl_adapter_usart.d 

OBJS += \
./component/uart/fsl_adapter_usart.o 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c component/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DMBEDTLS_FREESCALE_HASHCRYPT_SHA1 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DMBEDTLS_CONFIG_FILE='"ksdk_mbedtls_config.h"' -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\serial_manager" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\mbedtls\include" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\mbedtls\library" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\mbedtls\port\ksdk" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\board" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\source" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\SHA_256_PASSWORD\board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-uart

clean-component-2f-uart:
	-$(RM) ./component/uart/fsl_adapter_usart.d ./component/uart/fsl_adapter_usart.o

.PHONY: clean-component-2f-uart


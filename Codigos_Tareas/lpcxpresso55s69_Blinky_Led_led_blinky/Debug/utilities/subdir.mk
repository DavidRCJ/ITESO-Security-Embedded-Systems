################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_assert.c \
../utilities/fsl_debug_console.c \
../utilities/fsl_str.c 

S_UPPER_SRCS += \
../utilities/fsl_memcpy.S 

C_DEPS += \
./utilities/fsl_assert.d \
./utilities/fsl_debug_console.d \
./utilities/fsl_str.d 

OBJS += \
./utilities/fsl_assert.o \
./utilities/fsl_debug_console.o \
./utilities/fsl_memcpy.o \
./utilities/fsl_str.o 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c utilities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\source" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\utilities" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\drivers" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\device" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\startup" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\component\uart" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\component\lists" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\CMSIS" -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\board" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

utilities/%.o: ../utilities/%.S utilities/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"C:\Users\UIF87839\Documents\MCUXpressoIDE_11.8.1_1197\workspace\lpcxpresso55s69_Blinky_Led_led_blinky\source" -g3 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-utilities

clean-utilities:
	-$(RM) ./utilities/fsl_assert.d ./utilities/fsl_assert.o ./utilities/fsl_debug_console.d ./utilities/fsl_debug_console.o ./utilities/fsl_memcpy.o ./utilities/fsl_str.d ./utilities/fsl_str.o

.PHONY: clean-utilities

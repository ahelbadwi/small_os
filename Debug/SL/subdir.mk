################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SL/Sos.c \
../SL/Sos_Cfg.c \
../SL/Sos_Lcfg.c 

OBJS += \
./SL/Sos.o \
./SL/Sos_Cfg.o \
./SL/Sos_Lcfg.o 

C_DEPS += \
./SL/Sos.d \
./SL/Sos_Cfg.d \
./SL/Sos_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
SL/%.o: ../SL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Sprints\Software Design\Challenges\Sos\Commons" -I"D:\Sprints\Software Design\Challenges\Sos\McAl" -I"D:\Sprints\Software Design\Challenges\Sos\SL" -I"D:\Sprints\Software Design\Challenges\Sos\App" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../McAl/DIO.c \
../McAl/Timer.c \
../McAl/sleep.c 

OBJS += \
./McAl/DIO.o \
./McAl/Timer.o \
./McAl/sleep.o 

C_DEPS += \
./McAl/DIO.d \
./McAl/Timer.d \
./McAl/sleep.d 


# Each subdirectory must supply rules for building sources it contributes
McAl/%.o: ../McAl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Sprints\Software Design\Challenges\Sos\Commons" -I"D:\Sprints\Software Design\Challenges\Sos\McAl" -I"D:\Sprints\Software Design\Challenges\Sos\SL" -I"D:\Sprints\Software Design\Challenges\Sos\App" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



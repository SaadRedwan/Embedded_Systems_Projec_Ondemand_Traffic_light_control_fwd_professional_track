################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER0/Src/Timer0.c 

OBJS += \
./MCAL/TIMER0/Src/Timer0.o 

C_DEPS += \
./MCAL/TIMER0/Src/Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER0/Src/%.o: ../MCAL/TIMER0/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\DIO\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\HAL\LED\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\LIB" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\EXT_INT\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\GLBL_INTERPT\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\TIMER0\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



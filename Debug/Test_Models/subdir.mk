################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Test_Models/DIO_Test_Model.c \
../Test_Models/ExtInt_and_GlobalInt_Test_Model.c \
../Test_Models/Led_Test_Model.c \
../Test_Models/Timer1_Test_Model.c 

OBJS += \
./Test_Models/DIO_Test_Model.o \
./Test_Models/ExtInt_and_GlobalInt_Test_Model.o \
./Test_Models/Led_Test_Model.o \
./Test_Models/Timer1_Test_Model.o 

C_DEPS += \
./Test_Models/DIO_Test_Model.d \
./Test_Models/ExtInt_and_GlobalInt_Test_Model.d \
./Test_Models/Led_Test_Model.d \
./Test_Models/Timer1_Test_Model.d 


# Each subdirectory must supply rules for building sources it contributes
Test_Models/%.o: ../Test_Models/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\DIO\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\APP" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\TIMER1\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\HAL\LED\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\LIB" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\EXT_INT\Inc" -I"C:\Users\sreda\eclipse-workspace\On_demand_Traffic_Light_Control_Project\MCAL\GLBL_INTERPT\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



/********************************
 * File  	:  DIO_Test_Model.c
 * Date	 	:  Oct 01, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/


#include <avr/io.h>
#include <util/delay.h>
#include "Dio_Interface.h"

#define TIME_DELAY 1000
//
//int main(void)
//{
//	/*Test api Dio_ConfigChannel*/
//	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL3,OUTPUT);
//	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL4,OUTPUT);
//	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL5,OUTPUT);
//
//
//	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL1,OUTPUT);
//	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL2,OUTPUT);
//	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL3,OUTPUT);
//
//
//	while(1)
//	{
//		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL3,STD_HIGH);
//		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL4,STD_HIGH);
//		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL5,STD_HIGH);
//
//		_delay_ms(TIME_DELAY);
//
//		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL3,STD_LOW);
//		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL4,STD_LOW);
//		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL5,STD_LOW);
//
//		_delay_ms(TIME_DELAY);
//
//		Dio_FlipChannel(DIO_PORTC,DIO_CHANNEL1);
//		Dio_FlipChannel(DIO_PORTC,DIO_CHANNEL2);
//		Dio_FlipChannel(DIO_PORTC,DIO_CHANNEL3);
//
//
//		_delay_ms(TIME_DELAY);
//
//	}
//
//}

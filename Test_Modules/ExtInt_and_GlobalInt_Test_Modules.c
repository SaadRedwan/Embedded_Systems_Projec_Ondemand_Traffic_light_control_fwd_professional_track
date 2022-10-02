/********************************
 * File  	:  ExtInt_and_GlobalInt_Test_Model.c
 * Date	 	:  Oct 01, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Dio_Interface.h"
#include "ExtInt_Interface.h"
#include "GlblInterrupt_Interface.h"



#define TIME_DISABLE    5000
//
//
//ISR(INT0_vect)
//{
//	Dio_FlipChannel(DIO_PORTA,DIO_CHANNEL0);
//}
//
//int main(void)
//{
//	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL0,OUTPUT);
//
//
//
//	ExtInt_SnsCtrlSet(EXT_INT0,FAILING_EDGE_MODE);
////	ExtInt_SnsCtrlSet(EXT_INT0,RISING_EDGE_MODE);
//	ExtInt_Enable(EXT_INT0);
//	EnableAllInterrupts();
//
//
//	while(1)
//	{
//		_delay_ms(TIME_DISABLE);
//		DisableAllInterrupts();
//	}
//}
//
//

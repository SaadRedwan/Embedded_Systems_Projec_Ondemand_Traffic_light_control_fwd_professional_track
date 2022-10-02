/********************************
 * File  	:  Led_Test_Model.c
 * Date	 	:  Oct 01, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include <avr/io.h>
#include <util/delay.h>
#include "Led_Interface.h"

#define TIME_DELAY 500

//int main(void)
//{
//	Led_Init();
//
//	Led_OFF(CAR_GREEN_LED);
//	Led_OFF(CAR_YELLOW_LED);
//	Led_OFF(CAR_RED_LED);
//
//	Led_OFF(PEDESTRIANS_GREEN_LED);
//	Led_OFF(PEDESTRIANS_YELLOW_LED);
//	Led_OFF(PEDESTRIANS_RED_LED);
//
//
//	while(1)
//	{
//		Led_Toggle(CAR_GREEN_LED);
//		_delay_ms(TIME_DELAY);
//		Led_Toggle(CAR_YELLOW_LED);
//		_delay_ms(TIME_DELAY);
//		Led_Toggle(CAR_RED_LED);
//		_delay_ms(TIME_DELAY);
//		Led_Toggle(PEDESTRIANS_GREEN_LED);
//		_delay_ms(TIME_DELAY);
//		Led_Toggle(PEDESTRIANS_YELLOW_LED);
//		_delay_ms(TIME_DELAY);
//		Led_Toggle(PEDESTRIANS_RED_LED);
//		_delay_ms(TIME_DELAY);
//	}
//
//}

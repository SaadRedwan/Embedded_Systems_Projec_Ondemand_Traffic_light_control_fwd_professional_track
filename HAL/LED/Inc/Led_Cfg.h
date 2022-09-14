/************************************
 * Led_Cfg.h
 *
 *  Created on: Apr 30, 2021
 *  Author: Eng_Fawzi
 ************************************/

#ifndef HAL_LED_INC_LED_CFG_H_
#define HAL_LED_INC_LED_CFG_H_

/*	LEDs HW Channels Mapping	*/
#define CAR_PORT		                  DIO_PORTA
#define CAR_GREEN_CHANNEL	              DIO_CHANNEL0
#define CAR_YELLOW_CHANNEL	              DIO_CHANNEL1
#define CAR_RED_CHANNEL	                  DIO_CHANNEL2

#define PEDESTRIANS_PORT            	  DIO_PORTB
#define PEDESTRIANS_GREEN_CHANNEL	      DIO_CHANNEL0
#define PEDESTRIANS_YELLOW_CHANNEL	      DIO_CHANNEL1
#define PEDESTRIANS_RED_CHANNEL	          DIO_CHANNEL2

/*	LEDs HW Connection	*/

//
//#define LED0_CONNECTION	FORWARD
//#define LED1_CONNECTION	FORWARD
//#define LED2_CONNECTION	FORWARD
#endif /* HAL_LED_INC_LED_CFG_H_ */

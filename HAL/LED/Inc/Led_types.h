/*
 * Led_types.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Eng_Fawzi
 */

#ifndef HAL_LED_INC_LED_TYPES_H_
#define HAL_LED_INC_LED_TYPES_H_

typedef enum {
	CAR_GREEN_LED,
	CAR_YELLOW_LED,
	CAR_RED_LED,
	PEDESTRIANS_GREEN_LED,
	PEDESTRIANS_YELLOW_LED,
	PEDESTRIANS_RED_LED,
}Led_ID;

typedef enum
 {
 	LED_FAIL,
	LED_SUCCESS
 }ledErrorState;

#endif /* HAL_LED_INC_LED_TYPES_H_ */

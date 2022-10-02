/*********************************
 * Led.c
 *
 *  Created on: Apr 30, 2021
 *  Author: Eng_Fawzi
 **********************************/

#include "Led_Interface.h"


/******************************************************************************
* \Syntax          : ledErrorState Led_Init(void)
* \Description     : This function configure the pins of leds of the system
*******************************************************************************/

ledErrorState Led_Init(void)
{
	Dio_ConfigChannel(CAR_PORT, CAR_GREEN_CHANNEL, OUTPUT);
	Dio_ConfigChannel(CAR_PORT, CAR_YELLOW_CHANNEL, OUTPUT);
	Dio_ConfigChannel(CAR_PORT, CAR_RED_CHANNEL, OUTPUT);

	Dio_ConfigChannel(PEDESTRIANS_PORT, PEDESTRIANS_GREEN_CHANNEL, OUTPUT);
	Dio_ConfigChannel(PEDESTRIANS_PORT, PEDESTRIANS_YELLOW_CHANNEL, OUTPUT);
	Dio_ConfigChannel(PEDESTRIANS_PORT, PEDESTRIANS_RED_CHANNEL, OUTPUT);
	return LED_SUCCESS;
}

/******************************************************************************
* \Syntax          : ledErrorState Led_ON(void)
* \Description     : This function put the led in ON state
*******************************************************************************/

ledErrorState Led_ON(Led_ID led)
{
	switch (led)
	{
	case CAR_GREEN_LED:
		Dio_WriteChannel(CAR_PORT,CAR_GREEN_CHANNEL,STD_HIGH);
		break;
	case CAR_YELLOW_LED:
		Dio_WriteChannel(CAR_PORT,CAR_YELLOW_CHANNEL,STD_HIGH);
		break;
	case CAR_RED_LED:
		Dio_WriteChannel(CAR_PORT,CAR_RED_CHANNEL,STD_HIGH);
		break;
	case PEDESTRIANS_GREEN_LED:
		Dio_WriteChannel(PEDESTRIANS_PORT,PEDESTRIANS_GREEN_CHANNEL,STD_HIGH);
		break;
	case PEDESTRIANS_YELLOW_LED:
		Dio_WriteChannel(PEDESTRIANS_PORT,PEDESTRIANS_YELLOW_CHANNEL,STD_HIGH);
		break;
	case PEDESTRIANS_RED_LED:
		Dio_WriteChannel(PEDESTRIANS_PORT,PEDESTRIANS_RED_CHANNEL,STD_HIGH);
		break;
	}
	return LED_SUCCESS;
}

/******************************************************************************
* \Syntax          : ledErrorState Led_OFF(void)
* \Description     : This function put the led in OFF state
*******************************************************************************/

ledErrorState Led_OFF(Led_ID led)
{
	switch (led)
	{
	case CAR_GREEN_LED:
		Dio_WriteChannel(CAR_PORT,CAR_GREEN_CHANNEL,STD_LOW);
		break;
	case CAR_YELLOW_LED:
		Dio_WriteChannel(CAR_PORT,CAR_YELLOW_CHANNEL,STD_LOW);
		break;
	case CAR_RED_LED:
		Dio_WriteChannel(CAR_PORT,CAR_RED_CHANNEL,STD_LOW);
		break;
	case PEDESTRIANS_GREEN_LED:
		Dio_WriteChannel(PEDESTRIANS_PORT,PEDESTRIANS_GREEN_CHANNEL,STD_LOW);
		break;
	case PEDESTRIANS_YELLOW_LED:
		Dio_WriteChannel(PEDESTRIANS_PORT,PEDESTRIANS_YELLOW_CHANNEL,STD_LOW);
		break;
	case PEDESTRIANS_RED_LED:
		Dio_WriteChannel(PEDESTRIANS_PORT,PEDESTRIANS_RED_CHANNEL,STD_LOW);
		break;
	}
	return LED_SUCCESS;
}

/******************************************************************************
* \Syntax          : ledErrorState Led_Toggle(void)
* \Description     : This function toggle the current led state
*******************************************************************************/

ledErrorState Led_Toggle(Led_ID led)
{
	switch (led)
	{
	case CAR_GREEN_LED:
		Dio_FlipChannel(CAR_PORT,CAR_GREEN_CHANNEL);
		break;
	case CAR_YELLOW_LED:
		Dio_FlipChannel(CAR_PORT,CAR_YELLOW_CHANNEL);
		break;
	case CAR_RED_LED:
		Dio_FlipChannel(CAR_PORT,CAR_RED_CHANNEL);
		break;
	case PEDESTRIANS_GREEN_LED:
		Dio_FlipChannel(PEDESTRIANS_PORT,PEDESTRIANS_GREEN_CHANNEL);
		break;
	case PEDESTRIANS_YELLOW_LED:
		Dio_FlipChannel(PEDESTRIANS_PORT,PEDESTRIANS_YELLOW_CHANNEL);
		break;
	case PEDESTRIANS_RED_LED:
		Dio_FlipChannel(PEDESTRIANS_PORT,PEDESTRIANS_RED_CHANNEL);
		break;
	}
	return LED_SUCCESS;
}

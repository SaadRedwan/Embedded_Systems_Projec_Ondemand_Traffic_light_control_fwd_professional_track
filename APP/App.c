/********************************
 * File  	:  main.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/


#include "App.h"



#define TIMER1_500ms_PRELOAD       TIMER1_TOP-7813
#define NUMBER_OF_OVERFLOW_FOR_5S  10

#define EXIT_PEDESTRIANS           0
#define ENTER_PEDESTRIANS          1



volatile running_mode_state Current_Mode=NORMAL_MODE;
//volatile running_mode_state Previous_Mode=NORMAL_MODE;
volatile running_led_state current_car_led_state =GREEN;
volatile running_led_state previous_car_led_state =YELLOW;

volatile running_led_state current_peds_led_state =RED;
volatile running_led_state previous_peds_led_state =YELLOW;
volatile running_led_state previous_peds_led_state2 =YELLOW;

volatile u8 count_Overflow_5s=1;
volatile u8 INT0_Pressed =0;
volatile u8 Entry_State=EXIT_PEDESTRIANS;

ISR(TIMER1_OVF_vect)
{
	DisableAllInterrupts();
	Dio_FlipChannel(DIO_PORTC,DIO_CHANNEL0);

	if(Current_Mode==NORMAL_MODE)
	{
		if(current_car_led_state==YELLOW)
		{
			Led_Toggle(CAR_YELLOW_LED);
		}

		if(count_Overflow_5s==NUMBER_OF_OVERFLOW_FOR_5S)
		{
			if(current_car_led_state==GREEN && previous_car_led_state==YELLOW)
			{
				previous_car_led_state =GREEN;
				current_car_led_state=YELLOW;
			}
			else if(current_car_led_state==YELLOW)
			{
				if(previous_car_led_state==GREEN)
				{
					current_car_led_state=RED;
				}
				else if(previous_car_led_state==RED)
				{
					current_car_led_state=GREEN;
				}
				previous_car_led_state =YELLOW;
			}
			else if(current_car_led_state==RED && previous_car_led_state==YELLOW)
			{
				previous_car_led_state=RED;
				current_car_led_state=YELLOW;
			}
			count_Overflow_5s=0;
		}
	}
	else if(Current_Mode==PEDESTRIANS_MODE)
	{
		if(current_peds_led_state==YELLOW)
		{
			Led_Toggle(CAR_YELLOW_LED);
			Led_Toggle(PEDESTRIANS_YELLOW_LED);
			Dio_FlipChannel(DIO_PORTC,DIO_CHANNEL2);
		}
		if(count_Overflow_5s==NUMBER_OF_OVERFLOW_FOR_5S)
		{
			if(current_peds_led_state==YELLOW && previous_car_led_state==RED && previous_peds_led_state==GREEN)
			{
				previous_peds_led_state=YELLOW;
				previous_peds_led_state2=GREEN;
				previous_car_led_state=YELLOW;
				current_car_led_state=GREEN;
				current_peds_led_state=RED;
			}
			else if(current_peds_led_state==GREEN)
			{
				previous_peds_led_state=GREEN;
				previous_car_led_state=RED;

				current_car_led_state=YELLOW;
				current_peds_led_state=YELLOW;
			}

			else if(current_peds_led_state==YELLOW)
			{
				current_peds_led_state=GREEN;
			}
			else if(current_peds_led_state==RED)
			{
				current_peds_led_state=YELLOW;
			}

			count_Overflow_5s=0;
		}
	}

	count_Overflow_5s++;
	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
	EnableAllInterrupts();
}

ISR(INT0_vect)
{
	DisableAllInterrupts();
	if(current_car_led_state==RED && current_peds_led_state!=GREEN && INT0_Pressed==0)
	{

		current_peds_led_state=GREEN;

		Current_Mode=PEDESTRIANS_MODE;
		Entry_State=ENTER_PEDESTRIANS;

		TIMER1_Stop();
		TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
		TIMER1_Start(TIMER1_CS_1024_PRESCALER);
	}
	else if((current_car_led_state==YELLOW || current_car_led_state==GREEN) && INT0_Pressed==0)
	{
		current_peds_led_state=RED;
		Current_Mode=PEDESTRIANS_MODE;
		Entry_State=ENTER_PEDESTRIANS;
	}
		INT0_Pressed=1;
	EnableAllInterrupts();
}

modeRunningErrorState Normal_Mode(void)
{
	if(Current_Mode==NORMAL_MODE)
	{
		if(current_car_led_state==GREEN)
		{
			Led_OFF(CAR_YELLOW_LED);
			Led_ON(CAR_GREEN_LED);
		}
		else if(current_car_led_state==YELLOW)
		{
			Led_OFF(CAR_GREEN_LED);
			Led_OFF(CAR_RED_LED);
		}
		else if(current_car_led_state==RED)
		{
			Led_OFF(CAR_YELLOW_LED);
			Led_ON(CAR_RED_LED);
		}
	}
	return MODE_SUCCESS;
}

modeRunningErrorState Pedestrian_Mode(void)
{
	if(Current_Mode==PEDESTRIANS_MODE)
	{
		if(previous_peds_led_state==YELLOW &&
				previous_peds_led_state2==GREEN &&
				previous_car_led_state==YELLOW &&
				current_car_led_state==GREEN &&
				current_peds_led_state==RED && Entry_State==ENTER_PEDESTRIANS)
		{
			Led_OFF(PEDESTRIANS_YELLOW_LED);
			Led_OFF(CAR_YELLOW_LED);
			Led_OFF(PEDESTRIANS_GREEN_LED);

			Led_ON(PEDESTRIANS_RED_LED);
			Led_ON(CAR_GREEN_LED);

			INT0_Pressed=0;
		}
		else if(previous_peds_led_state==YELLOW &&
				previous_peds_led_state2==GREEN &&
				previous_car_led_state==YELLOW &&
				current_car_led_state==GREEN &&
				current_peds_led_state==RED&& Entry_State==EXIT_PEDESTRIANS)
		{
			Led_OFF(PEDESTRIANS_YELLOW_LED);
			Led_OFF(CAR_YELLOW_LED);
			Led_OFF(PEDESTRIANS_GREEN_LED);

			Led_ON(PEDESTRIANS_RED_LED);
			Led_ON(CAR_GREEN_LED);

			Current_Mode=NORMAL_MODE;
			INT0_Pressed=0;
		}
		else if(current_peds_led_state==GREEN )
		{
			Led_OFF(CAR_YELLOW_LED);
			Led_OFF(PEDESTRIANS_YELLOW_LED);
			Led_OFF(PEDESTRIANS_RED_LED);

			Led_ON(CAR_RED_LED);
			Led_ON(PEDESTRIANS_GREEN_LED);
		}
		else if(current_peds_led_state==YELLOW)
		{
			Led_OFF(CAR_RED_LED);
			Led_OFF(CAR_GREEN_LED);

			Led_OFF(PEDESTRIANS_RED_LED);
			Entry_State=EXIT_PEDESTRIANS;
		}
		else if(current_peds_led_state==RED)
		{
			Led_OFF(PEDESTRIANS_GREEN_LED);
			Led_OFF(PEDESTRIANS_YELLOW_LED);

			Led_ON(PEDESTRIANS_RED_LED);
		}
	}
	return MODE_SUCCESS;
}


appErrorState App_Start(void)
{
	Led_Init();
	TIMER1_Init();

	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL0,OUTPUT);
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL1,OUTPUT);
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL2,OUTPUT);

	ExtInt_SnsCtrlSet(EXT_INT0,RISING_EDGE_MODE);
	ExtInt_Enable(EXT_INT0);

	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
	TIMER1_EnableInterrupt();
	EnableAllInterrupts();

	/*Start the App*/
	TIMER1_Start(TIMER1_CS_1024_PRESCALER);

	return APP_SUCCESS;
}

appErrorState App_Running(void)
{
	Normal_Mode();

	Pedestrian_Mode();

	return APP_SUCCESS;
}

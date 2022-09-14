/********************************
 * File  	:  main.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/


#include "App.h"



#define TIMER1_500ms_PRELOAD       65535-7813
#define NUMBER_OF_OVERFLOW_FOR_5S  10

volatile running_mode_state Current_Mode=NORMAL_MODE;
volatile running_led_state current_car_led_state =GREEN;
volatile running_led_state previous_car_led_state =YELLOW;

volatile running_led_state current_peds_led_state =RED;
volatile running_led_state previous_peds_led_state =YELLOW;
volatile u8 count_Overflow_5s=1;


ISR(TIMER1_OVF_vect)
{
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
			else if(current_car_led_state==YELLOW && (previous_car_led_state==GREEN || previous_car_led_state==RED))
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
		if(current_car_led_state==YELLOW)
		{
			Led_Toggle(CAR_YELLOW_LED);
			Led_Toggle(PEDESTRIANS_YELLOW_LED);
		}
		if(count_Overflow_5s==NUMBER_OF_OVERFLOW_FOR_5S)
		{
			if(current_peds_led_state==GREEN && previous_peds_led_state==YELLOW)
			{
				previous_peds_led_state =GREEN;
				current_peds_led_state=YELLOW;
			}
			else if(current_peds_led_state==YELLOW && previous_peds_led_state==RED)
			{
				previous_peds_led_state=YELLOW;
				current_peds_led_state=GREEN;
				count_Overflow_5s=0;
			}
		}
	}



	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
	count_Overflow_5s++;
}

ISR(INT0_vect)
{
	DisableAllInterrupts();
	Current_Mode=PEDESTRIANS_MODE;
	if(current_car_led_state==RED)
	{
		current_peds_led_state=GREEN;
	}
	else if(current_car_led_state==GREEN || current_car_led_state==YELLOW)
	{
		current_peds_led_state=RED;
	}
	else if()
	{

	}
	EnableAllInterrupts();
}


void Normal_Mode(void)
{
	while(Current_Mode==NORMAL_MODE)
	{
		if(current_car_led_state==GREEN && Current_Mode==NORMAL_MODE)
		{
			TIMER1_Start(TIMER1_CS_1024_PRESCALER);
			Led_OFF(CAR_YELLOW_LED);
			Led_ON(CAR_GREEN_LED);
		}
		else if(current_car_led_state==YELLOW && Current_Mode==NORMAL_MODE)
		{
			Led_OFF(CAR_GREEN_LED);
			Led_OFF(CAR_RED_LED);
		}
		else if(current_car_led_state==RED && Current_Mode==NORMAL_MODE)
		{
			Led_OFF(CAR_YELLOW_LED);
			Led_ON(CAR_RED_LED);
		}
		else
		{
			Led_OFF(CAR_GREEN_LED);
			Led_OFF(CAR_YELLOW_LED);
			Led_OFF(CAR_RED_LED);
		}
	}
}

void Pedestrian_Mode(void)
{
	while(Current_Mode==PEDESTRIANS_MODE)
	{
		if(current_peds_led_state==GREEN)
		{
			TIMER1_Stop();
			TIMER1_Start(TIMER1_CS_1024_PRESCALER);
			Led_OFF(CAR_YELLOW_LED);
			Led_OFF(CAR_GREEN_LED);
			Led_ON(CAR_RED_LED);
			Led_ON(PEDESTRIANS_GREEN_LED);
		}
		else if(current_peds_led_state==RED)
		{
			Led_ON(PEDESTRIANS_RED_LED);

			previous_peds_led_state=RED;
			current_peds_led_state=YELLOW;
		}
		else if(current_peds_led_state==GREEN && previous_peds_led_state==RED)
		{
			Led_OFF(CAR_RED_LED);

			Led_OFF(PEDESTRIANS_RED_LED);
			Led_OFF(PEDESTRIANS_GREEN_LED);
		}
		else if(current_peds_led_state==GREEN && previous_peds_led_state==YELLOW)
		{
			Led_OFF(CAR_YELLOW_LED);
			Led_OFF(CAR_GREEN_LED);
			Led_ON(CAR_RED_LED);

			Led_ON(PEDESTRIANS_GREEN_LED);
		}
	}
}


void App_Init(void)
{
	Led_Init();
	TIMER1_Init();

	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);

	ExtInt_SnsCtrlSet(EXT_INT0,LOW_LEVEL_MODE);
	ExtInt_Enable(EXT_INT0);
	TIMER1_EnableInterrupt();
	EnableAllInterrupts();
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL0,OUTPUT);
	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL3,OUTPUT);
}

void App_start(void)
{
	Normal_Mode();
	Pedestrian_Mode();
}

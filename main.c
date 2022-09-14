/********************************
 * File  	:  main.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include "App.h"

//ISR(INT0_vect)
//{
//	DisableAllInterrupts();
//	Led_Toggle(CAR_GREEN_LED);
//	EnableAllInterrupts();
//}


int main(void)
{
		App_Init();

		App_start();
//	Led_Init();
//
//	ExtInt_SnsCtrlSet(EXT_INT0,LOW_LEVEL_MODE);
//	ExtInt_Enable(EXT_INT0);
//	EnableAllInterrupts();

	while(1)
	{
		;
	}

	return 0;
}


/********************************
 * File  	:  Timer1.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/
#include "Timer1.h"



void TIMER1_Init(void)
{
//	#if (TIMER_OPERATION_MODE == TIMER1_MODE_INTERVAL)
		TIMER1_TCCR1A_REG|= TIMER1_INTERVAL_MODE_WGM10 | TIMER1_INTERVAL_MODE_WGM11;
		TIMER1_TCCR1B_REG|= TIMER1_INTERVAL_MODE_WGM12 | TIMER1_INTERVAL_MODE_WGM13;
//	#else
//	#error "You Shall Define Timer Operation Mode In Timer1_Cfg.h"
//	#endif
}

void TIMER1_Start(u8 prescaler)
{
	TIMER1_TCCR1B_REG|=prescaler;
}
void TIMER1_Stop(void)
{
	TIMER1_TCCR1B_REG &=~(0x07);
}
void TIMER1_SetPreload(u16 preLoadValue)
{
	TIMER1_TCNT1_REG = preLoadValue;
}
void TIMER1_EnableInterrupt(void)
{
	#if (TIMER1_OPERATION_MODE == TIMER1_MODE_INTERVAL)
	SET_BIT(TIMER1_TIMSK_REG,TIMER1_INTERVAL_INT_ENABLE_BIT_NO);
	#endif
}
void TIMER1_DisableInterrupt(void)
{
	#if (TIMER1_OPERATION_MODE == TIMER1_MODE_INTERVAL)
	CLEAR_BIT(TIMER1_TIMSK_REG,TIMER1_INTERVAL_INT_ENABLE_BIT_NO);
	#endif
}



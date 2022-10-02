/********************************
 * File  	:  Timer1.c'
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include <Timer1_Interface.h>


/******************************************************************************
* \Syntax          : timer1ErrorState TIMER1_Init(void)
* \Description     : This function initiate the timer1 with the normal mode
*******************************************************************************/

timer1ErrorState TIMER1_Init(void)
{
		TIMER1_TCCR1A_REG|= TIMER1_INTERVAL_MODE_WGM10 | TIMER1_INTERVAL_MODE_WGM11;
		TIMER1_TCCR1B_REG|= TIMER1_INTERVAL_MODE_WGM12 | TIMER1_INTERVAL_MODE_WGM13;
		return TIMER1_SUCCESS;
}

/******************************************************************************
* \Syntax          : timer1ErrorState TIMER1_Start(void)
* \Description     : This function trigger the start of timer1 with a defined prescaler
*******************************************************************************/

timer1ErrorState TIMER1_Start(u8 prescaler)
{
	TIMER1_TCCR1B_REG|=prescaler;
	return TIMER1_SUCCESS;
}

/******************************************************************************
* \Syntax          : timer1ErrorState TIMER1_Stop(void)
* \Description     : This function stop the timer1 by put prescaler as zero
*******************************************************************************/

timer1ErrorState TIMER1_Stop(void)
{
	TIMER1_TCCR1B_REG &=~(0x07);
	return TIMER1_SUCCESS;
}

/******************************************************************************
* \Syntax          : timer1ErrorState TIMER1_SetPreload(void)
* \Description     : This function set the timer1 preLoad Value
*******************************************************************************/

timer1ErrorState TIMER1_SetPreload(u16 preLoadValue)
{
	TIMER1_TCNT1_REG = preLoadValue;
	return TIMER1_SUCCESS;
}

/******************************************************************************
* \Syntax          : timer1ErrorState TIMER1_EnableInterrupt(void)
* \Description     : This function enable the interrupt of timer1
*******************************************************************************/

timer1ErrorState TIMER1_EnableInterrupt(void)
{
	#if (TIMER1_OPERATION_MODE == TIMER1_MODE_INTERVAL)
	SET_BIT(TIMER1_TIMSK_REG,TIMER1_INTERVAL_INT_ENABLE_BIT_NO);
	#endif
	return TIMER1_SUCCESS;
}

/******************************************************************************
* \Syntax          : timer1ErrorState TIMER1_DisableInterrupt(void)
* \Description     : This function disable the interrupt of timer1
*******************************************************************************/

timer1ErrorState TIMER1_DisableInterrupt(void)
{
	#if (TIMER1_OPERATION_MODE == TIMER1_MODE_INTERVAL)
	CLEAR_BIT(TIMER1_TIMSK_REG,TIMER1_INTERVAL_INT_ENABLE_BIT_NO);
	#endif
	return TIMER1_SUCCESS;
}



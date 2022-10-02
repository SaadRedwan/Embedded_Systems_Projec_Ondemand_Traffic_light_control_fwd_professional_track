/*
 * GlblInterrupt.c
 *
 *  Created on: May 22, 2021
 *      Author: Eng_Fawzi
 */

#include "GlblInterrupt_Interface.h"


/******************************************************************************
* \Syntax          : glbIntErrorState EnableAllInterrupts(void)
* \Description     : This function enable the global interrupts flag
*******************************************************************************/

glbIntErrorState EnableAllInterrupts()
{
	SET_BIT(AVR_SREG_REG,I_BIT);

	return GLB_INT_SUCCESS;
}

/******************************************************************************
* \Syntax          : glbIntErrorState DisableAllInterrupts(void)
* \Description     : This function disable the global interrupts flag
*******************************************************************************/

glbIntErrorState DisableAllInterrupts()
{
	CLEAR_BIT(AVR_SREG_REG,I_BIT);

	return GLB_INT_SUCCESS;
}

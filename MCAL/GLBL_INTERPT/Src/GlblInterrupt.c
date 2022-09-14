/*
 * GlblInterrupt.c
 *
 *  Created on: May 22, 2021
 *      Author: Eng_Fawzi
 */

#include "GlblInterrupt_Interface.h"
glbIntErrorState EnableAllInterrupts()
{
	SET_BIT(AVR_SREG_REG,I_BIT);

	return GLB_INT_SUCCESS;
}
glbIntErrorState DisableAllInterrupts()
{
	CLEAR_BIT(AVR_SREG_REG,I_BIT);

	return GLB_INT_SUCCESS;
}

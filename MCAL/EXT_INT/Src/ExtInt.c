/********************************
 * File  	:  ExtInt.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include "ExtInt_Interface.h"

/******************************************************************************
* \Syntax          : extIntErrorState ExtInt_Enable(void)
* \Description     : This function enable external interrupt INT0
*******************************************************************************/

extIntErrorState ExtInt_Enable(Int_ID extIntID)
{
		SET_BIT(EXTINT_GICR_REG,EXT_INT0_EN_BIT);
		return EXT_INT_SUCCESS;
}

/******************************************************************************
* \Syntax          : extIntErrorState ExtInt_Enable(void)
* \Description     : This function disable external interrupt INT0
*******************************************************************************/

extIntErrorState ExtInt_Disable(Int_ID extIntID)
{
		CLEAR_BIT(EXTINT_GICR_REG,EXT_INT0_EN_BIT);
		return EXT_INT_SUCCESS;
}

/******************************************************************************
* \Syntax          : extIntErrorState ExtInt_Enable(void)
* \Description     : This function define the sense mode of
* the external interrupt  INT0 high level, any level, rising edge or falling edge
*******************************************************************************/

extIntErrorState ExtInt_SnsCtrlSet(Int_ID extIntID,Sense_Mode_ID intSense)
{
		EXTINT_MCUCR_REG|=intSense<<EXT_INT0_SENSE_BIT;
		return EXT_INT_SUCCESS;
}

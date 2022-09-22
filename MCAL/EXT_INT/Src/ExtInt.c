/********************************
 * File  	:  ExtInt.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include "ExtInt_Interface.h"

void ExtInt_Enable(Int_ID extIntID)
{
		SET_BIT(EXTINT_GICR_REG,EXT_INT0_EN_BIT);
}
void ExtInt_Disable(Int_ID extIntID)
{
		CLEAR_BIT(EXTINT_GICR_REG,EXT_INT0_EN_BIT);
}
void ExtInt_SnsCtrlSet(Int_ID extIntID,Sense_Mode_ID intSense)
{
		EXTINT_MCUCR_REG|=intSense<<EXT_INT0_SENSE_BIT;
}

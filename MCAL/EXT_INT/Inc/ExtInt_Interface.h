/**************************************
 * File  	:  ExtInt_Interface.h
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#ifndef MCAL_EXT_INT_INC_EXTINT_INTERFACE_H_
#define MCAL_EXT_INT_INC_EXTINT_INTERFACE_H_

#include "ExtInt_Private.h"
#include "ExtInt_Types.h"
#include "Std_Types.h"
#include "Bit_Math.h"

extIntErrorState ExtInt_Enable(Int_ID);
extIntErrorState ExtInt_Disable(Int_ID);
extIntErrorState ExtInt_SnsCtrlSet(Int_ID,Sense_Mode_ID);

#endif /* MCAL_EXT_INT_INC_EXTINT_INTERFACE_H_ */

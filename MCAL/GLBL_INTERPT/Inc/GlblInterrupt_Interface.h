/*
 * File  	:  GlblInterrupt_Interface.h
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#ifndef MCAL_GLBL_INTERPT_INC_GLBLINTERRUPT_INTERFACE_H_
#define MCAL_GLBL_INTERPT_INC_GLBLINTERRUPT_INTERFACE_H_

#include "Bit_Math.h"
#include "GlblInterrupt_Private.h"
#include "Std_Types.h"
#include "GlblInterrupt_Types.h"


glbIntErrorState EnableAllInterrupts(void);
glbIntErrorState DisableAllInterrupts(void);

#endif /* MCAL_GLBL_INTERPT_INC_GLBLINTERRUPT_INTERFACE_H_ */

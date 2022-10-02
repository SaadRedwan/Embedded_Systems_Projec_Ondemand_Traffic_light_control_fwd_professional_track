/********************************
 * File  	:  ExtInt_Types.h
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#ifndef MCAL_EXT_INT_INC_EXTINT_TYPES_H_
#define MCAL_EXT_INT_INC_EXTINT_TYPES_H_

typedef enum
{
	EXT_INT0
}Int_ID;

typedef enum
{
	LOW_LEVEL_MODE,
	ANY_LEVEL_MODE,
	FAILING_EDGE_MODE,
	RISING_EDGE_MODE
}Sense_Mode_ID;

typedef enum
 {
 	EXT_INT_FAIL,
	EXT_INT_SUCCESS
 }extIntErrorState;

#endif /* MCAL_EXT_INT_INC_EXTINT_TYPES_H_ */

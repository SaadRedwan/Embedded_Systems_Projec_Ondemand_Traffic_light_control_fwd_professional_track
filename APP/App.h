/********************************
 * File  	:  App.h
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#ifndef APP_APP_H_
#define APP_APP_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Dio_Interface.h"
#include "GlblInterrupt_Interface.h"
#include "ExtInt_Interface.h"
#include "Timer1.h"
#include "Led_Interface.h"

#include "App_Types.h"



void Normal_Mode(void);
void Pedestrian_Mode(void);
void App_Init(void);
void App_start(void);



#endif /* APP_APP_H_ */

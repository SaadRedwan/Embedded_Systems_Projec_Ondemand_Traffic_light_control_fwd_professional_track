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
#include "Timer1_Interface.h"

#include "Dio_Interface.h"
#include "GlblInterrupt_Interface.h"
#include "ExtInt_Interface.h"
#include "Led_Interface.h"

#include "App_Types.h"



modeRunningErrorState Normal_Mode(void);
modeRunningErrorState Pedestrian_Mode(void);
appErrorState App_Start(void);
appErrorState App_Running(void);



#endif /* APP_APP_H_ */

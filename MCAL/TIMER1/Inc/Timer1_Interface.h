 /********************************
 * File  	:  Timer1.h
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#ifndef TIMER1_H_
#define TIMER1_H_

#include "Bit_Math.h"
#include "Timer1_Cfg.h"
#include "Timer1_Private.h"

/*	TIMER1 Operation Modes	*/
#define TIMER1_INTERVAL_MODE_WGM10			((u8)0<<0)
#define TIMER1_INTERVAL_MODE_WGM11			((u8)0<<1)
#define TIMER1_INTERVAL_MODE_WGM12			((u8)0<<3)
#define TIMER1_INTERVAL_MODE_WGM13			((u8)0<<4)


/*	TIMER1 Clock Select Prescaler	*/
#define TIMER1_CS_1024_PRESCALER	    	((u8)5<<0)



/*	Timer1 Interrupt Enable	Bits */
#define TIMER1_INTERVAL_INT_ENABLE_BIT_NO		(2)


#define TIMER1_TOP 			(65535u)

timer1ErrorState TIMER1_Init(void);
timer1ErrorState TIMER1_Start(u8 prescaler);
timer1ErrorState TIMER1_Stop(void);
timer1ErrorState TIMER1_SetPreload(u16 preLoadValue);
timer1ErrorState TIMER1_EnableInterrupt(void);
timer1ErrorState TIMER1_DisableInterrupt(void);

#endif  /* TIMER1_H_ */

/********************************
 * File  	:  Timer1_Test_Model.c
 * Date	 	:  Oct 01, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/


// #include <avr/io.h>
// #include <avr/interrupt.h>
// #include <util/delay.h>

// #include "Dio_Interface.h"
// #include "Timer1_Interface.h"
// #include "ExtInt_Interface.h"
// #include "GlblInterrupt_Interface.h"



// #define TIMER1_500ms_PRELOAD       TIMER1_TOP-7813
// volatile u8 counter=0;



// ISR(INT0_vect)
// {
// 	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
// 	TIMER1_Start(TIMER1_CS_1024_PRESCALER);
// 	TIMER1_EnableInterrupt();

// 	Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL1,STD_HIGH);
// 	counter=0;
// }


// ISR(TIMER1_OVF_vect)
// {
// 	counter++;
// 	Dio_FlipChannel(DIO_PORTA,DIO_CHANNEL0);
// 	if(counter==10)
// 	{
// 		TIMER1_Stop();
// 		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL0,STD_LOW);
// 		Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL1,STD_LOW);
// 		TIMER1_DisableInterrupt();
// 	}
// 	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
// }


// int main(void)
// {
// 	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL0,OUTPUT);
// 	Dio_ConfigChannel(DIO_PORTA,DIO_CHANNEL1,OUTPUT);



// 	TIMER1_Init();

// 	TIMER1_SetPreload(TIMER1_500ms_PRELOAD);
// 	TIMER1_Start(TIMER1_CS_1024_PRESCALER);

// 	TIMER1_EnableInterrupt();

// 	ExtInt_SnsCtrlSet(EXT_INT0,FAILING_EDGE_MODE);
// 	ExtInt_Enable(EXT_INT0);

// 	EnableAllInterrupts();
// 	Dio_WriteChannel(DIO_PORTA,DIO_CHANNEL1,STD_HIGH);


// 	while(1)
// 	{

// 	}
// }

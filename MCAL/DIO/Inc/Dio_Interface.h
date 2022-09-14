/*
 * Dio_Interface.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Eng_Fawzi
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Std_Types.h"
#include "Dio_Types.h"
#include "Dio_Private.h"
#include "Bit_Math.h"

dioErrorState Dio_ConfigChannel(Dio_Port port,Dio_Channel channel, Dio_Direction direction);
dioErrorState Dio_WriteChannel(Dio_Port port,Dio_Channel channel, Dio_Level level);
Dio_Level Dio_ReadChannel(Dio_Port port,Dio_Channel channel);
dioErrorState Dio_FlipChannel(Dio_Port port,Dio_Channel channel);
#endif /* DIO_INTERFACE_H_ */

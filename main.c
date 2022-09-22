/********************************
 * File  	:  main.c
 * Date	 	:  Sep 06, 2022
 * Target	:  ATMEGA32
 * Author	:  Saad Redwan
 ********************************/

#include "App.h"



int main(void)
{
	App_Start();

	while(1)
	{
		App_Running();
	}

	return 0;
}

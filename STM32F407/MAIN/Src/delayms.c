/*
 * delayms.c
 *
 *  Created on: Feb 10, 2024
 *      Author: vishnu
 */

#include "delayms.h"
#include "stm32f4xx.h"


void delayms(int delay){

	SysTick -> LOAD = 16000;  // no. of clk per milliseconds
	SysTick -> VAL = 0;  //  clear current value
	SysTick -> CTRL |= ( 1U << 0 ) | ( 1U << 2); // Enable clock and systick

	for( int i=0; i < delay; i++){

		while(((SysTick -> CTRL ) & ( 1U << 16 )) == 0);
	}

	SysTick -> CTRL =  0;

}

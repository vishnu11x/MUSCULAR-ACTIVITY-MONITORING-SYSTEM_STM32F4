/*
 * delayms.c
 *
 *  Created on: Feb 10, 2024
 *      Author: vishnu
 */

#include "delayms.h"


//----------------------------------------------------------------------------------------
/* FUNCTION DECLARATION */
void delayms(int delay);  // To create delay in ms


//-----------------------------------------------------------------------------------------

// To create delay in ms
void delayms(int delay){

	SysTick -> LOAD = 167999;  // no. of clk per milliseconds
	SysTick -> VAL = 0;  //  clear current value
	SysTick -> CTRL |= ( 1U << 0 ) | ( 1U << 2); // Enable clock and systick

	for( int i=0; i < delay; i++){

		while(((SysTick -> CTRL ) & ( 1U << 16 )) == 0);  // To check count flag is high
	}

	SysTick -> CTRL =  0;  // reset count flag

}

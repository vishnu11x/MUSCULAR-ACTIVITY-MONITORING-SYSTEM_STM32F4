/*
 * switch.c
 *
 *  Created on: Feb 8, 2024
 *      Author: vishnu
 */

#include "switch.h"


#define SWT1    ( 1U<< 0)

//----------------------------------------------------------------------------------------
/* FUNCTION DECLARATION */
void SWT1_init(void);  // TO SET PA0 as input

//----------------------------------------------------------------------------------------
/*Function definition*/

void SWT1_init(void){

	GPIOA-> MODER &= (~( 1U << 0)); // TO set PA0 as input
	GPIOA-> MODER &= (~( 1U << 1));
}

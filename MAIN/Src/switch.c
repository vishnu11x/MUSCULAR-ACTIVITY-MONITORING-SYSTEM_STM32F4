/*
 * switch.c
 *
 *  Created on: Feb 8, 2024
 *      Author: vishnu
 */
#include "switch.h"
#include <stm32f4xx.h>

#define SWT1    ( 1U<< 0)

//----------------------------------------------------------------------------------------
/* FUNCTION DECLARATION */
void SWT1_init(void);  // TO SET PA0 AS O/P
int SWT1_status(void);  // TO READ SWITCH STATUS

//----------------------------------------------------------------------------------------
/*Function definition*/

void SWT1_init(void){

	GPIOA-> MODER &= (~( 1U << 0));
	GPIOA-> MODER &= (~( 1U << 1));
}
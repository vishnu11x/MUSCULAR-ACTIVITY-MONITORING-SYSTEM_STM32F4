/**
 ******************************************************************************
 * @file           : main.c
 * @author         : VISHNU C S
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "main.h"



//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){

	clock_max_config();  // Set SysClk 168MHz
	fpu_enable();  // Enable floating point unit
	ADC_init();  // Initialize ADC
	SWT1_init();  // Initialize Switch
	uart2_init();




	while(1){


		/* Wait for input from switch*/
		while( ((GPIOA -> IDR ) & ( 1U << 0 )) == 1){

			ADC_start();  // start ADC
			delayms(1);

		}

		ADC_stop();


	}


}

//----------------------------------------------------------------------------------------


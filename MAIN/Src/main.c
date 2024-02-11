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

#include <stdint.h>
#include <stm32f4xx.h>  // Library for STM32f407
#include "adc.h"
#include "switch.h"
#include "delayms.h"
#include "arm_math.h"


uint32_t sensor_data;   // To store sensor data





//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){

	/* ENABLE FLOATING POINT UNIT FULL ACESS*/
	SCB -> CPACR |= ( 1U << 20);
	SCB -> CPACR |= ( 1U << 21);
	SCB -> CPACR |= ( 1U << 22);
	SCB -> CPACR |= ( 1U << 23);

	ADC_init();  // Initialize ADC
	SWT1_init();  // Initialize Switch
	while(!((GPIOA -> IDR ) & ( 1U << 0 )));  // Wait for I/o from switch
	ADC_start();  // start ADC


	while(1){


		sensor_data = ADC_read();
		delayms(500);



	}


}
//----------------------------------------------------------------------------------------


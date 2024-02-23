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


uint16_t sensor_read;   // To store sensor data
float32_t sensor_data;  // To store sensor data in volts





//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){

	clock_168hz_config();
	//SystemCoreClockUpdate();
	fpu_enable();  // Enable floating point unit
	ADC_init();  // Initialize ADC
	SWT1_init();  // Initialize Switch
	while(!((GPIOA -> IDR ) & ( 1U << 0 )));  // Wait for input from switch
	ADC_start();  // start ADC


	while(1){

		sensor_read = ADC_read();  // Read raw ADC value
		sensor_data = ADC_convert( sensor_read );  // converts raw ADC value to volts
		delayms(1000);
	}


}
//----------------------------------------------------------------------------------------


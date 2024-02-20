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
#include <stm32f4xx.h> // Library for STM32f407
#include <arm_math.h>  // Library for math functions
#include "adc.h"       // User defined header file for ADC
#include "switch.h"    // User defined header file for switches
#include "delayms.h"   // User defined header file for delay
#include "signal_pros.h"  // User defined header file for signal processing



uint16_t sensor_read;   // To store sensor data
float32_t sensor_data;  // To store sensor data in volts





//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){


	fpu_enable();  // Enable floating point unit
	ADC_init();  // Initialize ADC
	SWT1_init();  // Initialize Switch
	while(!((GPIOA -> IDR ) & ( 1U << 0 )));  // Wait for input from switch
	ADC_start();  // start ADC


	while(1){

		sensor_read = ADC_read();  // Read raw ADC value
		sensor_data = ADC_convert( sensor_read );  // converts raw ADC value to volts
		delayms(500);
	}


}
//----------------------------------------------------------------------------------------


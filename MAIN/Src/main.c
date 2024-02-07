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
#include <adc.h>  // Library for adc config


uint32_t sensor_data;   // To store sensor data





//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){

	ADC_init();
	ADC_conv();

	while(1){

		sensor_data = ADC_read();

	}


}
//----------------------------------------------------------------------------------------


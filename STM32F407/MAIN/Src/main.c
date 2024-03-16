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

extern volatile float32_t sensor_data;
extern float32_t LPF_450HZ_KERNEL[31];
extern float32_t HPF_25HZ_KERNEL[31];
volatile float32_t fltr_sensor_data;
fir_filter_type fir_lpf;
fir_filter_type fir_hpf;
char buff[31];
char buff_1[31];
//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){

	clock_max_config();  // Set SysClk 168MHz
	fpu_enable();  // Enable floating point unit
	ADC_init();  // Initialize ADC
	SWT1_init();  // Initialize Switch
	uart2_init();  // Initialize UART2
	// initialize Filter function
	fir_fltr_init(&fir_lpf,LPF_450HZ_KERNEL , 31);
	fir_fltr_init(&fir_hpf, HPF_25HZ_KERNEL, 31);



	while(1){


		/* Wait for input from switch*/
		while( ((GPIOA -> IDR ) & ( 1U << 0 )) == 1){

			ADC_start();  // start ADC
			fltr_sensor_data = fir_fltr_run(&fir_hpf, sensor_data);
			fltr_sensor_data = fir_fltr_run(&fir_lpf, fltr_sensor_data);
			sprintf(buff,"%f \n \r",fltr_sensor_data);
			uart2_string_write(buff,"\n \r");
			delayms(1);


		}

		ADC_stop();
	 


	}


}

//----------------------------------------------------------------------------------------

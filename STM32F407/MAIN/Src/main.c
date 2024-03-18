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
volatile float32_t lpf_data;
volatile float32_t hpf_data;

extern float32_t LPF_450HZ_KERNEL[fltr_len];
extern float32_t HPF_25HZ_KERNEL[fltr_len];

fir_filter_type fir_lpf;
fir_filter_type fir_hpf;

float32_t rx_data[100];
float32_t rx_temp;

//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){
	clock_max_config();  // Set SysClk 168MHz
	fpu_enable();  // Enable floating point unit
	SWT1_init();  // Initialize Switch
	uart2_init();  // Initialize UART2
	rx_fifo_init();  // Initialize FIFO receive

	// initialize Filter function
	fir_fltr_init(&fir_lpf,LPF_450HZ_KERNEL , fltr_len);
	fir_fltr_init(&fir_hpf, HPF_25HZ_KERNEL, fltr_len);


	ADC_init();  // Initialize ADC
	ADC_trigger_init();  // Initialize timer trigger for ADC


	/* Wait for input from switch*/
	while( ((GPIOA -> IDR ) & ( 1U << 0 )) == 0);
	delayms(200);


	while(1){

		enable_adc();

		for( int i=0; i < 100; i++){

			rx_fifo_put(sensor_data);

		}

		for(int j = 0; j < 100; j++){

			rx_fifo_get(&rx_temp);
			rx_data[j] = rx_temp;
		}
		//hpf_data = fir_fltr_run(&fir_hpf, sensor_data);
		//lpf_data = fir_fltr_run(&fir_lpf, hpf_data);
		//delayms(1);
		/* Wait for input from switch*/
		if( ((GPIOA -> IDR ) & ( 1U << 0 )) == 1){
			disable_adc();
			break;
		}
	}

}



//----------------------------------------------------------------------------------------

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

extern float32_t BPF_25_450HZ [FLTR_LEN];

float32_t bpf_data[ FLTR_LEN + RXFIFOSIZE - 1];

float32_t rx_data[RXFIFOSIZE];
float32_t rx_temp;

//----------------------------------------------------------------------------------------
/* MAIN FUNCTION */

int main(){
	clock_max_config();  // Set SysClk 168MHz
	fpu_enable();  // Enable floating point unit
	SWT1_init();  // Initialize Switch
	uart2_init();  // Initialize UART2
	rx_fifo_init();  // Initialize FIFO receive


	ADC_init();  // Initialize ADC
	ADC_trigger_init();  // Initialize timer trigger for ADC


	/* Wait for input from switch*/
	while( ((GPIOA -> IDR ) & ( 1U << 0 )) == 0);
	delayms(200);


	while(1){

		enable_adc();

		for( int i=0; i < RXFIFOSIZE; i++){

			rx_fifo_put(sensor_data);

		}

		for(int j = 0; j < RXFIFOSIZE; j++){

			rx_fifo_get(&rx_temp);
			rx_data[j] = rx_temp;
		}

		arm_conv_f32( (float32_t*) BPF_25_450HZ, (uint32_t) FLTR_LEN,
				(float32_t*) rx_data, (uint32_t) RXFIFOSIZE, (float32_t*) bpf_data);

		/* Wait for input from switch*/
		if( ((GPIOA -> IDR ) & ( 1U << 0 )) == 1){
			disable_adc();
			break;
		}
	}

}



//----------------------------------------------------------------------------------------

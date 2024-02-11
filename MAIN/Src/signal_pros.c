/*
 * signal_pros.c
 *
 *  Created on: Feb 12, 2024
 *      Author: vishnu
 */

#include "signal_pros.h"
#include <stm32f4xx.h>
#include <arm_math.h>


/* FUNCTION DECLARATION */

void fpu_enable(void); // To enable FPU

void convolution( float32_t * source_sig_arry, float32_t * destn_signal_arry, float32_t * imp_response_arry,
		          uint32_t source_sig_len, uint32_t imp_sig_len); // To perform covolution



/* FUNCTION DEFENTION */

void fpu_enable(void){

	/* ENABLE FLOATING POINT UNIT FULL ACESS*/
	SCB -> CPACR |= ( 1U << 20);
	SCB -> CPACR |= ( 1U << 21);
	SCB -> CPACR |= ( 1U << 22);
	SCB -> CPACR |= ( 1U << 23);
}

void convolution( float32_t * source_sig_arry, float32_t * destn_signal_arry, float32_t * imp_response_arry,
		          uint32_t source_sig_len, uint32_t imp_sig_len){

	uint32_t i, j;

	uint32_t destn_sig_len = source_sig_len + imp_sig_len -1  ;  // To calculate the length of output signal

	/* Clear Destination buffer */
	for( i = 0; i < destn_sig_len; i++){
		destn_signal_arry[i] = 0;
	}

	/* Convolution */
	for ( i = 0; i < source_sig_len; i++ ){

		for ( j = 0; j < imp_sig_len; j++){

			destn_signal_arry[i+j] = destn_signal_arry[i+j] + ( source_sig_arry[i] * imp_response_arry [j] );


		}
	}


}




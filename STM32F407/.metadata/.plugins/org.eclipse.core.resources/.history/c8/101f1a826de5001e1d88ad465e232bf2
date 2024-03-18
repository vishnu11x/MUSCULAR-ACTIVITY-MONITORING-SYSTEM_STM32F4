/*
 * signal_pros.h
 *
 *  Created on: Feb 12, 2024
 *      Author: vishnu
 */

#ifndef SIGNAL_PROS_H_
#define SIGNAL_PROS_H_



#include <stdint.h>
#include <stm32f4xx.h>
#include <arm_math.h>

//-------------------------------------------------------------------------------------------------------

#define fltr_len 31


typedef struct{
	float32_t buff[fltr_len];
	uint32_t buff_indx;
	float32_t *kernel;
	uint32_t kernel_len;
	float32_t out;
}fir_filter_type;

//------------------------------------------------------------------------------------------------------------------------


/* FUNCTION DECLARATION */

void fpu_enable(void); // To enable FPU

// To perform covolution
void convolution( float32_t * source_sig_arry, float32_t * destn_signal_arry, float32_t * imp_response_arry,
		          uint32_t source_sig_len, uint32_t imp_sig_len);

// Function to real-time  filter function
void fir_fltr_init(fir_filter_type *fir, float32_t * fltr_kernel, uint32_t fltr_kernel_len);

// Function to apply rela-time filter function
float32_t fir_fltr_run (fir_filter_type *fir, float32_t samples);


#endif /* SIGNAL_PROS_H_ */

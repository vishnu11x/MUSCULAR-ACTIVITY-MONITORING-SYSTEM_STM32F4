/*
 * signal_pros.c
 *
 *  Created on: Feb 12, 2024
 *      Author: vishnu
 */

#include "signal_pros.h"



//------------------------------------------------------------------------------------------------------------------------


float32_t HPF_25HZ_KERNEL[fltr_len] = {-0.001566,-0.0018215,-0.0024966,-0.0035965,-0.0051015,
		-0.0069667,-0.0091244,-0.011487,-0.013951,-0.016404,-0.01873,-0.020816,-0.022558,
		-0.02387,-0.024685,0.9735,-0.024685,-0.02387,-0.022558,-0.020816,-0.01873,-0.016404,
		-0.013951,-0.011487,-0.0091244,-0.0069667,-0.0051015,-0.0035965,-0.0024966,-0.0018215,-0.001566
};

float32_t LPF_450HZ_KERNEL[fltr_len] = {0.0011976,0.0016526,-0.0013283,-0.0042247,0.0010487,
		0.0098447,0.0021961,-0.018572,-0.012112,0.02921,0.034582,-0.039563,-0.086033,0.047116,
		0.31051,0.44896,0.31051,0.047116,-0.086033,-0.039563,0.034582,0.02921,-0.012112,
		-0.018572,0.0021961,0.0098447,0.0010487,-0.0042247,-0.0013283,0.0016526,0.0011976
};
//---------------------------------------------------------------------------------------------------------------------

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

void fir_fltr_init(fir_filter_type *fir, float32_t * fltr_kernel, uint32_t fltr_kernel_len){

	fir -> kernel = fltr_kernel;  // Set filter kernel

	fir -> kernel_len = fltr_kernel_len;  // Set kernel length

	// clear buffer
	for(int i=0; i< (fir -> kernel_len); i++){

		fir -> buff[i] = 0;
	}

	fir -> buff_indx = 0;  // Reset buffer index

	fir -> out = 0.00f;  // Clear output

}

float32_t fir_fltr_run (fir_filter_type *fir, float32_t samples){

	fir -> buff[fir->buff_indx] = samples;  // Store latest sample in the buffer

	fir -> buff_indx++;  // Increment buff index

	if(fir -> buff_indx == fltr_len){

		fir -> buff_indx =0;
	}

	/* Perform convolution */
	fir -> out = 0.0f;

	uint32_t sum_indx = fir -> buff_indx;

	for (int i = 0; i < (fir -> kernel_len); i++){

		if(sum_indx >0)
			sum_indx--;
		else
			sum_indx = (fir -> kernel_len -1);

		fir -> out += fir -> kernel[i] * fir ->  buff[sum_indx];
	}

	return fir -> out;
}





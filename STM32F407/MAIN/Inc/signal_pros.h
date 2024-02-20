/*
 * signal_pros.h
 *
 *  Created on: Feb 12, 2024
 *      Author: vishnu
 */

#ifndef SIGNAL_PROS_H_
#define SIGNAL_PROS_H_
#include <stdint.h>
#include <arm_math.h>

void fpu_enable(void); // To enable FPU

void convolution( float32_t * source_sig_arry, float32_t * destn_signal_arry, float32_t * imp_response_arry,
		          uint32_t source_sig_len, uint32_t imp_sig_len); // To perform covolution



#endif /* SIGNAL_PROS_H_ */
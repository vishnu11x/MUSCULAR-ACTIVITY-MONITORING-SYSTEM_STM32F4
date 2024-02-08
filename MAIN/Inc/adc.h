/*
 * adc.h
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
void ADC_init (void);
void ADC_start (void);
uint32_t  ADC_read (void);
void ADC_stop (void);


#endif /* ADC_H_ */

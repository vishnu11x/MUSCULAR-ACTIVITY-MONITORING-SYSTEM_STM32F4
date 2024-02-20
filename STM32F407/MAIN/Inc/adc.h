/*
 * adc.h
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
#include <arm_math.h>
void ADC_init (void);  // To initialize ADC
void ADC_start (void); // To start ADC
uint16_t  ADC_read (void);  // To read raw ADC value
void ADC_stop (void);   // To stop ADC
float32_t ADC_convert( uint16_t raw_adc);  // TO convert raw ADC value to volts


#endif /* ADC_H_ */
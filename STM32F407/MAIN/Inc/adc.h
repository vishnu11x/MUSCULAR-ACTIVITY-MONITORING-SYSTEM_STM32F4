/*
 * adc.h
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <stm32f4xx.h>  // Library for STM32f407
#include <arm_math.h>

extern volatile uint16_t adc_data;  //  To store raw ADC value
extern volatile float32_t sensor_data;  // To store sensor data in volts



/* FUNCTION DECLARATION */
void ADC_init (void);  // To initialize ADC
void enable_adc(void); // To enable ADC
void ADC_start (void); // To start ADC
void disable_adc (void);   // To disable ADC
float32_t ADC_convert( uint16_t raw_adc);  // TO convert raw ADC value to volts
void ADC_trigger_init(void);
float32_t adc_callback(void);
void tim_callback(void);
extern void ADC_IRQHandler(void);
extern void TIM2_IRQHandler(void);


#endif /* ADC_H_ */

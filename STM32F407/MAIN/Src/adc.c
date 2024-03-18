/*
 * adc.c
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#include "adc.h"


#define GPIOAEN          ( 1U << 0 )  //TO enable GPIOA
#define ADC1EN           ( 1U << 8 )  //TO enable ADC1
#define ADC_CH1          ( 1U << 0 )  // To Select channel 1
#define ADC_VREF         3.3f         // ADC reference voltage
#define ADC_RES          (float)(pow(2,12)-1)  // Resolution of ADC (12-bit)

volatile uint16_t adc_data;
volatile float32_t sensor_data;

//----------------------------------------------------------------------------------------
/*Function definition*/

//To initialize ADC1
void ADC_init (void){

    /* CONFIG GPIO */
	RCC -> AHB1ENR |= GPIOAEN;  // Enable clock to GPIOA

	GPIOA -> MODER |= ( 1U << 2 );  // Enable analog mode in Port A1
	GPIOA -> MODER |= ( 1U << 3 );

	/* CONFIG ADC */
	RCC -> APB2ENR |= ( ADC1EN );  // Enable clock to ADC1
	ADC1 -> CR2 &= ~( 1U << 1);  // To Set in single conversion mode
	ADC1 -> SQR3 = ADC_CH1;  // Select Channel 1 in Sequence
	ADC1 -> SQR1 = ( 0X00 );  // length of Channel Sequence (1)
	ADC1 -> CR1 &= ~(( 1U << 24 ) | ( 1U << 25 )); // Set Resolution to 12-bit
	ADC1 -> CR1 |= ( 1U << 5);  // Enable interrupt for EOC
	NVIC_SetPriority( ADC_IRQn,0);  // Set interrupt priority
	NVIC_EnableIRQ ( ADC_IRQn);  // Enable interrupt in NVIC

}

void ADC_trigger_init(void){

	/* CONFIG TIMER FOR TRIGGER (1000HZ) */
	RCC -> APB1ENR |= ( 1U << 0); // Enable clock for TIM2
	TIM2 -> PSC = (4200 - 1);  // Set prescaler for 10000Hz timer frequency
	TIM2 -> ARR = (10 - 1);  // Set auto reload value
	TIM2 -> CNT = 0;
	TIM2 -> DIER |= ( 1U << 0);  // Enable update interrupt
	NVIC_SetPriority( TIM2_IRQn,1);  // Set interrupt priority
	NVIC_EnableIRQ( TIM2_IRQn);  // Enable interrupt in NVIC
}

void enable_adc(void){
	ADC1 -> CR2 |= ( 1U << 0 );  // Enable ADC1
	TIM2 -> CR1 |= ( 1U << 0);  // Enable TIM2
}
// To start conversion
void ADC_start (void){

	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion

}

void disable_adc (void){

	ADC1 -> CR2 &= (~( 1U << 30 ));  // To stop ADC conversion
	TIM2 -> CR1 &= ~( 1U << 0);  // Disable TIM2
}


float32_t adc_callback(void){

	adc_data = (ADC1->DR);
	sensor_data = ( adc_data * ADC_VREF) / ADC_RES ;  // Equation to convert to volts
	return (sensor_data);
}

void tim_callback(void){

	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion

}

extern void ADC_IRQHandler(void){

	if( ((ADC1->SR) & ( 1U << 1) ) != 0){

		ADC1 -> SR &= ~( 1U << 1);
		adc_callback();
	}
}
extern void TIM2_IRQHandler(void){

	if ( ((TIM2 -> SR) & ( 1U << 0 ))){
		TIM2 -> SR &= ~( 1U << 0);
		tim_callback();
	}
}




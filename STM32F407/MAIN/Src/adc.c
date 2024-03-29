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
	ADC1 -> CR2 |= ( 1U << 0 );  // Enable ADC1
	ADC1 -> SQR3 = ADC_CH1;  // Select Channel 1 in Sequence
	ADC1 -> SQR1 = ( 0X00 );  // length of Channel Sequence (1)
	ADC1 -> CR1 &= ~(( 1U << 24 ) | ( 1U << 25 )); // Set Resolution to 12-bit
	ADC1 -> CR1 |= ( 1U << 5);  // Enable interrupt for EOC
	ADC1 -> CR2 |= ( 1U << 28 ) | ( 1U << 29 ); //  Enable external trigger for ADC1
	ADC1 -> CR2 &= ~(( 1U << 24 ) | ( 1U << 27));// Select TIM2 TRGO event for external trigger
	ADC1 -> CR2 |= ( 1U << 25) | ( 1U << 25);
	NVIC_EnableIRQ ( ADC_IRQn);  // Enable interrupt in NVIC

	/* CONFIG TIMER FOR TRIGGER (1000HZ) */
	RCC -> APB1ENR |= ( 1U << 0); // Enable clock for TIM2
	TIM2 -> PSC = 41999;  // Set prescaler for 10000Hz timer frequency
	TIM2 -> ARR = 9;  // Set auto reload value
	TIM2 -> CR2 &= ~(( 1U << 4) | ( 1U << 6));  // Select update event for TRGO
	TIM2 -> CR2 |= ( 1U << 5);
	TIM2 -> CR1 |= ( 1U << 0);  // Enable TIM2
}

// To start conversion
void ADC_start (void){

	ADC1 -> CR2 &= ~( 1U << 1);  // To Set in single conversion mode
	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion
	ADC_stop();                  // Stop ADC
}

void ADC_stop (void){

	ADC1 -> CR2 &= (~( 1U << 30 ));  // To stop ADC conversion
}

float32_t ADC_read (void){

	adc_data = (ADC1->DR);
	sensor_data = ( adc_data * ADC_VREF) / ADC_RES ;  // Equation to convert to volts
	return (sensor_data);


}


void ADC_IRQHandler(void){

	if( ((ADC1->SR) & ( 1U << 1) ) != 0){

		ADC1 -> SR &= ~( 1U << 1);
		ADC_read();
	}
}



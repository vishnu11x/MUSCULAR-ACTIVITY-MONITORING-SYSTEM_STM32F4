/*
 * adc.c
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#include "adc.h"
#include <stm32f4xx.h>  // Library for STM32f407
#include <arm_math.h>



#define GPIOAEN          ( 1U << 0 )  //TO enable GPIOA
#define ADC1EN           ( 1U << 8 )  //TO enable ADC1
#define ADC_CH1          ( 1U << 0 )  // To Select channel 1
#define ADC_VREF         3.3f         // ADC reference voltage
#define ADC_RES          (float)(pow(2,12)-1)  // Resolution of ADC (12-bit)


/* FUNCTION DECLARATION */
void ADC_init (void);  // To initialize ADC
void ADC_start (void); // To start ADC
uint16_t  ADC_read (void);  // To read raw ADC value
void ADC_stop (void);   // To stop ADC
float32_t ADC_convert( uint16_t raw_adc);  // TO convert raw ADC value to volts


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
	//ADC1 -> CR1 |= (( 1U << 24 ) | ( 1U << 25 )); // Set Resolution to 12-bit
}

// To start conversion
void ADC_start (void){

	ADC1 -> CR2 |= ( 1U << 1 );  // To set continuous conversion mode
	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion
}

void ADC_stop (void){
	ADC1 -> CR2 &= (~( 1U << 30 ));  // To stop ADC conversion
}

// To read ADC data
uint16_t  ADC_read (void){

	while(!( ADC1-> SR & ( 1U << 1) ));  // To check if ADC conversion finished

	uint32_t value;  // To store raw ADC value
	value = (ADC1 -> DR);
	ADC1 -> SR &= (~( 1U << 1));  // Clear status register of ADC

 	return( value );
}

// TO convert raw ADC value to volts
float32_t ADC_convert( uint16_t raw_adc){

	float32_t ADC_volts = ( raw_adc * ADC_VREF) / ADC_RES;  // Equation to convert to volts
	return ( ADC_volts);
}


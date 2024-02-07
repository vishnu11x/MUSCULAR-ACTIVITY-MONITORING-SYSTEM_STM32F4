/*
 * adc.c
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#include <adc.h>
#include <stm32f4xx.h>  // Library for STM32f407

#define UARTEN           ( 1U << 17 )
#define GPIOAEN          ( 1U << 0 )  //TO enable GPIOA
#define ADC1EN           ( 1U << 8 )  //TO enable ADC1
#define ADC_CH1          ( 1U << 0 )  // To Select channel 1

/* FUNCTION DECLARATION */
void ADC_init (void);
void ADC_conv (void);
uint32_t  ADC_read (void);


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
void ADC_conv (void){

	ADC1 -> CR2 |= ( 1U << 1 );  // To set continuous conversion mode
	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion
}

// To read ADC data
uint32_t  ADC_read (void){

	while(!( ADC1-> SR & ( 1U << 1) )){}

 	return( ADC1 -> DR);
}
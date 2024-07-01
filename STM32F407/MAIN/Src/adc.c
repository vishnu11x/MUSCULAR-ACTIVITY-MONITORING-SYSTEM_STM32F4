/*
 * adc.c
 *
 *  Created on: Feb 7, 2024
 *      Author: vishnu
 */

#include "adc.h"


uint16_t adc_rawdata[NUM_SAMPLES];
volatile float32_t sensor_data;

//----------------------------------------------------------------------------------------
/*Function definition*/

//To initialize ADC1
void adc_dma_init (void){

    /* CONFIG GPIO */
	RCC -> AHB1ENR |= (1U << 0);  // Enable clock to GPIOA

	GPIOA -> MODER |= ( 1U << 0 );  // Enable analog mode in PA0
	GPIOA -> MODER |= ( 1U << 1 );

	/* CONFIG ADC */
	RCC -> APB2ENR |= (1U << 8 );  // Enable clock to ADC1
	ADC1 -> CR2 |= (1U << 8) | (1U << 9); // Select to use DMA

	ADC1 -> CR2 |= ( 1U << 28 ); //  Enable external trigger on rising edge for ADC1
	ADC1 -> CR2 &= ~( 1U << 29 );

	ADC1 -> CR2 &= ~(( 1U << 24 ) | ( 1U << 27)); // Select TIM2 TRGO event for external trigger
	ADC1 -> CR2 |= ( 1U << 25) | ( 1U << 26);




	/* CONFIG DMA */
	RCC -> AHB1ENR |= (1U << 22);  // Enable clock for DMA
	DMA2_Stream0 -> CR &= ~(1U << 0) ;  // Disable DMA stream

	while( DMA2_Stream0 -> CR & (1U << 0)){}  // Wait till stream is disable
	DMA2_Stream0 -> CR |= (1U << 8);  // Enable circular mode

	DMA2_Stream0 -> CR |= (1U << 13); // Set Msize to 16-bit (half-word)
	DMA2_Stream0 -> CR &= ~(1U << 14);

	DMA2_Stream0 -> CR |= (1U << 11);  // Set Psize to 16-bit (half-word)
	DMA2_Stream0 -> CR &= (1U << 12);

	DMA2_Stream0 -> CR |= (1U << 10);  // Enable memory increment

	DMA2_Stream0 -> PAR = (uint32_t)(&(ADC1 -> DR));  // Set periph address
	DMA2_Stream0 -> M0AR = (uint32_t)(&adc_rawdata);  // Set memory address

	DMA2_Stream0 -> NDTR = NUM_SAMPLES;  // Set No.of data item to transfer

	/* CONFIG TIMER FOR TRIGGER (1000HZ) */
	RCC -> APB1ENR |= ( 1U << 0); // Enable clock for TIM2
	TIM2 -> PSC = (8400 - 1);  // Set prescaler for 10000Hz timer frequency
	TIM2 -> ARR = (10-1);  // Set auto reload value

	TIM2 -> CR2 &= ~( 1U << 4);  // Select update event for TRGO
	TIM2 -> CR2 |= ( 1U << 5);
	TIM2 -> CR2 &= ~( 1U <<6);



	ADC1 -> CR2 |= ( 1U << 0 );  // Enable ADC1
	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion
	DMA1_Stream0 -> CR |= (1U << 0);  // Enable DMA stream
	TIM2 -> CR1 |= ( 1U << 0);  // Enable TIM2


}


// To start conversion
void adc_start (void){

	ADC1 -> CR2 |= ( 1U << 30);  // To start the ADC conversion
}

void adc_stop (void){

	ADC1 -> CR2 &= (~( 1U << 30 ));  // To stop ADC conversion
}






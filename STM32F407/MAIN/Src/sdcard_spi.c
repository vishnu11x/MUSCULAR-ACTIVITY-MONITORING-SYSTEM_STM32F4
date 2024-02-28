/*
 * sdcard_spi.c
 *
 *  Created on: Feb 21, 2024
 *      Author: vishnu
 */

#include "sdcard_spi.h"




//------------------------------------------------------------------------------------------------


// Function definition


void spi1_init(){

	RCC -> AHB1ENR |= ( 1U << 0 ); // Enable clock for GPIOA

		/* Set alternate function for PA5(CLK), PA6(MISO), PA7(MOSI) */

		GPIOA -> MODER &= ~( 1U << 10); // Alternative function for PA5
		GPIOA -> MODER |= ( 1U << 11);

		GPIOA -> MODER &= ~( 1U << 12); // Alternative function for PA6
		GPIOA -> MODER |= ( 1U << 13);

		GPIOA -> MODER &= ~( 1U << 14); // Alternative function for PA7
		GPIOA -> MODER |= ( 1U << 15);

		/* Set PA9 as o/p for SC pin */

		GPIOA -> MODER |= ( 1U << 18);  // General purpose o/p mode for PA9
		GPIOA -> MODER &= ~( 1U << 19);

		/* Set alternative function type (AF5) for PA5, PA6, PA7 */

		GPIOA -> AFR[0] |= ( 1U << 20);  // AF5 alternative function for PA5
		GPIOA -> AFR[0] &= ~( 1U << 21);
		GPIOA -> AFR[0] |= ( 1U << 22);
		GPIOA -> AFR[0] &= ~( 1U << 23);

		GPIOA -> AFR[0] |= ( 1U << 24);  // AF5 alternative function for PA6
		GPIOA -> AFR[0] &= ~( 1U << 25);
		GPIOA -> AFR[0] |= ( 1U << 26);
		GPIOA -> AFR[0] &= ~( 1U << 27);

		GPIOA -> AFR[0] |= ( 1U << 28);  // AF5 alternative function for PA7
		GPIOA -> AFR[0] &= ~( 1U << 29);
		GPIOA -> AFR[0] |= ( 1U << 20);
		GPIOA -> AFR[0] &= ~( 1U << 21);


	RCC -> APB2ENR |= ( 1U << 12); // Enable clock for SPI1

	SPI1 -> CR1 &= ~( 1U << 3); // To set Baud rate control Fpclk/2
	SPI1 -> CR1 &= ~( 1U << 4);
	SPI1 -> CR1 &= ~( 1U << 5);

	SPI1 -> CR1 |= ( 1U << 0);  // Set CLOCK PHASE to 1
	SPI1 -> CR1 |= ( 1U << 1);  // Set CLOCK POLARITY to 1

	SPI1 -> CR1 |= ( 1U << 11);  // TO set 16-bit data frame format

	SPI1 -> CR1 &= ~( 1U << 10);  // To select full duplex mode

	SPI1 -> CR1 |= ( 1U << 2);  // Set to master mode

	SPI1 -> CR1 |= ( 1U << 9); //  Set software slave management
	SPI1 -> CR1 |= ( 1U << 8); // Replace NSS bit with SSI bit if SSM enabled

	SPI1 -> CR1 &= ~( 1U << 7);  // Transmit MSB first

	SPI1 -> CR1 |= ( 1U << 6);  // Enable SPI
}

void spi1_send (uint16_t *data, uint32_t size){

	uint32_t i =0;
	uint16_t temp;
	while(i<size){

	while(!(SPI1 -> SR & ( 1U << 1))){}  // Wait for TXE flag to set

	/* Write data to Data Register */
	SPI1 -> DR = data[i];
	i++;

	}

	while(!(SPI1 -> SR & ( 1U << 1))){}  // Wait for TXE flag to set
	while((SPI1 -> SR) & ( 1U << 7)){}  // Wait for BSY flag to reset

	/* clear overrun flag by reading DR & SR register */
	temp = (SPI1 -> DR);
	temp = (SPI1 -> SR);
}

void spi1_receive (uint16_t *data, uint32_t size){
	while(size){
		SPI1 -> DR = 0;  // Write dummy data

		while(!(SPI1 -> SR & ( 1U << 0))){}  // Wait for RXNE to set
		*data++ = SPI1 -> DR;
		size--;
	}

}

void sc_enable(void){

	GPIOA -> ODR &= ~( 1U << 9 );  // RESET PA9
}

void sc_disable(void){

	GPIOA -> ODR |= ( 1U << 9 );  // SET PA9
}



/*
 * sdcard_spi.h
 *
 *  Created on: Feb 21, 2024
 *      Author: vishnu
 */

#ifndef SDCARD_SPI_H_
#define SDCARD_SPI_H_

#include <stm32f4xx.h>
#include <arm_math.h>
#include <stdint.h>
#include <diskio.h>


//------------------------------------------------------------------------------------------------

// Function Declaration

void spi1_init(void);  // To initialize  SPI
void spi1_send (uint16_t *data, uint32_t size);  // To transmit data
void spi1_recevie (uint16_t *data, uint32_t size);  // TO receive data
void sc_enable(void);  // To enable SC line
void sc_disable(void);  // To disable SC line



#endif /* SDCARD_SPI_H_ */
/*
 * sdcard_spi.h
 *
 *  Created on: Feb 21, 2024
 *      Author: vishnu
 */

#ifndef SDCARD_SPI_H_
#define SDCARD_SPI_H_

#include <stm32f4xx.h>
#include <stdint.h>

void spi1_gpio_init(void);  // To initialize GPIO for SPI
void spi1_init(void);  // To initialize  SPI



#endif /* SDCARD_SPI_H_ */

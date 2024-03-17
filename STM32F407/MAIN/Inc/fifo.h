/*
 * fifo.h
 *
 *  Created on: Mar 17, 2024
 *      Author: vishnu
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <arm_math.h>

#define RXFIFOSIZE  50
#define RXFIFOFAIL  0
#define RXFIFOSUCESS 1

typedef float32_t rx_datatype;
//------------------------------------------------------------------------------------------
/* FUNCTION DECLARATION */
void rx_fifo_init(void); // To initialize FIFO
uint8_t rx_fifo_put(rx_datatype data);  // To put data into FIFO
uint8_t rx_fifo_get(rx_datatype * datapt);  // To get data from FIFO

#endif /* FIFO_H_ */

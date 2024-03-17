/*
 * fifo.c
 *
 *  Created on: Mar 17, 2024
 *      Author: vishnu
 */
#include "fifo.h"

rx_datatype rx_fifo[RXFIFOSIZE];

volatile rx_datatype * rx_put_pt;
volatile rx_datatype * rx_get_pt;

//----------------------------------------------------------------------------
/* FUNCTION DEFINITION */
void rx_fifo_init(void){
	rx_put_pt = rx_get_pt = &rx_fifo[0];  // Reset FIFO
}

uint8_t rx_fifo_put(rx_datatype data){

	rx_datatype volatile * rx_nxt_put_pt;

	rx_nxt_put_pt = rx_put_pt + 1;

	if( rx_nxt_put_pt == &rx_fifo[RXFIFOSIZE])  // Check if at the end
		rx_nxt_put_pt = &rx_fifo[0];   // Wrap around

	if( rx_nxt_put_pt == rx_get_pt)
		return(RXFIFOFAIL);

	else
	{
		*(rx_put_pt) = data;  // Put data into FIFO
		rx_put_pt = rx_nxt_put_pt;
		return(RXFIFOSUCESS);
	}
}


uint8_t rx_fifo_get(rx_datatype * datapt){

	if(rx_put_pt == rx_get_pt)  // Check if FIFO is empty
		return(RXFIFOFAIL);

	*datapt = *(rx_get_pt++);  // Get data from FIFO

	if( rx_get_pt == &rx_fifo[RXFIFOSIZE])  // Check if at the end
		rx_get_pt = &rx_fifo[0];   // Wrap around

	return(RXFIFOSUCESS);


}

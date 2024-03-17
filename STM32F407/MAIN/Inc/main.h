/*
 * main.h
 *
 *  Created on: Feb 23, 2024
 *      Author: vishnu
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stm32f4xx.h> // Library for STM32f407
#include <arm_math.h>  // Library for math functions
#include "adc.h"       // User defined header file for ADC
#include "switch.h"    // User defined header file for switches
#include "delayms.h"   // User defined header file for delay
#include "signal_pros.h"  // User defined header file for signal processing
#include "clock.h"   // User defined header file to configure clock
#include "uart2.h"  // User defined header file for UART
/* FATfs header files */
#include <ff.h>
#include <diskio.h>
#include <spi1_sd.h>



#endif /* MAIN_H_ */

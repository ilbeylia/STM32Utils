/*
 * ADC_lib.h
 *
 *  Created on: Dec 6, 2024
 *      Author: ilbeyli
 */

#ifndef INC_ADC_LIB_H_
#define INC_ADC_LIB_H_

#include "stm32f4xx.h"
/*
 * Our use of two sample codes in ADC. These are the basic and DMA method.
 */


// Basic
uint8_t ADC_read(ADC_HandleTypeDef *hadc);

// DMA


#endif /* INC_ADC_LIB_H_ */

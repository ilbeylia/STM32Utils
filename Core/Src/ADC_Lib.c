/*
 * ADC_Lib.c
 *
 *  Created on: Dec 6, 2024
 *      Author: ilbeyli
 */

#include "ADC_lib.h"
#include "stdio.h"
#include "stdint.h"



// Basic
uint8_t ADC_read(ADC_HandleTypeDef *hadc){
	HAL_ADC_Start(hadc);
	while(HAL_ADC_PollForConversion(hadc, 100) != HAL_OK);
	uint32_t adc_value = HAL_ADC_GetValue(hadc);
	HAL_ADC_Stop(hadc);
	return adc_value;
}




/*
 * STEP_MOTOR_lib.h
 *
 *  Created on: Dec 10, 2024
 *      Author: ilbeyli
 */

#ifndef INC_STEP_MOTOR_LIB_H_
#define INC_STEP_MOTOR_LIB_H_


#include "stm32f4xx.h"



typedef struct
{

	TIM_HandleTypeDef*	Timer_handle;
	uint32_t			Timer_channel;

	GPIO_TypeDef*		dir_GPIOx;
	uint16_t			dir_GPIO_Pin;


	struct
	{
		uint32_t	sayac;
		uint32_t	adim;
		uint32_t	durum;
	}step_set;

}step_config;

typedef enum {
	Step_DURDU,
	Step_BASLADI,
}step_durum;

typedef enum {
	Step_ILERI,
	Step_GERI,
}Step_yon;




void step_init(	step_config* step_config,

				TIM_HandleTypeDef*	Timer_handle,
				uint32_t			Timer_channel,
				GPIO_TypeDef*		dir_GPIOx,
				uint16_t			dir_GPIO_Pin
				);

void step(step_config* step_config, uint32_t adim, uint32_t yon);

void step_durdur(step_config* step_config);

#endif /* INC_STEP_MOTOR_LIB_H_ */

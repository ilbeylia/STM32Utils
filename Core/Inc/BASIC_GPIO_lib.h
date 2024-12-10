/*
 * BASIC_GPIO_lib.h
 *
 *  Created on: Dec 10, 2024
 *      Author: ilbeyli
 */

#ifndef INC_BASIC_GPIO_LIB_H_
#define INC_BASIC_GPIO_LIB_H_


#include "stm32f4xx.h"
#include "stdio.h"
#include "stdint.h"


// status led config >> for four leds
typedef enum{
	LED_Mode1,
	LED_Mode2,
	LED_Mode3,
	LED_Mode4
}Status_led_mode_e;

typedef struct{
	GPIO_TypeDef * Led1_GPIOx;
	uint16_t Led1_GPIO_pin;
	GPIO_TypeDef * Led2_GPIOx;

	uint16_t Led2_GPIO_pin;

	GPIO_TypeDef * Led3_GPIOx;
	uint16_t Led3_GPIO_pin;

	GPIO_TypeDef * Led4_GPIOx;
	uint16_t Led4_GPIO_pin;

}Status_led_s;


void status_led_init(Status_led_s *status_led, GPIO_TypeDef * Led1_GPIOx, uint16_t Led1_GPIO_pin,
		GPIO_TypeDef * Led2_GPIOx, uint16_t Led2_GPIO_pin,
		GPIO_TypeDef * Led3_GPIOx, uint16_t Led3_GPIO_pin,
		GPIO_TypeDef * Led4_GPIOx, uint16_t Led4_GPIO_pin);

void status_led_process(Status_led_s* status_led, Status_led_mode_e Mode);



#endif /* INC_BASIC_GPIO_LIB_H_ */

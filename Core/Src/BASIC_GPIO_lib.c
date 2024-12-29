/*
 * BASIC_GPIO_lib.c
 *
 *  Created on: Dec 10, 2024
 *      Author: ilbeyli
 */

#include "BASIC_GPIO_lib.h"

// status led config >> for four leds
void status_led_init(Status_led_s *status_led, GPIO_TypeDef * Led1_GPIOx, uint16_t Led1_GPIO_pin,
		GPIO_TypeDef * Led2_GPIOx, uint16_t Led2_GPIO_pin,
		GPIO_TypeDef * Led3_GPIOx, uint16_t Led3_GPIO_pin,
		GPIO_TypeDef * Led4_GPIOx, uint16_t Led4_GPIO_pin)
{
	status_led->Led1_GPIOx = Led1_GPIOx;
	status_led->Led1_GPIO_pin = Led1_GPIO_pin;

	status_led->Led2_GPIOx = Led2_GPIOx;
	status_led->Led2_GPIO_pin = Led2_GPIO_pin;

	status_led->Led3_GPIOx = Led3_GPIOx;
	status_led->Led3_GPIO_pin = Led3_GPIO_pin;

	status_led->Led4_GPIOx = Led4_GPIOx;
	status_led->Led4_GPIO_pin = Led4_GPIO_pin;

}


// led 1 -- kırmızı
// led 2 -- yeşil
// led 3 -- 2. yeşil
// led 4 -- sarı
void status_led_process(Status_led_s* status_led, Status_led_mode_e Mode){
	switch (Mode) {
		case LED_STOP :
			HAL_GPIO_WritePin(status_led->Led1_GPIOx, status_led->Led1_GPIO_pin, 1);
			HAL_Delay(200);
			HAL_GPIO_WritePin(status_led->Led1_GPIOx, status_led->Led1_GPIO_pin, 0);
			HAL_Delay(200);
			break;
		case LED_START :
			HAL_GPIO_WritePin(status_led->Led2_GPIOx, status_led->Led2_GPIO_pin, 1);
			HAL_Delay(200);
			HAL_GPIO_WritePin(status_led->Led2_GPIOx, status_led->Led2_GPIO_pin, 0);
			HAL_Delay(200);
			break;
		case LED_OKAY :
			HAL_GPIO_WritePin(status_led->Led3_GPIOx, status_led->Led3_GPIO_pin, 1);
			HAL_Delay(200);
			HAL_GPIO_WritePin(status_led->Led3_GPIOx, status_led->Led3_GPIO_pin, 0);
			HAL_Delay(200);
			break;
		case LED_GO :
			HAL_GPIO_WritePin(status_led->Led2_GPIOx, status_led->Led2_GPIO_pin, 0);
			HAL_GPIO_WritePin(status_led->Led1_GPIOx, status_led->Led1_GPIO_pin, 1);
			HAL_Delay(200);
			HAL_GPIO_WritePin(status_led->Led1_GPIOx, status_led->Led1_GPIO_pin, 0);
			HAL_GPIO_WritePin(status_led->Led4_GPIOx, status_led->Led4_GPIO_pin, 1);
			HAL_Delay(200);
			HAL_GPIO_WritePin(status_led->Led4_GPIOx, status_led->Led4_GPIO_pin, 0);
			HAL_GPIO_WritePin(status_led->Led2_GPIOx, status_led->Led2_GPIO_pin, 1);
			HAL_Delay(200);
			break;
		case LED_STAY :
			HAL_GPIO_WritePin(status_led->Led4_GPIOx, status_led->Led4_GPIO_pin, 1);
			HAL_Delay(200);
			HAL_GPIO_WritePin(status_led->Led4_GPIOx, status_led->Led4_GPIO_pin, 0);
			HAL_Delay(200);
			break;

		default:
			HAL_GPIO_WritePin(status_led->Led1_GPIOx, status_led->Led1_GPIO_pin, 1);
			HAL_Delay(100);
			HAL_GPIO_WritePin(status_led->Led1_GPIOx, status_led->Led1_GPIO_pin, 0);
			HAL_Delay(100);
			break;
	}
}

/*
 * LIS302DL_lib.c
 *
 *  Created on: Dec 10, 2024
 *      Author: ilbeyli
 */


#include "LIS302DL_lib.h"



#define CS_ENABLE()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET)
#define CS_DISABLE()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET)

void LIS302DL_init(LIS302DL_Mode Mode) {
    LIS302DL_WriteReg(LIS302DL_Ctrl_Reg1, Mode);
}

void LIS302DL_WriteReg(uint8_t reg, uint8_t data){
	uint8_t SendData[2] = {reg,data};
	CS_ENABLE();
	HAL_SPI_Transmit(&hspi1, SendData, 2, HAL_MAX_DELAY);
	CS_DISABLE();
}

uint8_t LIS302DL_ReadReg(uint8_t reg){
	uint8_t SendData = reg | 0x80;
	uint8_t RecvData = 0;

	CS_ENABLE();
	HAL_SPI_Transmit(&hspi1, &SendData, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive(&hspi1, &RecvData, 1, HAL_MAX_DELAY);
	CS_DISABLE();
	return RecvData;
}


void LIS302DL_ReadXYZ(int8_t *x, int8_t *y, int8_t *z){
	*x = (int8_t)LIS302DL_ReadReg(LIS302DL_OutX);
	*y = (int8_t)LIS302DL_ReadReg(LIS302DL_OutY);
	*z = (int8_t)LIS302DL_ReadReg(LIS302DL_OutZ);
}

void calculateAngles(int8_t x, int8_t y, int8_t z, float *pitch, float *roll) {
    *pitch = atan2(y, sqrt(x * x + z * z)) * 180.0 / 3.14159;
    *roll = atan2(x, sqrt(y * y + z * z)) * 180.0 / 3.14159;
}

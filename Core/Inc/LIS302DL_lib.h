/*
 * LIS302DL_lib.h
 *
 *  Created on: Dec 10, 2024
 *      Author: ilbeyli
 */

#ifndef INC_LIS302DL_LIB_H_
#define INC_LIS302DL_LIB_H_


#include "stm32f4xx.h"
#include "stdint.h"
#include "stdio.h"

#define LIS302DL_Who_Am_I 0x0F
#define LIS302DL_Ctrl_Reg1 0x20
#define LIS302DL_OutX 0x29
#define LIS302DL_OutY 0x2B
#define LIS302DL_OutZ 0x2D

extern SPI_HandleTypeDef hspi1;

typedef enum {
    Fast_Mode = 0xC7,
    Normal_Mode = 0x47
} LIS302DL_Mode;

void LIS302DL_init(LIS302DL_Mode Mode);
uint8_t LIS302DL_ReadReg(uint8_t reg);
void LIS302DL_WriteReg(uint8_t reg, uint8_t data);
void LIS302DL_ReadXYZ(int8_t *x, int8_t *y, int8_t *z);
void calculateAngles(int8_t x, int8_t y, int8_t z, float *pitch, float *roll);



#endif /* INC_LIS302DL_LIB_H_ */

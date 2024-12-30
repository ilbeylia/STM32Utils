/*
 * lcd_i2c.h
 *
 *  Created on: Dec 30, 2024
 *      Author: ilbeyli
 */

#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_

#include "stm32f4xx_hal.h"

#define LCD_I2C_ADDR (0x27 << 1)

// LCD kontrol bayrakları
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00
#define LCD_ENABLE_BIT 0x04


#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80


void LCD_Init(I2C_HandleTypeDef *hi2c);
void LCD_SendString(char *str);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Clear(void);
void LCD_SendChar(char c);

#endif /* INC_LCD_I2C_H_ */

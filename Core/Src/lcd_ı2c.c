/*
 * lcd_ı2c.c
 *
 *  Created on: Dec 30, 2024
 *      Author: ilbeyli
 */


#include "lcd_i2c.h"

static I2C_HandleTypeDef *lcd_i2c;
static uint8_t backlight_state = LCD_BACKLIGHT;

// I2C üzerinden veri gönderme
static void LCD_Write(uint8_t data) {
    HAL_I2C_Master_Transmit(lcd_i2c, LCD_I2C_ADDR, &data, 1, HAL_MAX_DELAY);
    HAL_Delay(1);
}

// Komut gönderme
static void LCD_WriteCommand(uint8_t cmd) {
    uint8_t data_u = (cmd & 0xF0) | backlight_state;
    uint8_t data_l = ((cmd << 4) & 0xF0) | backlight_state;
    uint8_t data[4] = {data_u | LCD_ENABLE_BIT, data_u, data_l | LCD_ENABLE_BIT, data_l};
    HAL_I2C_Master_Transmit(lcd_i2c, LCD_I2C_ADDR, data, 4, HAL_MAX_DELAY);
    HAL_Delay(1);
}

// Veri gönderme
static void LCD_WriteData(uint8_t data) {
    uint8_t data_u = (data & 0xF0) | backlight_state | 0x01;
    uint8_t data_l = ((data << 4) & 0xF0) | backlight_state | 0x01;
    uint8_t data_arr[4] = {data_u | LCD_ENABLE_BIT, data_u, data_l | LCD_ENABLE_BIT, data_l};
    HAL_I2C_Master_Transmit(lcd_i2c, LCD_I2C_ADDR, data_arr, 4, HAL_MAX_DELAY);
    HAL_Delay(1);
}

// LCD başlatma
void LCD_Init(I2C_HandleTypeDef *hi2c) {
    lcd_i2c = hi2c;

    HAL_Delay(50);  // wait for >40ms
      lcd_send_cmd (0x30);
      HAL_Delay(5);  // wait for >4.1ms
      lcd_send_cmd (0x30);
      HAL_Delay(1);  // wait for >100us
      lcd_send_cmd (0x30);
      HAL_Delay(10);
      lcd_send_cmd (0x20);  // 4bit mode
      HAL_Delay(10);

      // display initialisation
      lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
      HAL_Delay(1);
      lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
      HAL_Delay(1);
      lcd_send_cmd (0x01);  // clear display
      HAL_Delay(2);
      lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
      HAL_Delay(1);
      lcd_send_cmd (0x0C);
}

// İmleci ayarla
void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t addr = (row == 0) ? 0x80 + col : 0xC0 + col;
    LCD_WriteCommand(addr);
}

// Ekranı temizle
void LCD_Clear(void) {
    LCD_WriteCommand(LCD_CLEAR_DISPLAY);
    HAL_Delay(2);
}

// String gönder
void LCD_SendString(char *str) {
    while (*str) {
        LCD_SendChar(*str++);
    }
}

// Karakter gönder
void LCD_SendChar(char c) {
    LCD_WriteData(c);
}

// Lcd test
void LCD_Test(){
    LCD_Clear();
    LCD_SetCursor(2, 0);
    LCD_SendString("Merhaba");
    LCD_SetCursor(1, 0);
    LCD_SendString("STM32F4!");
}

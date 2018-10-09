#ifndef LCD_H
#define LCD_H

#include "stm32f10x_conf.h"

void LCD_DATA_DIR_OUT(void);
void Delay(__IO uint32_t nCount);
void Lcd_Write_Command(uint8_t cmd);
void Lcd_Write_Data(uint8_t ch);
void Lcd_Init(void);
void Lcd_Cursor(uint8_t column, uint8_t line);
void lcd_print (char *string);
void lcd_clear (void);

void tes_pin(void);

void Example_LCD1602(void);
 
#endif

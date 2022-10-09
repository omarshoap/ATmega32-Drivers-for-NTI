/*
 * LCD.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_


#define _4_BIT_MODE     4
#define _8_BIT_MODE     8

void LCD_INIT();
void LCD_WRITE_CMD(u8);
void LCD_WRITE_CHR(u8);
void LCD_WRITE_STR(s8*);
void LCD_WRITE_INT(u32);
void LCD_CLEAR();
#endif /* HAL_LCD_LCD_H_ */

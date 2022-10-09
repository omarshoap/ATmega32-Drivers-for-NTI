/*
 * LCD_CFG.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_
/*LCD_MODES : OPTIONS -> _4_BIT_MODE , _8_BIT_MODE */
#define LCD_MODE               _8_BIT_MODE

#define LCD_DATA_PIN_1         4
#define LCD_DATA_PIN_2         5
#define LCD_DATA_PIN_3         6
#define LCD_DATA_PIN_4         7

#define LCD_ENABLE_PORT        DIO_PORTC
#define LCD_ENABLE_PIN         1

#define LCD_RS_PORT            DIO_PORTC
#define LCD_RS_PIN             0

#define LCD_DATA_REGESTER      DIO_PORTD

#endif /* HAL_LCD_LCD_CFG_H_ */

/*
 * LCD.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


/*
 * LCD.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "LCD_CFG.h"
#include "DIO.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_INIT()
{
	DIO_PIN_DIRECTION(LCD_ENABLE_PORT,LCD_ENABLE_PIN,OUTPUT);
	DIO_PIN_DIRECTION(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
    #if LCD_MODE == _4_BIT_MODE
	DIO_PIN_DIRECTION(LCD_DATA_REGESTER,LCD_DATA_PIN_1,OUTPUT);
	DIO_PIN_DIRECTION(LCD_DATA_REGESTER,LCD_DATA_PIN_2,OUTPUT);
	DIO_PIN_DIRECTION(LCD_DATA_REGESTER,LCD_DATA_PIN_3,OUTPUT);
	DIO_PIN_DIRECTION(LCD_DATA_REGESTER,LCD_DATA_PIN_4,OUTPUT);
    _delay_ms(100);
    LCD_WRITE_CMD(0X33);     /* TO ACTIVATE 4-BIT MODE */
    LCD_WRITE_CMD(0X32);
    LCD_WRITE_CMD(0X28);
    #elif LCD_MODE == _8_BIT_MODE
    DIO_PORT_DIRECTION(LCD_DATA_REGESTER,0xff);
    _delay_ms(100);
    LCD_WRITE_CMD(0X38);
    #endif
    LCD_WRITE_CMD(0X0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
    LCD_WRITE_CMD(0X01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
    LCD_WRITE_CMD(0X06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
    LCD_WRITE_CMD(0X02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
}



void LCD_WRITE_CMD(u8 command)
{
	DIO_PIN_WRITE(LCD_RS_PORT,LCD_RS_PIN,LOW);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
    #if LCD_MODE == _8_BIT_MODE
	DIO_PORT_WRITE(LCD_DATA_REGESTER,command);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
    #elif LCD_MODE == _4_BIT_MODE
	/***SEND_HIGH_PART***/
	DIO_PORT_WRITE(LCD_DATA_REGESTER,(command & 0xf0) | (LCD_DATA_REGESTER & 0x0f));
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	/***SEND_LOW_PART***/
	DIO_PORT_WRITE(LCD_DATA_REGESTER,(command << 4) | (LCD_DATA_REGESTER & 0x0f));
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
    #endif
	_delay_ms(5);
}

void LCD_WRITE_CHR(u8 character)
{
	DIO_PIN_WRITE(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
    #if LCD_MODE == _8_BIT_MODE
	DIO_PORT_WRITE(LCD_DATA_REGESTER,character);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
    #elif LCD_MODE == _4_BIT_MODE
	/***SEND_HIGH_PART***/
	DIO_PORT_WRITE(LCD_DATA_REGESTER,(character & 0xf0) | (LCD_DATA_REGESTER & 0x0f));
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	/***SEND_LOW_PART***/
	DIO_PORT_WRITE(LCD_DATA_REGESTER,(character << 4) | (LCD_DATA_REGESTER & 0x0f));
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1);
	DIO_PIN_WRITE(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
    #endif
	_delay_ms(5);
}

void LCD_WRITE_STR(s8*p)
{
	u8 i = 0;
	while(p[i] != '\0')
	{
	LCD_WRITE_CHR(p[i]);
	i++;
	}

}

void LCD_WRITE_INT(u32 num)
{

	u32 rem = 0;
	u8 arr [17];
	s8 i = 0;
	while(num != 0)
	{
		rem = num % 10;
		arr[i] = rem + 48;
		i++;
		num = num / 10;
	}
	i--;
	while(i > -1)
	{
	    LCD_WRITE_CHR(arr[i]);
	    i--;
	}

}

void LCD_CLEAR()
{
	LCD_WRITE_CMD(0x01);
}

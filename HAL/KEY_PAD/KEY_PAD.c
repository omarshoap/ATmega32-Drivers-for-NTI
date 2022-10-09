/*
 * KEY_PAD.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "KEY_PAD_CFG.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u8 arr[4][4] = { {'7','8','9','/'},
		         {'4','5','6','*'},
	         	 {'1','2','3','-'},
				 {'c','0','=','+'},
               };


void KEY_PAD_INIT()
{
	/*_ALL_ROWS_ARE_OUTPUTS_*/
	DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_R0_PIN,OUTPUT);
	DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_R1_PIN,OUTPUT);
	DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_R2_PIN,OUTPUT);
	DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_R3_PIN,OUTPUT);
	/*_ALL_OUTPUTS_ARE_HIGH_*/
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_R0_PIN,HIGH);
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_R1_PIN,HIGH);
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_R2_PIN,HIGH);
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_R3_PIN,HIGH);
	/*_ALL_COULMNS_ARE_INPUTS_*/
    DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_C0_PIN,INPUT);
    DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_C1_PIN,INPUT);
    DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_C2_PIN,INPUT);
    DIO_PIN_DIRECTION(KEY_PAD_PORT,KEY_PAD_C3_PIN,INPUT);
	/*_ENABLE_PULL_UP_RES_FOR_ALL_INPUTS_*/
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_C0_PIN,HIGH);
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_C1_PIN,HIGH);
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_C2_PIN,HIGH);
    DIO_PIN_WRITE(KEY_PAD_PORT,KEY_PAD_C3_PIN,HIGH);
}
u8 KEY_PAD_READ()
{
	u8 temp = 1;
	u8 value = 0;
	u8 r,c;

	for(r=0;r<=3;r++)
	{
	    DIO_PIN_WRITE(KEY_PAD_PORT,r,LOW);
	    for(c=0;c<=3;c++)
	    {
	        temp = DIO_PIN_READ(KEY_PAD_PORT,c+4);
	        if(temp == 0)
	        {
	        	_delay_ms(150);
	        	temp = DIO_PIN_READ(KEY_PAD_PORT,c+4);
	        	 if(temp == 0)
	        	 {
	        	value = arr[r][c];
	        	 }
	        }

	    }
	    DIO_PIN_WRITE(KEY_PAD_PORT,r,HIGH);
	}
	return value;
}

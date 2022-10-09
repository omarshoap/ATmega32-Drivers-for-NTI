/*
 * TEMP_S.c

 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "TEMP_S_CFG.h"
#include "ADC.h"

void TEMP_S_INIT(void)
{
	ADC_INIT();
}

u8 TEMP_S_READ(void)
{
	u16 value;
	value = ADC_READ(TEMP_S_PIN);
	u8 temp;
	temp = ( value * 500 ) /1023;
	return temp ;
}

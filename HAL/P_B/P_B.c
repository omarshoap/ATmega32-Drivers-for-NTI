/*
 * P_B.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "P_B_CFG.h"
#include "DIO.h"

void P_B_INIT(void)
{
	DIO_PIN_DIRECTION(P_B_PORT,P_B_PIN,INPUT);
	DIO_PIN_WRITE(P_B_PORT,P_B_PIN,HIGH);
}
u8 P_B_READ(void)
{
	u8 value = 0;
	value = DIO_PIN_READ(P_B_PORT,P_B_PIN);
	return value;
}

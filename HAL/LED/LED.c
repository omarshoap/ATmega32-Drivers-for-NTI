/*
 * LED.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


/*
 * LED.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "LED_CFG.h"
#include "DIO.h"

void LED_INIT(void)
{

	DIO_PIN_DIRECTION(LED_PORT,LED_PIN,OUTPUT);

}
void LED_ON(void)
{

	DIO_PIN_WRITE(LED_PORT,LED_PIN,HIGH);

}
void LED_OFF(void)
{

	DIO_PIN_WRITE(LED_PORT,LED_PIN,LOW);

}
void LED_TOG(void)
{
	DIO_PIN_TOG(LED_PORT,LED_PIN);
}

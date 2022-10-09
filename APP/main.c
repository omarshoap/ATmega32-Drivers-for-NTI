/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "DIO.h"
#include "LED.h"
#include "LCD.h"
#include "S_SEG.h"
#include "P_B.h"
#include "KEY_PAD.h"
#include "EXT_INT.h"
#include "ADC.h"
#include "TEMP_S.h"
#include "TIMER.h"
#include "REG.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

u8 x;

int main(void)
{
	LCD_INIT();
	 ADC_INIT();
	 u16 y ;
	 while(1)
	 {
		 y= ADC_READ(ADC_CHANNEL_0);
		 LCD_WRITE_INT(y);
		 _delay_ms(100);
		 LCD_CLEAR();
		 _delay_ms(300);

	 }

    return 0;
}







/*
 extern u32 num_of_ov;
extern u8  rem_ticks;

int main(void)
{
	PWM_0_INIT();
	PWM_0_SET_DUTY_CYCLE(0);
	PWM_0_START();
    while(1)
    {

    }
    return 0;
}




ISR(TIMER0_OVF_vect)
{
	static u32 x;
	x++;
	if(x == num_of_ov)
	{
		LED_TOG();
		x = 0;
		TCNT0      = 255 - rem_ticks;
	}
}
ISR(TIMER0_COMP_vect)
{

}
ISR(TIMER1_COMPA_vect)
{
LED_ON();
}

*/

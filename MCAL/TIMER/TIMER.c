/*
 * TIMER.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "TIMER_CFG.h"
#include "TIMER.h"
#include "REG.h"
#include "BIT_MATH.h"
u32 num_of_ov;
u8  rem_ticks;
u32 timer_0_num_of_cm;
u32 timer_1_num_of_cm;



void TIMER_0_INIT(void)
{
	#if TIMER_0_MODE == NORMAL
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
    #elif TIMER_0_MODE == CTC
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
    #elif TIMER_0_MODE == PWM
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
    #endif

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);
}
void TIMER_0_SET_TIME(u32 desired_time)
{
    #if TIMER_0_MODE == NORMAL
	u8  tick_time  = 1024 / 8;      // result will be in micro second
	u32 total_ticks = desired_time*1000 / tick_time;
	    num_of_ov  = total_ticks / 256;
	    rem_ticks  = total_ticks % 256;
	if(rem_ticks != 0)
	{
		TCNT0      = 255 - rem_ticks;
		num_of_ov++;
	}
    #elif TIMER_0_MODE == CTC
	u8  tick_time  = 1024 / 8;      // result will be in micro second
	u32 total_ticks = desired_time*1000 / tick_time;
    OCR0 = 250;
	timer_0_num_of_cm  = total_ticks / 62;
    #endif
}
void TIMER_0_START(void)
{
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
}
void TIMER_0_STOP(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void TIMER_1_INIT(void)
{
	/*to select ctc mode in timer 1*/
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

	/*_to enable global int and timer 1 int*/
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,4);
}
void TIMER_1_SET_TIME(u32 desired_time)
{
	if (desired_time <= 8000)
	{
		u8  tick_time  = 1024 / 8;      // result will be in micro second
		u32 total_ticks = desired_time*1000 / tick_time;
		OCR1A = total_ticks - 1;

	}
}
void TIMER_1_START(void)
{
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}
void TIMER_1_STOP(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void PWM_0_INIT(void)
{
	SET_BIT(DDRB,3);
	/* to select fast pwm mode*/
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/*to select non inverted mode*/
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
}
void PWM_0_SET_DUTY_CYCLE(u8 duty_cycle)
{
	if(duty_cycle <= 100)
	{
		OCR0 = (( duty_cycle * 256 ) / 100 ) - 1;
	}
}
void PWM_0_START(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
}


void P_C_INIT(void){
	/*set direction of OC) to be output*/

	/* enable phase correct mode*/
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/*set on up-counting non-inverting */
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	/*CMP value */
	OCR0 = 200 ;
}
void P_C_START(void){
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
}
void P_C_D(void){
	SET_BIT(DDRB,3);
}




void PWM_1_INIT(void){
	/*set direction of OC1A to be output*/
	SET_BIT(DDRD,5);

	/*to select fast PWM (top is ICR1) mode (14) in timer 1*/
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);

	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	/*non-inverting*/
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);

	/* to make top = 20msec*/
	ICR1 = 19999 ;

}
void PWM_1_SET_TIME(u16 time)
{	/* time in microsecond*/
	OCR1A = time ;
}
void PWM_1_START(void){
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);

}
void PWM_1_STOP(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}





/*
ISR(INT0_vect)

{
	LED_TOG();
}
*/

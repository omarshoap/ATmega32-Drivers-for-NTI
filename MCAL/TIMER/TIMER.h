/*
 * TIMER.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "STD_TYPES.h"

#define NORMAL          0
#define CTC             1
#define PWM             2
#define FAST_PWM        3


void TIMER_0_INIT(void);
void TIMER_0_SET_TIME(u32);
void TIMER_0_START(void);
void TIMER_0_STOP(void);

void TIMER_1_INIT(void);
void TIMER_1_SET_TIME(u32);
void TIMER_1_START(void);
void TIMER_1_STOP(void);

void PWM_0_INIT(void);
void PWM_0_SET_DUTY_CYCLE(u8);
void PWM_0_START(void);


void PWM_1_INIT(void);
void PWM_1_SET_TIME(u16 time);
void PWM_1_START(void)	;
void PWM_1_STOP(void);


#endif /* MCAL_TIMER_TIMER_H_ */

/*
 * ADC.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include "STD_TYPES.h"

#define AVCC             0
#define AREF             1
#define _2V              2

#define R_ADJUSTMENT     0
#define L_ADJUSTMENT     1

#define _64              0
#define _128             1

#define ADC_CHANNEL_0    0
#define ADC_CHANNEL_1    1
#define ADC_CHANNEL_2    2
#define ADC_CHANNEL_3    3
#define ADC_CHANNEL_4    4
#define ADC_CHANNEL_5    5
#define ADC_CHANNEL_6    6
#define ADC_CHANNEL_7    7


void ADC_INIT(void);
u16  ADC_READ(u8);

#endif /* MCAL_ADC_ADC_H_ */

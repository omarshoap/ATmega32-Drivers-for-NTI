/*

 * ADC.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "ADC_CFG.h"
#include "ADC.h"
#include "BIT_MATH.h"
#include "REG.h"

void ADC_INIT(void)
{
#if ADC_VREF  ==  AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif  ADC_VREF  ==  AREF
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_VREF  ==  _2V
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#endif
#if ADC_ADJUSTMENT == R_ADJUSTMENT
	CLR_BIT(ADMUX,5);
#elif ADC_ADJUSTMENT == L_ADJUSTMENT
	SET_BIT(ADMUX,5);
#endif
	/*_TO_CHOOSE_AUTO_TRIGGER_MODE_*/
	SET_BIT(ADCSRA,5);
#if ADC_PRESCALER   == _64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRESCALER == _128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#endif
	/*_TO_ENABLE_ADC_*/
	SET_BIT(ADCSRA,7);
}
u16  ADC_READ(u8 channel)
{
	switch(channel)
	{
	case 0 :
		CLR_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case 1:
		SET_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case 2:
		CLR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case 3:
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case 4:
		CLR_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	case 5:
		SET_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	case 6:
		CLR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	case 7:
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	default:
		break;
	}
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);


	/*_TO_START_CONVERSION_*/
	SET_BIT(ADCSRA,6);
	u16 x;
	while (GET_BIT(ADCSRA,4) == 0)
	{

	}
	x = ADC_DATA;
	return x;
}

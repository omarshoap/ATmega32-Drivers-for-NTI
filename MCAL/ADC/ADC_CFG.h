/*
 * ADC_CFG.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/*_SELECT_VREF_*/
/*_OPTIONS -> [ AVCC ] , [ AREF ] , [ _2V ] _*/
#define ADC_VREF                 AVCC
/*_SELECT_ADJUSTMENT_*/
/*_OPTIONS -> [ R_ADJUSTMENT ] , [ L_ADJUSTMENT ] _*/
#define ADC_ADJUSTMENT          R_ADJUSTMENT
/*_SELECT_PRESCALER_*/
/*_OPTIONS -> [ _128 ] , [ _64 ] _*/
#define ADC_PRESCALER          _64
#endif /* MCAL_ADC_ADC_CFG_H_ */

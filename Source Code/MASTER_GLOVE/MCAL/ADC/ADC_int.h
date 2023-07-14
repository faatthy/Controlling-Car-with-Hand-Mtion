/*
 * ADC_int.h
 *
 *  Created on: Oct 7, 2022
 *      Author: fathy
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

void ADC_voidInit(void);

void ADC_voidSelectChannel(u8 Copy_u8ChannelID);

void ADC_voidStartConversion(void);

void ADC_voidEnableAutoTrigger(u8 Copy_u8TiggerSource);

void ADC_voidDisableAutoTrigger(void);

void ADC_voidRead(u16 * Copy_u16ADCValue);

void ADC_voidReadHigh(u8 * Copy_u8ADCValue);

void ADC_voidPollingRead(u16 * Copy_u16ADCValue);

void ADC_voidCallBack(void (* Copy_pFunAppFun)(void));



void ADC_voidEnableInterrupt(void);
//void ADC_voidDisableInterrupt(void);



#endif /* MCAL_ADC_ADC_INT_H_ */

/*
 * ADC_priv.h
 *
 *  Created on: Oct 7, 2022
 *      Author: fathy
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define PRES_64 		21

#define AVCC_REF		54
#define AREF_REF		98
#define INTRNL_REF		65

#define LEFT_ADJUST		02
#define RIGHT_ADJUST	20

#define INTERRUPT		53
#define POLLING			32

#define SINGLE			73
#define EXTI0			19


#define ADMUX			*((volatile u8 *)0x27)
#define ADCSRA			*((volatile u8 *)0x26)
#define ADCL			*((volatile u8 *)0x24)
#define ADCH			*((volatile u8 *)0x25)

#define SFIOR			*((volatile u8 *)0x50)


#endif /* MCAL_ADC_ADC_PRIV_H_ */

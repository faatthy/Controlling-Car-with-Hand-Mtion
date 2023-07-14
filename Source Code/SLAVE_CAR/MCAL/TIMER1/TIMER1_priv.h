/*
 * TIMER1_priv.h
 *
 *  Created on: Feb 3, 2023
 *      Author: fathy
 */

#ifndef MCAL_TIMER1_TIMER1_PRIV_H_
#define MCAL_TIMER1_TIMER1_PRIV_H_

#define F_CPU									16000000UL

#define NO_CLK									0
#define PRESCLNG_1								1
#define PRESCLNG_8								8
#define PRESCLNG_64								64
#define PRESCLNG_256							256
#define PRESCLNG_1024							1024
#define FALLING          						10
#define RISING       							15
#define NORMAL									1
#define CTC										2
#define FAST_PWM								1
#define PHASE_CORRECT							2
#define NON_INVERTED							1
#define INVERTED								2


#define ICR1		(*(volatile u16*)0x46)
#define ICR1L		(*(volatile u8*)0x46)
#define ICR1H		(*(volatile u8*)0x47)

#define OCR1A		(*(volatile u16*)0x4A)
#define OCR1AL		(*(volatile u8*)0x4A)
#define OCR1AH		(*(volatile u8*)0x4B)
#define OCR1B		(*(volatile u16*)0x48)
#define OCR1BL		(*(volatile u8*)0x48)
#define OCR1BH 		(*(volatile u8*)0x49)


#define TCNT1		(*(volatile u16*)0x4C)
#define TCNT1L		(*(volatile u8*)0x4C)
#define TCNT1H		(*(volatile u8*)0x4D)

#define TCCR1		(*(volatile u16*)0x4E)
#define TCCR1A		(*(volatile u8*)0x4F)
#define TCCR1B		(*(volatile u8*)0x4E)

#define  CRYSTAL_FREQUENCY   16
#endif /* MCAL_TIMER1_TIMER1_PRIV_H_ */

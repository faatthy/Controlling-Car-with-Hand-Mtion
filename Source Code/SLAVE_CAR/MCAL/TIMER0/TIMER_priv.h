/*
 * TIMER_priv.h
 *
 *  Created on: Oct 8, 2022
 *      Author: fathy
 */

#ifndef MCAL_TIMER0_TIMER_PRIV_H_
#define MCAL_TIMER0_TIMER_PRIV_H_
#define PRES_0				0
#define PRES_1				1
#define PRES_8				8
#define PRES_64				64
#define PRES_256			256
#define PRES_1024			1024
#define PRES_FALL			7
#define PRES_RISE			3

#define NORMAL_MODE				36
#define CTC_MODE                41
#define FAST_PWM_MODE           50
#define PHASE_PWM_MODE          51


/******* CTC MODES  ************/
#define DISCONNECTED		65
#define TOGGLE				20
#define CLEAR				50
#define SET					90
/********PWM MODES  *******/
#define  INVERTED       0
#define  NON_INVERTED   1

#define TIMSK	*((volatile u8*) 0x59)

/*TIFR*/
#define TIFR	*((volatile u8*) 0x58)

/*TCCR*/
#define TCCR0	*((volatile u8*) 0x53)

/*TCNT*/
#define TCNT0	*((volatile u8*) 0x52)


/*OCR*/
#define OCR0	*((volatile u8*) 0x5c)

#endif /* MCAL_TIMER0_TIMER_PRIV_H_ */

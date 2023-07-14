/*
 * TIMER_int.h
 *
 *  Created on: Oct 8, 2022
 *      Author: fathy
 */

#ifndef MCAL_TIMER0_TIMER0_INT_H_
#define MCAL_TIMER0_TIMER0_INT_H_

void TIMER0_voidInit(void);
void TIMER0_voidStart(void);
void TIMER0_voidDelay(u16 copy_u16millisec);





void TIMER0_voidCallBack(void (*fun)(void),u8 timerID ,u8 mode);
void PWM0_voidInit(void);
void PWM0_voidSetDuty(u8 Copy_u8Duty);
void PWM0_voidStart(void);

void TIMER0_voidStop(void);
void PWM0_voidStop(void);





#endif /* MCAL_TIMER0_TIMER0_INT_H_ */

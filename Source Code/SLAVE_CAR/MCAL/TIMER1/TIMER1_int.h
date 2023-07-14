/*
 * TIMER1_int.h
 *
 *  Created on: Feb 3, 2023
 *      Author: fathy
 */

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

void Pwm1_voidInit(void);
void Pwm1_voidSetOCR1A(u16 Local_u16DutyCycle);
void Pwm1_voidSetOCR1B(u16 Local_u16DutyCycle);
void Pwm1_voidSetFrequency(u16 Local_u16Frequency);
void Pwm1_voidStart(void);
void Pwm1_voidStop(void);




#endif /* MCAL_TIMER1_TIMER1_INT_H_ */

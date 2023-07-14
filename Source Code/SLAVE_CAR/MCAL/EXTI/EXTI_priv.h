/*
 * EXTI_priv.h
 *
 *  Created on: Jan 30, 2023
 *      Author: fathy
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define EVENT_TRIGGERED				65
#define POLLING						13

#define LOW_LEVEL					32
#define ANY_CHANGE					34
#define RISING						73
#define FALLING						10

#define INT0 						0
#define INT1 						1
#define INT2 						2

#define MCUCR			*((volatile u8*)0x55)
#define MCUCSR			*((volatile u8*)0x54)
#define GICR			*((volatile u8*)0x5B)
#define GIFR			*((volatile u8*)0x5A)



#endif /* MCAL_EXTI_EXTI_PRIV_H_ */

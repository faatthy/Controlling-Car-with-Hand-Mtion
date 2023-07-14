/*
 * EXTI_int.h
 *
 *  Created on: Jan 30, 2023
 *      Author: fathy
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

void EXTI_voidInit(void);

void EXTI_voidSetSenseLevel(u8 Copy_u8IntPinNum , u8 Copy_u8SenseLevel);

void EXTI_voidEnableInterrupt(u8 Copy_u8IntPinNum);

void EXTI_voidDisableInterrupt(u8 Copy_u8IntPinNum);

void EXTI_voidCallBack(void(*Copy_pFunAppFun)(void) , u8 Copy_u8IntPinNum);


#define INT0 						0
#define INT1 						1
#define INT2 						2

#define LOW_LEVEL					32
#define ANY_CHANGE					34
#define RISING						73
#define FALLING						10

#endif /* MCAL_EXTI_EXTI_INT_H_ */

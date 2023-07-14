/*
 * DIO_int.h
 *
 *  Created on: Jan 28, 2023
 *      Author: fathy
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
void DIO_voidInit(void);

void DIO_voidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction);

void DIO_voidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value);

void DIO_voidTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID);

void DIO_voidGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 * Copy_pu8Value);
u8 DIO_u8GetValue(u8 Copy_u8GroupID, u8 Copy_u8PinID);
/**** defined groups *****/
#define DIO_u8GROUP_A				0
#define DIO_u8GROUP_B				1
#define DIO_u8GROUP_C				2
#define DIO_u8GROUP_D				3
/******** drefined nember of pines********/
#define DIO_u8PIN0					0
#define DIO_u8PIN1					1
#define DIO_u8PIN2					2
#define DIO_u8PIN3					3
#define DIO_u8PIN4					4
#define DIO_u8PIN5					5
#define DIO_u8PIN6					6
#define DIO_u8PIN7					7
/***** define states of pin*********/
#define DIO_u8LOW					0
#define DIO_u8HIGH					1

/******* define states of button *******/
#define DIO_u8FLOAT					0
#define DIO_u8PULL_UP				1
/******* define states of direction of pin****/
#define DIO_u8INPUT					0
#define DIO_u8OUTPUT				1
#define DIO_u8BIT_MASK				1
#endif /* MCAL_DIO_DIO_INT_H_ */

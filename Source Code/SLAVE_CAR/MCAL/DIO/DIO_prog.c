/*
 * DIO_prog.c
 *
 *  Created on: Jan 28, 2023
 *      Author: fathy
 */

#include"../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"
#include"DIO_priv.h"
#include"DIO_conf.h"



void DIO_voidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction){

	if(Copy_u8GroupID<=DIO_u8GROUP_D&&Copy_u8PinID<=DIO_u8PIN7&&Copy_u8Direction<=DIO_u8OUTPUT){
		switch(Copy_u8GroupID){
		case DIO_u8GROUP_A:
			DDRA &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			DDRA |=(Copy_u8Direction<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_B:
			DDRB &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			DDRB |=(Copy_u8Direction<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_C:
			DDRC &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			DDRC |=(Copy_u8Direction<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			DDRD &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			DDRD |=(Copy_u8Direction<<Copy_u8PinID);
			break;

		}

	}

	return ;
}

void DIO_voidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value){

	if(Copy_u8GroupID<=DIO_u8GROUP_D&&Copy_u8PinID<=DIO_u8PIN7&&DIO_u8HIGH){
		switch(Copy_u8GroupID){
		case DIO_u8GROUP_A:
			PORTA &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			PORTA |=(Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_B:
			PORTB &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			PORTB |=(Copy_u8Value<<Copy_u8PinID);
		 break;
		case DIO_u8GROUP_C:
			PORTC &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			PORTC |=(Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			PORTD &=~(DIO_u8BIT_MASK<<Copy_u8PinID);
			PORTD |=(Copy_u8Value<<Copy_u8PinID);
			break;
		}
	}

	return ;
}

void DIO_voidTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID){

	if(Copy_u8GroupID<=DIO_u8GROUP_D&&Copy_u8PinID<=DIO_u8PIN7){
		switch(Copy_u8GroupID){
		case DIO_u8GROUP_A:
			PORTA ^=(DIO_u8BIT_MASK<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_B:
		   PORTB ^=(DIO_u8BIT_MASK<<Copy_u8PinID);
		   break;
		case DIO_u8GROUP_C:
			PORTC ^=(DIO_u8BIT_MASK<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			PORTD ^=(DIO_u8BIT_MASK<<Copy_u8PinID);
			break;

		}
	}

	return ;
}

void DIO_voidGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 * Copy_pu8Value){

	if(Copy_u8GroupID<=DIO_u8GROUP_D&&Copy_u8PinID<=DIO_u8PIN7){
		switch (Copy_u8GroupID){
		case DIO_u8GROUP_A:
			*Copy_pu8Value=(PINA>>Copy_u8PinID)&DIO_u8BIT_MASK;
			break;
		case DIO_u8GROUP_B:
			*Copy_pu8Value=(PINB>>Copy_u8PinID)&DIO_u8BIT_MASK;
			break;
		case DIO_u8GROUP_C:
			*Copy_pu8Value=(PINC>>Copy_u8PinID)&DIO_u8BIT_MASK;
			break;
		case DIO_u8GROUP_D:
			*Copy_pu8Value=(PIND>>Copy_u8PinID)&DIO_u8BIT_MASK;
			break;

		}
	}

	return;
}
u8 DIO_u8GetValue(u8 Copy_u8GroupID, u8 Copy_u8PinID){
	u8 value=0;
	if(Copy_u8GroupID<=DIO_u8GROUP_D&&Copy_u8PinID<=DIO_u8PIN7){
			switch (Copy_u8GroupID){
			case DIO_u8GROUP_A:
				value=(PINA>>Copy_u8PinID)&DIO_u8BIT_MASK;
				break;
			case DIO_u8GROUP_B:
				value=(PINB>>Copy_u8PinID)&DIO_u8BIT_MASK;
				break;
			case DIO_u8GROUP_C:
				value=(PINC>>Copy_u8PinID)&DIO_u8BIT_MASK;
				break;
			case DIO_u8GROUP_D:
				value=(PIND>>Copy_u8PinID)&DIO_u8BIT_MASK;
				break;

			}

}
	return value;
}

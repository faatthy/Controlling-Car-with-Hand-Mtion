/*
 * UART_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: fathy
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"
#include"../DIO/DIO_int.h"
#include"UART_priv.h"
#include "UART_conf.h"
void UART_voidInit(void)
{


#if SPEED_MODE == NORMAL
	UCSRA &=~(1<<1);
#elif SPEED_MODE == DOUBLE
	UCSRA |= (1<<1);
#endif

#if UART_MODE == TRANSCIEVER
	UCSRB |=(3<<3);
#endif

	u8 Local_u8UCSRC=0;
#if DATA_LEN == EIGHT
	Local_u8UCSRC |= (3<<1);
#endif

#if PARITY_STATE == NO_PARITY
	Local_u8UCSRC &= ~ (3<<4);
#endif

#if STOP_STATE == ONE_STOP_BIT
	Local_u8UCSRC &= ~(1<<3);
#endif

#if CLOCK_MODE == ASYCH
	Local_u8UCSRC &=~(1<<6);
#endif
	Local_u8UCSRC |=(1<<7);
	UCSRC = Local_u8UCSRC;

	u16 Local_u16UBRR = BUAD(BAUDRATE);

	Local_u16UBRR &=~(1<<15);

	UBRRL  = (u8)Local_u16UBRR;
	UBRRH  = (u8)(Local_u16UBRR>>8);
	DIO_voidSetPinDirection(DIO_u8GROUP_D , DIO_u8PIN0 , DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8GROUP_D , DIO_u8PIN1 , DIO_u8OUTPUT);

	return;
}

void UART_voidSendChar(u8 Copy_u8Data)
{

	while (!((UCSRA>>UDRE)&1));
	UDR = Copy_u8Data;

	/*
	 * UDR = Copy_u8Data;
	 * while( ! ((UCSRA>>TXC) & 1 ) );
	 * UCSRA |= (1<<TXC);
	 */
	return;
}

void UART_voidRecieveChar(u8 *Copy_pu8Data)
{


	while (!((UCSRA>>RXC)&1));
	*Copy_pu8Data = UDR;

	return;
}

void UART_voidSendString(const u8* Copy_pcData)
{


	while (*Copy_pcData != '\0')
	{
		while (!((UCSRA>>UDRE)&1));
		UDR = *Copy_pcData;
		Copy_pcData++;
	}

	return;
}


void UART_voidRecieveString(char * Copy_pcData)
{


	u8 Local_u8Data=0 , Local_u8Index=0;

	while (1)
	{
		while (!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;

		if (Local_u8Data == '\r' || Local_u8Data == '\n' || Local_u8Data == '\0')
		{
			Copy_pcData[Local_u8Index]='\0';
			break;
		}
		Copy_pcData[Local_u8Index]=Local_u8Data;
		Local_u8Index++;
	}


	return;
}




/*  \r =13 , \n */
/*
ES_t UART_enuRecieveString(char * Copy_pcData)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Data=0 , Local_u8Index=0;
	u8 Local_u8Termination;

	while (!((UCSRA>>RXC)&1));
		Local_u8Termination = UDR;

	while (1)
	{
		while (!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;

		if (Local_u8Data == Local_u8Termination)
		{
			Copy_pcData[Local_u8Index]='\0';
			break;
		}
		Copy_pcData[Local_u8Index]=Local_u8Data;
		Local_u8Index++;
	}


	return Local_enuErrorState;
}*/

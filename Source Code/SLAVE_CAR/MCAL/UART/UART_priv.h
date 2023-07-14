/*
 * UART_priv.h
 *
 *  Created on: Feb 6, 2023
 *      Author: fathy
 */

#ifndef MCAL_UART_UART_PRIV_H_
#define MCAL_UART_UART_PRIV_H_
#define BUAD(BAUD_VAL)		(u16)(F_CPU/(SPEED_MODE * 8 * BAUD_VAL)-1)

#define UDRE		5
#define RXC			7


#define NORMAL		2
#define DOUBLE		1

#define TRANSMITTER 	0
#define RECIEVER		5
#define TRANSCIEVER		9

#define	FIVE			7
#define EIGHT			9

#define NO_PARITY		6
#define ODD_PARITY		7
#define EVEN_PARITY		63

#define ONE_STOP_BIT	86
#define TWO_STOP_BIT	76

#define ASYCH		45
#define SYCH		78


#define UDR			*((u8*)0x2C)
#define UCSRA		*((u8*)0x2B)
#define UCSRB		*((u8*)0x2A)
#define UCSRC		UBRRH
#define UBRRL		*((u8*)0x29)
#define UBRRH		*((u8*)0x40)

#endif /* MCAL_UART_UART_PRIV_H_ */

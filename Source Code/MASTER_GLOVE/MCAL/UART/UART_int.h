/*
 * UART_int.h
 *
 *  Created on: Feb 6, 2023
 *      Author: fathy
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void UART_voidInit(void);

void UART_voidSendChar(u8 Copy_u8Data);

void UART_voidRecieveChar(u8 *Copy_pu8Data);

void UART_voidSendString(const char* Copy_pcData);

void UART_voidRecieveString(char * Copy_pcData);

#endif /* MCAL_UART_UART_INT_H_ */

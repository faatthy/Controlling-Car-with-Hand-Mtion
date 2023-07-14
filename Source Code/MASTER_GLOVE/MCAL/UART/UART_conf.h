/*
 * UART_conf.h
 *
 *  Created on: Feb 6, 2023
 *      Author: fathy
 */

#ifndef MCAL_UART_UART_CONF_H_
#define MCAL_UART_UART_CONF_H_

//				NORMAL  ,   DOUBLE
#define SPEED_MODE		DOUBLE

//				TRANSMITTER , RECIEVER, TRANSCIEVER
#define UART_MODE		TRANSCIEVER

//

#define BAUDRATE		9600ul

#define CLOCK_MODE		ASYCH

// 				FIVE , SIX ,
#define DATA_LEN		EIGHT

#define PARITY_STATE	NO_PARITY

#define STOP_STATE		ONE_STOP_BIT


#endif /* MCAL_UART_UART_CONF_H_ */

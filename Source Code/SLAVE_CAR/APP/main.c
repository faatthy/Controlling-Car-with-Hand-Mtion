/*
 * main.c
 *
 *  Created on: Jun 25, 2023
 *      Author: fathy
 */
#include "../LIBRARY/errorState.h"
#include"../LIBRARY/stdTypes.h"
#include"../MCAL/DIO/DIO_int.h"

#include"../HAL/LCD/LCD_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"

#include "../HAL/ULTRASONIC_SENSOR/ULTRASONIC_SENSOR_int.h"
#include "../HAL/MOTORS_CAR/MOTORS_CAR_int.h"
#include "../MCAL/UART/UART_int.h"
#include<util/delay.h>
#define FORWARD '1'
#define BACKWARD '2'
#define LEFT '3'
#define RIGHT '4'
#define STOP '5'
#define NO_CHANGE '0'
u8 DIRECTION=FORWARD;

int main(){
	LCD_voidInit();
	EXTI_voidInit();
	UART_voidInit();
	ULTRASONIC_SENSOR_voidInit();
	MOTORS_CAR_voidInit();

	LCD_voidWriteString("car is ON ");

	_delay_ms(2000);

	while(1){

		UART_voidRecieveChar(&DIRECTION);
		switch(DIRECTION){
		case FORWARD:
			LCD_voidClearScreen();
			LCD_voidWriteString("FORWARD ");
			MOTORS_CAR_voidForward();
			_delay_ms(1000);
			break;
		case RIGHT:
			LCD_voidClearScreen();
			LCD_voidWriteString("RIGHT");
			MOTORS_CAR_voidRight();
			_delay_ms(1000);
			break;
		case LEFT:
			LCD_voidClearScreen();
			LCD_voidWriteString("LEFT");
			MOTORS_CAR_voidLeft();
			_delay_ms(1000);

			break;
		case BACKWARD:
			LCD_voidClearScreen();
			LCD_voidWriteString("BACKWARD");
			MOTORS_CAR_voidBackward();
			_delay_ms(1000);
			break;
		case STOP:
			LCD_voidClearScreen();
			LCD_voidWriteString("CAR IS OFF");
			MOTORS_CAR_voidStop();
			_delay_ms(1000);
			break;
		default:
			break;

		}

	}

}

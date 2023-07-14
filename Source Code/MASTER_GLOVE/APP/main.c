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
#include "../MCAL/ADC/ADC_int.h"
#include "../HAL/FLEX_SENSOR/FLEX_SENSOR_int.h"
#include "../MCAL/UART/UART_int.h"

#include<util/delay.h>

u16 FINGERS[5];
int main(){

    UART_voidInit();
    _delay_ms(1000);

    FLEX_SENSOR_voidInit();
    while(1){
    	FINGERS[0]=FLEX_SENSOR_voidReadFinger(0);    // THUMP
    	FINGERS[1]=FLEX_SENSOR_voidReadFinger(1);    //INDEX
    	FINGERS[2]=FLEX_SENSOR_voidReadFinger(2);    //MIDDLE
    	FINGERS[3]=FLEX_SENSOR_voidReadFinger(3);    //RING
    	FINGERS[4]=FLEX_SENSOR_voidReadFinger(4);    //PINKY


   // LCD_voidClearScreen();
   u8 DATA= Translate_Results(FINGERS);

   UART_voidSendChar(DATA);
    _delay_ms(1000);
    }
}


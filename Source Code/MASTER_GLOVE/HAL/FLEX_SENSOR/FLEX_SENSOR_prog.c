/*
 * FLEX_SENSOR_prog.c


 *
 *  Created on: Jul 5, 2023
 *      Author: fathy
 */

#include"../../LIBRARY/stdTypes.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "FLEX_SENSOR_priv.h"
#include "FLEX_SENSOR_conf.h"
u16 read;
void FLEX_SENSOR_voidInit(void){
	    ADC_voidInit();
		ADC_voidStartConversion();
		ADC_voidPollingRead(&read);
}
u16 FLEX_SENSOR_voidReadFinger(u8 Copy_u8Finger){
	ADC_voidSelectChannel(Copy_u8Finger);
	ADC_voidStartConversion();
	ADC_voidPollingRead(&read);
	read=(read*500ul)/1024;
	read/=100;
	return read;
}
u8 Translate_Results(u16*Copy_u8Results){
	if ((Copy_u8Results[0] == 4) && (Copy_u8Results[1] == 4) &&(Copy_u8Results[2] == 2)&&(Copy_u8Results[3] == 2) &&(Copy_u8Results[4] == 4)) {
                 return FORWARD;
	    } else if ((Copy_u8Results[0] == 2) && (Copy_u8Results[1] == 4) &&(Copy_u8Results[2] == 2)&&(Copy_u8Results[3] == 2) &&(Copy_u8Results[4] == 2)) {
               return BACKWARD;

	    } else if ((Copy_u8Results[0] == 4) && (Copy_u8Results[1] == 2) &&(Copy_u8Results[2] == 2)&&(Copy_u8Results[3] == 2) &&(Copy_u8Results[4] == 2)) {
                return LEFT;

	    } else if ((Copy_u8Results[0] == 2) && (Copy_u8Results[1] == 4) &&(Copy_u8Results[2] == 2)&&(Copy_u8Results[3] == 2) &&(Copy_u8Results[4] == 4)) {
                 return RIGHT;

	    }
	    else if ((Copy_u8Results[0] == 2) && (Copy_u8Results[1] == 3) &&(Copy_u8Results[2] == 3)&&(Copy_u8Results[3] == 2) &&(Copy_u8Results[4] == 2)) {
	                    return STOP;
	    }
	    else {

                return NO_CHANGE;	    }
}


/*
 * ULTRASONIC_SENSOR_prog.c
 *
 *  Created on: Jul 7, 2023
 *      Author: fathy
 */

#include "../../LIBRARY/stdTypes.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/EXTI/EXTI_int.h"
#include "ULTRASONIC_SENSOR_priv.h"
#include "ULTRASONIC_SENSOR_conf.h"
#include"../../HAL/LCD/LCD_int.h"
#include"../../MCAL/ICU/ICU_int.h"
#include "../../MCAL/TIMER0/TIMER0_int.h"
#include"../../MCAL/TIMER0/TIMER_priv.h"
#include <util/delay.h>

u8 Edge_Count = 0;
u16 Time_High = 0;
u16 distance=0;

void ULTRASONIC_SENSOR_voidEdgeProcessing(void){

	Edge_Count++;
		if(Edge_Count == 1)
		{

			Icu_voidClearTimerValue();

			Icu_voidSetEdgeDetectionType(FALLING_EDGE);
		}

		else if(Edge_Count == 2)
		{

			Time_High = Icu_u16GetInputCaptureValue();


			Edge_Count =0;
			Icu_voidClearTimerValue();

			Icu_voidSetEdgeDetectionType(RISING_EDGE);
		}

}


void ULTRASONIC_SENSOR_voidInit(void){

		Icu_ConfigType Icu_Config = {F_8,RISING_EDGE};


	Icu_voidSetCallBack(ULTRASONIC_SENSOR_voidEdgeProcessing);


		Icu_voidInit(&Icu_Config);


		DIO_voidSetPinDirection(ULTRASONIC_SENSOR_TRIG_GROUP,ULTRASONIC_SENSOR_TRIG_PIN,DIO_u8OUTPUT);
}
void ULTRASONIC_SENSOR_voidTrigger(void){

	DIO_voidSetPinValue(ULTRASONIC_SENSOR_TRIG_GROUP,ULTRASONIC_SENSOR_TRIG_PIN,DIO_u8HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(ULTRASONIC_SENSOR_TRIG_GROUP,ULTRASONIC_SENSOR_TRIG_PIN,DIO_u8LOW);
}
u16 ULTRASONIC_SENSOR_u16ReadDistance(void){
	ULTRASONIC_SENSOR_voidTrigger();

		distance= ((u16)(f32)((Time_High)/57.47));
        distance/=2;     /* i work as frequency 16 million not 8 million */
	return distance;
}

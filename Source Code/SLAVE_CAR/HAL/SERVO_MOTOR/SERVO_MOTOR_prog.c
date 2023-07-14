/*
 * SERVO_MOTOR_prog.c
 *
 *  Created on: Feb 3, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/errorState.h"
#include"../../LIBRARY/stdTypes.h"
#include"../../MCAL/TIMER1/TIMER1_int.h"
#include "SERVO_MOTOR_priv.h"
#include "SERVO_MOTOR_conf.h"
#include<util/delay.h>
void SERVO_MOTOR_voidInit(void){
	Pwm1_voidInit();
	Pwm1_voidSetFrequency(50);
	Pwm1_voidStart();
}
void SERVO_MOTOR_voidRotate(void){
	Pwm1_voidSetOCR1A(RIGHT);
	_delay_ms(1000);
	Pwm1_voidSetOCR1A(MIDDLE);
	_delay_ms(1000);
	Pwm1_voidSetOCR1A(LEFT);
	_delay_ms(1000);
	Pwm1_voidSetOCR1A(MIDDLE);
	_delay_ms(1000);
}
void SERVO_MOTOR_voidRotateLeft(void){
	Pwm1_voidSetOCR1A(LEFT);
}
void SERVO_MOTOR_voidRotateRight(void){
	Pwm1_voidSetOCR1A(RIGHT);
}
void SERVO_MOTOR_voidRotateMiddle(void){
	Pwm1_voidSetOCR1A(MIDDLE);
}



void SERVO_MOTOR_voidTurnOff(void){
	Pwm1_voidStop();
	return;
}

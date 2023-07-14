/*
 * TIMER1_prog.c
 *
 *  Created on: Feb 3, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/errorState.h"
#include"../../LIBRARY/stdTypes.h"
#include"../DIO/DIO_int.h"
#include"TIMER1_priv.h"
#include"TIMER1_conf.h"
#include "../../HAL/LCD/LCD_int.h"
#include "util/delay.h"
void Pwm1_voidInit(void){

#if PWM1_MODE ==FAST_PWM
	TCCR1A&=~(1<<0);
	TCCR1A|=(1<<1);
	TCCR1B|=(1<<3);
	TCCR1B|=(1<<4);
#endif

#if OUTPUT_MODE==NON_INVERTED
	TCCR1A|=(1<<7);
	TCCR1A&=~(1<<6);
#endif
	DIO_voidSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN5,DIO_u8OUTPUT);


	//CHANNEL 2 INIT
  DIO_voidSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN4,DIO_u8OUTPUT);
	TCCR1A|=(1<<5);
	TCCR1A&=~(1<<4);
    LCD_voidInit();
	return;
}

void Pwm1_voidSetFrequency(u16 Copy_u16Frequency){

	ICR1 = ((CRYSTAL_FREQUENCY * 1000000) / (Copy_u16Frequency* TIMER1_PRESCALER));
	LCD_voidWritInteger(ICR1);
	return;
}
void Pwm1_voidSetOCR1A(u16 Copy_u16DutyCycle){


	OCR1A = Copy_u16DutyCycle;
	//LCD_voidWritInteger(OCR1A);


		return;
	}
void Pwm1_voidSetOCR1B(u16 Copy_u16DutyCycle){


		OCR1B = Copy_u16DutyCycle;


		return;
	}


void Pwm1_voidStart(void){


	#if TIMER1_PRESCALER ==NO_CLK
		//do nothing
	#elif TIMER1_PRESCALER==PRESCLNG_1

		TCCR1B|=(1<<0);
	#elif TIMER1_PRESCALER==PRESCLNG_8
		TCCR1B|=(1<<1);
	#elif TIMER1_PRESCALER==PRESCLNG_64
		TCCR1B|=(3<<0);
	#elif TIMER1_PRESCALER==PRESCLNG_256
		TCCR1B|=(1<<2);
	#elif TIMER1_PRESCALER==PRESCLNG_1024
		TCCR1B|=(5<<0);
	#elif TIMER1_PRESCALER=FALLING
		TCCR1B|=(6<<0);
	#elif TIMER0_PRES==RISING
		TCCR1B|=(7<<0);

	#endif

		return;
}
void Pwm1_voidStop(void){
	TCCR1B&=~(7<<0);
	return;
}

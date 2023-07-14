/*
 * ICU_prog.c
 *
 *  Created on: Jul 9, 2023
 *      Author: fathy
 */

#include"../../LIBRARY/stdTypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"ICU_priv.h"
#include"ICU_conf.h"
#include "ICU_int.h"
#include <avr/interrupt.h>
#include "../../HAL/LCD/LCD_int.h"
static  volatile void (*ICU_callBackPtr)(void) = NULL;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_CAPT_vect){
	if(ICU_callBackPtr != NULL)
	{

		ICU_callBackPtr(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void Icu_voidInit(const Icu_ConfigType * Config_Ptr)
{
	/* Configure ICP1/PD6 as i/p pin */
	DIO_voidSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8INPUT);

	/* Timer1 always operates in Normal Mode */
	TCCR1A = (1<<3) | (1<<2);

	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */

	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->clock);
	/*
     * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge)<<6);

	/* Initial Value for Timer1 */
	TCNT1 = 0;

	/* Initial Value for the input capture register */
	ICR1 = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMSK |= (1<<5);
}

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_voidSetCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	ICU_callBackPtr = a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void Icu_voidSetEdgeDetectionType(const Icu_EdgeType a_edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | (a_edgeType<<6);
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
u16 Icu_u16GetInputCaptureValue(void)
{
	//LCD_voidWritInteger(ICR1);
	return ICR1;

}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_voidClearTimerValue(void)
{
	TCNT1 = 0;
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_voidDeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<5);
}

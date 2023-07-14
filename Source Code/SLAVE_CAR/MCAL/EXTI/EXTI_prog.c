/*
 * EXTI_prog.c

 *
 *  Created on: Jan 30, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/errorState.h"
#include"../../LIBRARY/stdTypes.h"
#include"EXTI_conf.h"
#include"EXTI_priv.h"
#include"../DIO/DIO_int.h"
static void (*EXTI_pFunISR0Fun)(void) = NULL;
static void (*EXTI_pFunISR1Fun)(void) = NULL;
static void (*EXTI_pFunISR2Fun)(void) = NULL;
void EXTI_voidInit(void){

	//INT0
#if EXTI0_INT_MODE==EVENT_TRIGGERED
	GICR|=(DIO_u8BIT_MASK<<6);
#elif EXTI0_INT_MODE==POLLING
	GICR&=~(DIO_u8BIT_MASK<<6);
#else
#error exti0 configuration is wrong

#endif
	//clear register before intializion
	MCUCR &=~(3<<0);

#if EXTI0_SENSE_LEVEL == LOW_LEVEL

#elif EXTI0_SENSE_LEVEL == ANY_CHANGE
	MCUCR |= (1<<0);
#elif EXTI0_SENSE_LEVEL == FALLING
	MCUCR |= (2<<0);
#elif EXTI0_SENSE_LEVEL == RISING
	MCUCR |= (3<<0);
#else
#error sense level of exti 0 is wrong
#endif

	//INT1

#if EXTI1_INT_MODE==EVENT_TRIGGERED
	GICR|=(DIO_u8BIT_MASK<<7);
#elif EXTI0_INT_MODE==POLLING
	GICR&=~(DIO_u8BIT_MASK<<7);
#else
//#error exti0 configuration is wrong
#endif
	//clear register before intializion
	MCUCR &=~(3<<2);

#if EXTI1_SENSE_LEVEL == LOW_LEVEL

#elif EXTI1_SENSE_LEVEL == ANY_CHANGE
	MCUCR |= (1<<2);
#elif EXTI1_SENSE_LEVEL == FALLING
	MCUCR |= (2<<2);
#elif EXTI1_SENSE_LEVEL == RISING
	MCUCR |= (3<<2);
#else
#error sense level of exti 0 is wrong
#endif


	//INT2
#if EXTI2_INT_MODE==EVENT_TRIGGERED
	GICR|=(DIO_u8BIT_MASK<<5);
#elif EXT2_INT_MODE==POLLING
	GICR&=~(DIO_u8BIT_MASK<<5);
#else
//#error exti2 configuration is wrong
#endif
	//clear register before intializion
	MCUCSR&=~(1<<6);

#if EXTI2_SENSE_LEVEL==FALLING

#elif EXTI2_SENSE_LEVEL==RISING
	MCUCSR|=(1<<6);
#else
#error sense level of exti 0 is wrong
#endif
	return ;
}

void EXTI_voidSetSenseLevel(u8 Copy_u8IntPinNum , u8 Copy_u8SenseLevel){

	if(Copy_u8IntPinNum == INT0)
		{
			MCUCR &=~(3<<0);
			switch(Copy_u8SenseLevel)
			{
			case LOW_LEVEL:

				break;
			case ANY_CHANGE:
				MCUCR |= (1<<0);
				break;
			case FALLING:
				MCUCR |= (2<<0);
				break;
			case RISING:
				MCUCR |= (3<<0);
				break;

			}
		}
		else if(Copy_u8IntPinNum == INT1)
		{
           MCUCR&=~(3<<2);
       	switch(Copy_u8SenseLevel)
       			{
       			case LOW_LEVEL:

       				break;
       			case ANY_CHANGE:
       				MCUCR |= (1<<2);
       				break;
       			case FALLING:
       				MCUCR |= (2<<2);
       				break;
       			case RISING:
       				MCUCR |= (3<<2);
       				break;

       			}

		}
		else if(Copy_u8IntPinNum == INT2)
		{
        MCUCSR&=~(1<<6);
        switch(Copy_u8SenseLevel){
        case FALLING:
        	break;
        case RISING:
        	MCUCSR|=(1<<6);
        	break;

		}}


		return;
	}


void EXTI_voidEnableInterrupt(u8 Copy_u8IntPinNum){

	switch(Copy_u8IntPinNum){
	case INT0:
		GICR|=(1<<6);
		break;
	case INT1:
		GICR|=(1<<7	);
		break;
	case INT2:
		GICR|=(1<<5);
		break;

}
return;
}
void EXTI_voidsDisableInterrupt(u8 Copy_u8IntPinNum){

		switch(Copy_u8IntPinNum){
		case INT0:
			GICR&=~(1<<6);
			break;
		case INT1:
			GICR&=~(1<<7	);
			break;
		case INT2:
			GICR&=~(1<<5);
			break;

}
		return;
}

void EXTI_voidCallBack(void(*Copy_pFunAppFun)(void) , u8 Copy_u8IntPinNum){

	if(Copy_pFunAppFun != NULL)
		{
			switch(Copy_u8IntPinNum){
			case INT0:
				EXTI_pFunISR0Fun=Copy_pFunAppFun;
				break;
			case INT1:
				EXTI_pFunISR1Fun=Copy_pFunAppFun;
				break;
			case INT2:
				EXTI_pFunISR2Fun=Copy_pFunAppFun;
				break;

			}
		}
		return;
	}


/*
void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));

	//int0
	void __vector_1 (void)
	{
		if (EXTI_pFunISR0Fun != NULL)
		{
			EXTI_pFunISR0Fun ();
		}
	}

	//int1
	void __vector_2 (void)
	{
		if (EXTI_pFunISR1Fun != NULL)
				{
					EXTI_pFunISR1Fun ();
				}
	}

	//int2
	void __vector_3 (void)
	{
		if (EXTI_pFunISR2Fun != NULL)
				{
					EXTI_pFunISR2Fun ();
				}
	}
*/

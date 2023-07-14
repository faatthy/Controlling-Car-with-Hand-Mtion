/*
 * ICU_priv.h
 *
 *  Created on: Jul 9, 2023
 *      Author: fathy
 */

#ifndef MCAL_ICU_ICU_PRIV_H_
#define MCAL_ICU_ICU_PRIV_H_
/*
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;
*/

#define ICR1		(*(volatile u16*)0x46)
#define ICR1L		(*(volatile u8*)0x46)
#define ICR1H		(*(volatile u8*)0x47)

#define OCR1A		(*(volatile u16*)0x4A)
#define OCR1AL		(*(volatile u8*)0x4A)
#define OCR1AH		(*(volatile u8*)0x4B)
#define OCR1B		(*(volatile u16*)0x48)
#define OCR1BL		(*(volatile u8*)0x48)
#define OCR1BH 		(*(volatile u8*)0x49)


#define TCNT1		(*(volatile u16*)0x4C)
#define TCNT1L		(*(volatile u8*)0x4C)
#define TCNT1H		(*(volatile u8*)0x4D)

#define TCCR1		(*(volatile u16*)0x4E)
#define TCCR1A		(*(volatile u8*)0x4F)
#define TCCR1B		(*(volatile u8*)0x4E)

#define TIMSK	*((volatile u8*) 0x59)

#endif /* MCAL_ICU_ICU_PRIV_H_ */

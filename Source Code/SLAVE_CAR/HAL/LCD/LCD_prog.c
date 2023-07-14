/*
 * LCD_prog.c
 *
 *  Created on: Jan 28, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/errorState.h"
#include"../../LIBRARY/stdTypes.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"LCD_priv.h"
#include"LCD_conf.h"
#include<util/delay.h>
void LCD_voidWriteNLatch(u8 Copy_u8Byte){

	DIO_voidSetPinValue(LCD_u8RW_GROUP,LCD_u8RW_PIN,DIO_u8LOW);
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8LOW);

#if LCD_MODE==EIGHT_BIT
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,(Copy_u8Byte>>7)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D6_PIN,(Copy_u8Byte>>6)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D5_PIN,(Copy_u8Byte>>5)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D4_PIN,(Copy_u8Byte>>4)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D3_PIN,(Copy_u8Byte>>3)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D2_PIN,(Copy_u8Byte>>2)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D1_PIN,(Copy_u8Byte>>1)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D0_PIN,(Copy_u8Byte>>0)&DIO_u8BIT_MASK);
#elif LCD_MODE==FOUR_BIT
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,(Copy_u8Byte>>7)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D6_PIN,(Copy_u8Byte>>6)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D5_PIN,(Copy_u8Byte>>5)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D4_PIN,(Copy_u8Byte>>4)&DIO_u8BIT_MASK);
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8LOW);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,((Copy_u8Byte>>3)&1));
	DIO_voidSetPinValue(LCD_u8D6_GROUP,LCD_u8D6_PIN,((Copy_u8Byte>>2)&1));
	DIO_voidSetPinValue(LCD_u8D5_GROUP,LCD_u8D5_PIN,((Copy_u8Byte>>1)&1));
	DIO_voidSetPinValue(LCD_u8D4_GROUP,LCD_u8D4_PIN,((Copy_u8Byte>>0)&1));
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8LOW);
	_delay_ms(2);

	#endif

					return;
}
void LCD_voidInit(void){

	DIO_voidSetPinDirection(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8RW_GROUP,LCD_u8RW_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8OUTPUT);

	DIO_voidSetPinDirection(LCD_u8D7_GROUP,LCD_u8D7_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8D6_GROUP,LCD_u8D6_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8D5_GROUP,LCD_u8D5_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8D4_GROUP,LCD_u8D4_PIN,DIO_u8OUTPUT);
#if LCD_MODE== EIGHT_BIT
	DIO_voidSetPinDirection(LCD_u8D3_GROUP,LCD_u8D3_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8D2_GROUP,LCD_u8D2_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8D1_GROUP,LCD_u8D1_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_u8D0_GROUP,LCD_u8D0_PIN,DIO_u8OUTPUT);

	DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8OW);
	LCD_voidWriteNLatch(0x38);
#elif LCD_MODE==FOUR_BIT
	DIO_voidSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,0);
	DIO_voidSetPinValue(LCD_u8D6_GROUP,LCD_u8D6_PIN,0);
	DIO_voidSetPinValue(LCD_u8D5_GROUP,LCD_u8D5_PIN,1);
	DIO_voidSetPinValue(LCD_u8D4_GROUP,LCD_u8D4_PIN,0);
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8LOW);
		_delay_ms(2);
		DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);

	      LCD_voidWriteNLatch(0x28);

#endif
	      //desplay on off

	     	      DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);
	     	      LCD_voidWriteNLatch(0X0F);
	     	      //desplay clear
	     	     DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);
	     	    	     	      LCD_voidWriteNLatch(0X01);
	     	    	     	      //set mode (increasing or decreasing)and the cursor
	     	    	     	     DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);
	     	    	     	    	      LCD_voidWriteNLatch(0X06);
	      return;
}
void LCD_voidWriteData(u8 Copy_u8Data){

	DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8HIGH);
	LCD_voidWriteNLatch(Copy_u8Data);
	return;
}
void LCD_voidWriteCommand(u8 Copy_u8Command){

	DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);
			      LCD_voidWriteNLatch(Copy_u8Command);
			      return;
}

void LCD_voidWriteString(const char*Copy_String){

	while(*Copy_String!=0){
			DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8HIGH);
			LCD_voidWriteNLatch(*Copy_String++);
		}
	return;
}
void LCD_voidClearScreen(void){

	DIO_voidSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);
	LCD_voidWriteNLatch(0x01);
	LCD_voidWriteCommand(0x80);           //GO TO POSITION ZER0
	return;
}
void LCD_voidShiftDisplayRight(void){

	LCD_voidWriteCommand(0x18);
	return ;
}
void LCD_voidDisplayLeft(void){

	LCD_voidWriteCommand(0x1c);
	return ;
}
void LCD_voidSetCgram(u8 * Copy_u8Array,u8 Copy_u8Position,u8 Copy_u8Num_Char){

	LCD_voidWriteCommand(0x40+8*Copy_u8Position);
		u8 i;
		for(i=0;i<8*Copy_u8Num_Char;i++){
			LCD_voidWriteData(Copy_u8Array[i]);

		}
		return;
}
void LCD_voidSetDdram(u8 Copy_u8Position){

		LCD_voidWriteCommand(0X80+(8*Copy_u8Position));
		return;
}
void LCD_voidWriteCharacter(u8 Copy_u8Char){

	LCD_voidWriteData(Copy_u8Char);
	return;
}
void LCD_voidWritInteger(u16 Copy_intNumber){

int local_intTempNum=Copy_intNumber;
u8 local_u8Length=0;
if(Copy_intNumber==0){
	LCD_voidWriteCharacter('0');
	return;
}
while(local_intTempNum!=0){
	local_intTempNum/=10;
	local_u8Length++;
}
u8 array[local_u8Length];
local_intTempNum=Copy_intNumber;
for(u8 i=local_u8Length;i>0;i--){
	array[i-1]=local_intTempNum%10+'0';
	local_intTempNum/=10;
}
for(u8 i=0;i<local_u8Length;i++){
	LCD_voidWriteCharacter(array[i]);
}
return;
}
void LCD_voidWriteFloat(f32 Copy_floatNumber){

	u32 Local_u32int=(u32)(Copy_floatNumber);
	LCD_voidWritInteger(Local_u32int);
	LCD_voidWriteCharacter('.');
	u32 Local_u32float=(u32)(1000.0*(Copy_floatNumber-(u32)(Local_u32int)));
    LCD_voidWritInteger(Local_u32float);

	return;
}
void LCD_voidGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col){

	if(Copy_u8Row<=1&&Copy_u8Col<=16){
		if(Copy_u8Row==0){
			LCD_voidWriteCommand((0x80+Copy_u8Col));
		}
		else if(Copy_u8Row==1){
			LCD_voidWriteCommand((0xC0+Copy_u8Col));
		}
	}

		return;

}

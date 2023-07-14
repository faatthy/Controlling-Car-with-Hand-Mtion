/*
 * LCD_int.h
 *
 *  Created on: Jan 28, 2023
 *      Author: fathy
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

void LCD_voidInit(void);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteNLatch(u8 Copy_u8Byte);
void LCD_voidWriteString(const char*Copy_String);
void LCD_voidClearScreen(void);
void LCD_voidShiftDisplayRight(void);
void LCD_voidShiftDisplayLeft(void);
void LCD_voidSetCgram(u8 * Copy_u8Array,u8 Copy_u8Position,u8 Copy_u8Num_Char);
void LCD_voidSetDdram(u8 Copy_u8Position);
void LCD_voidWriteCharacter(u8 Copy_u8Char);
void LCD_voidWritInteger(u16 Copy_intNumber);
void LCD_voidWriteFloat(float Copy_floatNumber);
void LCD_voidGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col);

#endif /* HAL_LCD_LCD_INT_H_ */

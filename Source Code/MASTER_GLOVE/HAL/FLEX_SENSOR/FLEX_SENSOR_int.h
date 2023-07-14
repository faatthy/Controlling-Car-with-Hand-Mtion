/*
 * FLEX_SENSOR_int.h
 *
 *  Created on: Jul 5, 2023
 *      Author: fathy
 */

#ifndef HAL_FLEX_SENSOR_FLEX_SENSOR_INT_H_
#define HAL_FLEX_SENSOR_FLEX_SENSOR_INT_H_

void FLEX_SENSOR_voidInit(void);
u16 FLEX_SENSOR_voidReadFinger(u8 Copy_u8Finger);
u8 Translate_Results(u16*Copy_Results);
#endif /* HAL_FLEX_SENSOR_FLEX_SENSOR_INT_H_ */

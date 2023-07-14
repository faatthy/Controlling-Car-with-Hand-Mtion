/*
 * GIE_prog.c
 *
 *  Created on: Jan 30, 2023
 *      Author: fathy
 */
#include"../../LIBRARY/errorState.h"
#include"../../LIBRARY/stdTypes.h"
#include"GIE_conf.h"
#include"GIE_priv.h"
void GIE_voidEnable(void){

	SREG|=(1<<7);
	return ;
}
void GIE_voidDisable(void){

	SREG&=~(1<<7);
	return;
}

/*
 * SwICU.c
 *
 * Created: 1/29/2020 1:55:04 PM
 *  Author: bodau
 */ 
#include "SwICU.h"


void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge)
{
	SwICU_SetCfgEdge(a_en_inputCaptureEdge);
	timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_1024,
				0, 0, T0_INTERRUPT_NORMAL);
	sei();
}

EN_SwICU_Edge_t SwICU_GetCfgEdge(void)
{
	return MCUCSR & ISC2;
}

void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge)
{
	if (a_en_inputCaptureEdgeedge == SwICU_EdgeFalling) {
		MCUCSR &= ~(1 << ISC2);
	} else {
		MCUCSR |= (1 << ISC2);
	}
}

void SwICU_Read(volatile uint8_t * a_pu8_capt)
{
	*a_pu8_capt = timer0Read();
}

void SwICU_Stop(void)
{
	timer0Stop();
}

void SwICU_Start(void)
{
	timer0Start();
}

void SwICU_Enable(void)
{
	GICR |= (1 << INT2);
}

void SwICU_Disable(void)
{
	GICR &= ~(1 << INT2);
}
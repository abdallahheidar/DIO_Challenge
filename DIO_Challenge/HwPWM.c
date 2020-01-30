/*
 * HwPWM.c
 *
 * Created: 1/30/2020 11:44:50 AM
 *  Author: bodau
 */ 

#include "HwPWM.h"

void HwPWMInit(void)
{
	timer1Init(0x00,
				(T1_OC1A_CLEAR | T1_OC1B_CLEAR),
				T1_PRESCALER_64,
				0,
				0,
				0,
				0,
				T1_POLLING);
	TCCR1A |= 0xA2;
	TCCR1B |= 0x10;
	TCNT1 = 0;
	gpioPinDirection(GPIOD, BIT4, OUTPUT);
	gpioPinDirection(GPIOD, BIT5, OUTPUT);
}


void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency)
{
	uint16_t prescaler = 64;
	uint8_t OK = 0;
	uint32_t TOP = ( 8000000UL / (prescaler * a_u32_frequency) );;
	while(!OK)
	{
 		gpioPinDirection(GPIOD, BIT0, OUTPUT);
		if (TOP > 255 && prescaler == 64){
			prescaler = 256;
			TOP = ( 8000000UL / (prescaler * a_u32_frequency) );
		} else if (TOP > 255 && prescaler == 256) {
			prescaler = 1024;
			TOP = ( 8000000UL / (prescaler * a_u32_frequency) );
		} else {
			OK = 1;
		}
	}
	//gpioPinWrite(GPIOD, BIT0, LOW);
	uint32_t Ton = TOP * (a_u8_duty/100.00);
	ICR1 = TOP;
	OCR1A = Ton;
	OCR1B = Ton;
	
	if (prescaler == 64) {
		TCCR1B |= T1_PRESCALER_64;
	} else if (prescaler == 256) {
		TCCR1B |= T1_PRESCALER_256;
		gpioPinWrite(GPIOD, BIT0, HIGH);
	} else {
		TCCR1B |= T1_PRESCALER_256;
	}
}
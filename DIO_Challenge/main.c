#include "led.h"
#include "pushButton.h"
#include "sevenSeg.h"
#include "softwareDelay.h"
#include "timers.h"
#include "gpio.h"
#include "SwICU.h"
#include "interrupt.h"
#include "std_types.h"
#include "HwPWM.h"
#include "registers.h"

uint8_t SwICU_Reading;

void Go_State(void);
void Ready_State(void);
void Stop_State(void);

void REQ1_Start(void);
void REQ2_Start(void);
void REQ3_Start(void);

int main(void)
{
	HwPWMInit();
	HwPWMSetDuty(70, 100);
	while (1)
	{
	}
	
	/*
	HwPWMInit();
	while(1)
	{
		HwPWMSetDuty(50, 200);
		softwareDelayMs(100);
	}
	*/
	/*
	Led_Init(LED_0);
	
	while(1)
	{
		timer2SwPWM(PORTB_DATA, BIT4, 50, 50);
	}
	
	while(1)
	{
		Led_Off(LED_0);
		timer0DelayMs(10);
		Led_On(LED_0);
		timer0DelayMs(10);
	}
	uint8_t REQ_Select = 0;
	gpioPinDirection(GPIOA, (BIT5 | BIT6 | BIT7), INPUT);
	gpioPortWrite(GPIOA, (BIT5 | BIT6 | BIT7));
	REQ_Select = gpioPortRead(GPIOA);
	switch(REQ_Select)
	{
		case 192:
			REQ1_Start();
			break;
		case 160:
			REQ2_Start();
			break;
		case 96:
			REQ3_Start();
			break;
		default: break;
	}
    while (1) 
    {
    }
	*/
}


void Go_State(void)
{
	Led_On(LED_1);
	softwareDelayMs(1000);
	Led_Off(LED_1);
}



void Ready_State(void)
{
	Led_On(LED_2);
	softwareDelayMs(1000);
	Led_Off(LED_2);
}


void Stop_State(void)
{
	Led_On(LED_3);
	softwareDelayMs(1000);
	Led_Off(LED_3);
}


void REQ1_Start(void)
{
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);
	uint8_t sevSegNumber = 0;
	while(1){
		for ( sevSegNumber = 0; sevSegNumber < 100 ; sevSegNumber++ )
		{
			for (int cnt=0; cnt<10; cnt++)
			{
				sevenSegEnable(SEG_0);
				sevenSegWrite(SEG_0, sevSegNumber / 10 );
				softwareDelayMs(50);
				sevenSegDisable(SEG_0);
				
				
				sevenSegEnable(SEG_1);
				sevenSegWrite(SEG_1, sevSegNumber % 10 );
				softwareDelayMs(50);
				sevenSegDisable(SEG_1);
			}
		}
	}
}


void REQ2_Start(void)
{
	Led_Init(LED_1);
	uint8_t pressCounts = 0 ;
	uint8_t intPress = 0;
	while(1){
		pressCounts = 0 ;
		intPress = 0;
		if (pushButtonGetStatus(BTN_1) == Prepressed)
		{
			softwareDelayMs(20);
			if (pushButtonGetStatus(BTN_1) == Prepressed)
			{
				if (pressCounts == 0)
				{
					pressCounts++;
					Led_On(LED_1);
					for (int i = 0; i < 5; i++)
					{
						softwareDelayMs(200);
						if (pushButtonGetStatus(BTN_1) == Prepressed){
							intPress = 1;
						}
					}
					if (intPress == 0)
					{
						pressCounts = 0;
						} else {
						pressCounts++;
						softwareDelayMs(1000);
					}
				}
				} else {
				Led_Off(LED_1);
			}
			} else {
			Led_Off(LED_1);
		}
	}
}



void REQ3_Start(void)
{
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	
	uint8_t State = 0;
	for (;;)
	{
		switch(State){
			case 0:
			Go_State();
			State = 1;
			break;
			case 1:
			Ready_State();
			State = 2;
			break;
			case 2:
			Stop_State();
			State = 0;
			break;
			default: break;
		}
	}
}

/*
ISR(INT2_vect) {
	volatile uint8_t edgeDetect = SwICU_EdgeRisiging;
	if (edgeDetect == SwICU_EdgeRisiging  )
	{
		SwICU_Start();
		SwICU_Disable();
		SwICU_SetCfgEdge(SwICU_EdgeFalling);
		SwICU_Enable();
		edgeDetect = SwICU_EdgeFalling;
	}
	else if (edgeDetect == SwICU_EdgeFalling )
	{
		SwICU_Stop();
		SwICU_Read(&SwICU_Reading);
		SwICU_Disable();
		SwICU_SetCfgEdge(SwICU_EdgeRisiging);
		SwICU_Enable();
		edgeDetect = SwICU_EdgeRisiging;
	}
}
*/
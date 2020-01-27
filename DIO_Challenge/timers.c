/**
 * @file	timers.c
 * @author	Abdallah Heidar
 * @date	22 Jan 2020
 * @brief	The timer driver implementation
 */

#include "timers.h"
#include "macros.h"

uint8_t g_duty;

#define FULL_DUTY 100
#define  FREQUENCY 8000000UL

uint8_t tim0_prescaler = T0_NO_CLOCK;
uint8_t T1_prescaler;
uint8_t T2_prescaler;


/*===========================Timer0 Control===============================*/

/**
 * @brief Initialize Timer0
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t en_mode, En_timer0OC_t en_OC0,
				En_timer0perscaler_t en_prescal,
			    uint8_t u8_initialValue, uint8_t u8_outputCompare,
			    En_timer0Interrupt_t en_interruptMask)
				{
								
				TCCR0 |= en_mode | en_OC0 ;
				timer0Set(u8_initialValue);
				if( en_mode == T0_COMP_MODE){
					 OCR0 = u8_outputCompare;
				}
				tim0_prescaler = en_prescal;
				TIMSK |= en_interruptMask;
				}				
					
				

/**
 * @brief set Timer0 value
 * @param u8_value the value desired for Timer0
 */
void timer0Set(uint8_t u8_value){
	
	TCNT0 = u8_value;
}

/**
 * @brief Read the value of timer/counter register
 * @return TCNT0 value
 */
uint8_t timer0Read(void){
	return TCNT0;
}

/**
 * @brief Start Timer0
 */
void timer0Start(void){
	
	TCCR0 |= tim0_prescaler;
}

/**
 * @brief Stop Timer0
 */
void timer0Stop(void){
	/* clear the first three bits to provide no clock to the timer */
	TCCR0 &= T0_NO_CLOCK;
}

/**
 * @brief Delay function
 * @param u16_delay_in_ms the time in ms
 */
void timer0DelayMs(uint16_t u16_delay_in_ms){
			//uint16_t overflows;
			//clockCycleTime =    prescaler / FREQUENCY;
			//ticksNeeded =  u16_delay_in_ms  / clockCycleTime;
			//overflows =  u16_delay_in_ms * FREQUENCY / (1000 * 255 *prescaler);
		timer0Start();
		while(u16_delay_in_ms--){
			timer0Set(240); // Preload with 256 - 250 counts
			while(!(TIFR & (1 << 0)));
			TIFR |= (1 << 0); // clear with writing one 
		}
		timer0Stop();
}

/**
 * @brief Delay function
 * @param u32_delay_in_us the time in ms
 */
void timer0DelayUs(uint32_t u32_delay_in_us);

/**
 * @brief SW PWM function
 * @param u8_dutyCycle signal duty cycle
 * @param u8_frequency signal frequency
 */
void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency){
	
	g_duty = u8_dutyCycle;
	
}

/*===========================Timer1 Control===============================*/
/**
 * @brief Initialize Timer1
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,
				En_timer1perscaler_t en_prescal, uint16_t u16_initialValue,
			    uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,
				uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask)
				{
						TCCR1 |= en_mode | en_OC ;
						timer1Set(u16_initialValue);
						T1_prescaler = en_prescal;
						OCR1A = u16_outputCompareA;
						OCR1B = u16_outputCompareB;
						ICR1 = u16_inputCapture;
						TIMSK |= en_interruptMask;
				}

/**
 * @brief set Timer1 value
 * @param u16_value the value desired for Timer1
 */
void timer1Set(uint16_t value){
	TCNT1 = value;
}

/**
 * @brief Read the value of timer/counter register
 * @return TCNT1 value
 */
uint16_t timer1Read(void){
	return TCNT1;
}

/**
 * @brief Start Timer1
 */
void timer1Start(void){
	TCCR1B |= T1_prescaler;
}

/**
 * @brief Stop Timer1
 */
void timer1Stop(void){
	TCCR1B &= ~((1 << 2) | (1 << 1) | (1 << 0));
}

/**
 * @brief Delay function
 * @param u32_delay_in_ms the time in ms
 */
void timer1DelayMs(uint16_t u32_delay_in_ms){
	// Tick interval = 4 uS @ 16 MHz DIV_BY_64
	// 1 mS = 250 ticks.
		timer1Start();
		while(u32_delay_in_ms--){
			timer1Set(65286); // Preload with 65536 -250counts
			while(!(TIFR & (1 << 2)));
			TIFR |= (1 << 2);
		}
		timer1Stop();
}	

/**
 * @brief Delay function
 * @param u32_delay_in_us the time in us
 */
void timer1DelayUs(uint32_t u32_delay_in_us);

/**
 * @brief SW PWM function
 * @param u8_dutyCycle signal duty cycle
 * @param u8_frequency signal frequency
 */
void timer1SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);

/*===========================Timer2 Control===============================*/
/**
 * @brief Initialize Timer2
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer2Init(En_timer2Mode_t en_mode,
				En_timer2OC_t en_OC,
				En_timer2perscaler_t en_prescal,
				uint8_t u8_initialValue,
			    uint8_t u8_outputCompare,
				uint8_t u8_assynchronous,
			    En_timer2Interrupt_t en_interruptMask)
				{
					TCCR2 |= en_mode | en_OC ;			
					timer2Set(u8_initialValue);			
					if( en_mode == T0_COMP_MODE){
						OCR2 = u8_outputCompare;
					}
					T2_prescaler  = en_prescal;
					TIMSK |= en_interruptMask;			
				}

/**
 * @brief set Timer2 value
 * @param u8_a_value the value desired for Timer2
 */
void timer2Set(uint8_t u8_a_value){
	TCNT2 = u8_a_value;
}

/**
 * @brief Read the value of timer/counter register
 * @return TCNT2 value
 */
uint8_t timer2Read(void){
	 return TCNT2;
}

/**
 * @brief Start Timer2
 */
void timer2Start(void){
	TCCR2 |= T2_prescaler;
}

/**
 * @brief Stop Timer2
 */
void timer2Stop(void){
	TCCR2 &= T2_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer2DelayMs(uint16_t u16_delay_in_ms){
	
	timer2Start();
	while(u16_delay_in_ms--){
		
		timer2Set(6); // Preload with 256 - 250 counts
		
		while(!(TIFR & (1 << 6)));
		TIFR |= (1 << 6); // clear with writing one
	}
	timer2Stop();
}

/**
 * @brief Delay function
 * @param u16_delay_in_us the time in us
 */
void timer2DelayUs(uint32_t u32_delay_in_us)
{
	timer2Init(T2_COMP_MODE, T2_OC2_DIS, T2_PRESCALER_NO, 0, 14, 0, T2_INTERRUPT_CMP);
	timer2Start();
	while(u32_delay_in_us)
	{
		while(!(GET_BIT(TIFR,7)));
		SET_BIT(TIFR,7);
		u32_delay_in_us--;
	}
}

/**
 * @brief SW PWM function
 * @param u8_dutyCycle signal duty cycle
 * @param u8_frequency signal frequency
 */
void timer2SwPWM(uint8_t gpio_port, uint8_t gpio_pin, uint8_t u8_dutyCycle, uint8_t u8_frequency)
{
	uint32_t Period = (1.00/u8_frequency)*1000000.00;
	uint32_t Ton = Period * (u8_dutyCycle/100.00);
	uint32_t Toff = Period - Ton;
	uint8_t cycles = 20;
	while(cycles)
	{
		gpioPinWrite(gpio_port, gpio_pin, HIGH);
		timer2DelayUs(Ton);
		gpioPinWrite(gpio_port, gpio_pin, LOW);
		timer2DelayUs(Toff);
		cycles--;
	}
}

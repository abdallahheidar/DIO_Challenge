#include "sevenSeg.h"

/**
 * Description: 
 * @param 
 */
void sevenSegInit(En_SevenSegId_t a_segment_id){
	
	gpioPortDirection(SEG_BCD_GPIO, OUTPUT);
	
	switch(a_segment_id){
		
		case SEG_0:
				gpioPinDirection(SEG_EN1_GPIO, SEG_EN1_BIT, OUTPUT);
				break;
				
		case SEG_1:
				gpioPinDirection(SEG_EN2_GPIO, SEG_EN2_BIT, OUTPUT);
		break;
		
		default: break;
	}
}
/**
 * Description: 
 * @param 
 */
void sevenSegEnable(En_SevenSegId_t en_segment_id){
	
	switch(en_segment_id){
		
		case SEG_0:
					gpioPinWrite(SEG_EN1_GPIO, SEG_EN1_BIT, HIGH);
					break;
		case SEG_1:
					gpioPinWrite(SEG_EN2_GPIO, SEG_EN2_BIT, HIGH);
					break;
		default: break; 
		}
}

/**
 * Description: 
 * @param 
 */
void sevenSegDisable(En_SevenSegId_t en_segment_id){
	
		switch(en_segment_id){
			
			case SEG_0:
					gpioPinWrite(SEG_EN1_GPIO, SEG_EN1_BIT, LOW);
					break;
			case SEG_1:
					gpioPinWrite(SEG_EN2_GPIO, SEG_EN2_BIT, LOW);
					break;
			default: break;
		}
}

/**
 * Description: 
 * @param 
 */
void sevenSegWrite(En_SevenSegId_t en_segment_id , uint8_t number ){
	
	switch(en_segment_id){
		
		case SEG_0:
					gpioPortWrite(SEG_BCD_GPIO, LOW);
					gpioPortWrite(SEG_BCD_GPIO, 0x0F & number);
					break;
		case SEG_1:
					gpioPortWrite(SEG_BCD_GPIO, LOW);
					gpioPortWrite(SEG_BCD_GPIO, 0x0F & number);
					break;
		default: break;
	}
}


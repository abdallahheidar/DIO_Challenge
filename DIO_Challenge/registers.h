#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"

/*
 * General Registers
 */
#define MCUCR	*((reg_type8_t)(0X55))
#define MCUCSR	*((reg_type8_t)(0X54))
#define GICR	*((reg_type8_t)(0X5B))
#define GIFR	*((reg_type8_t)(0X5A))

/*
 * PORTx registers
 */

#define PORTA_DATA 	*((reg_type8_t)(0X3B))
#define PORTA_DIR  	*((reg_type8_t)(0X3A))
#define PORTA_PIN	*((reg_type8_t)(0X39))

#define PORTB_DATA 	*((reg_type8_t)(0X38))
#define PORTB_DIR  	*((reg_type8_t)(0X37))
#define PORTB_PIN	*((reg_type8_t)(0X36))

#define PORTC_DATA 	*((reg_type8_t)(0X35))
#define PORTC_DIR  	*((reg_type8_t)(0X34))
#define PORTC_PIN	*((reg_type8_t)(0X33))


#define PORTD_DATA 	*((reg_type8_t)(0X32))
#define PORTD_DIR  	*((reg_type8_t)(0X31))
#define PORTD_PIN	*((reg_type8_t)(0X30))


/*
 * General Timer registers
 */
#define TIMSK		*((reg_type8_t)(0X59))
#define TIFR		*((reg_type8_t)(0X58))


/*
 * Timer 0 Registers
 */

#define TCCR0		*((reg_type8_t)(0X53))
#define TCNT0		*((reg_type8_t)(0X52))
#define OCR0		*((reg_type8_t)(0X5C))


/*
 * Timer 1 Registers
 */

#define TCCR1A		*((reg_type8_t)(0X4F))
#define TCCR1B		*((reg_type8_t)(0X4E))
#define TCCR1		*((reg_type16_t)(0X4E)) // accessing the lowest address 
#define TCNT1H		*((reg_type8_t)(0X4D))
#define TCNT1L		*((reg_type8_t)(0X4C))
#define TCNT1		*((reg_type16_t)(0X4C))
#define OCR1AH		*((reg_type8_t)(0X4B))
#define OCR1AL		*((reg_type8_t)(0X4A))
#define OCR1A		*((reg_type16_t)(0X4A))
#define OCR1BH		*((reg_type8_t)(0X49))
#define OCR1BL		*((reg_type8_t)(0X48))
#define OCR1B		*((reg_type16_t)(0X48))
#define ICR1H		*((reg_type8_t)(0X47))
#define ICR1L		*((reg_type8_t)(0X46))
#define ICR1		*((reg_type16_t)(0X46))


/*
 * Timer 2 Registers
 */
#define TCCR2		*((reg_type8_t)(0X45))
#define TCNT2		*((reg_type8_t)(0X44))
#define OCR2		*((reg_type8_t)(0X43))

/*
 * INT Pins
 */

#define ISC2    6

/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0


/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0




#endif /* REGISTERS_H_ */

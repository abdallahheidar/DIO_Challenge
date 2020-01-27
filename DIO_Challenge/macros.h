/**
 * @file	macros.h
 * @author	Abdallah Heidar
 * @date	22 Jan 2020
 * @brief	The bit manipulation macros 
 */ 

#define SET_BIT(Reg,bit_no)				Reg |=		 (1<<bit_no)
#define CLR_BIT(Reg,bit_no)				Reg &=		~(1<<bit_no)
#define TOG_BIT(Reg,bit_no)				Reg ^=		 (1<<bit_no)

#define SET_BIT_MASK(Reg,bit_mask)		Reg |=		 (bit_mask)
#define CLR_BIT_MASK(Reg,bit_mask)		Reg &=		~(bit_mask)
#define TOG_BIT_MASK(Reg,bit_mask)		Reg ^=		 (bit_mask)
#define GET_BIT(Reg,pin_)				(Reg & pin_)
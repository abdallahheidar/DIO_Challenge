/*
 * dcMotor.h
 *
 * Created: 1/26/2020 10:28:41 AM
 *  Author: Khaled Magdy
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "gpio.h"
#include "timers.h"

#define M1EN_GPIO	(GPIOD)
#define M1EN_BIT	(BIT4)

#define M2EN_GPIO	(GPIOD)
#define M2EN_BIT	(BIT5)

#define M1D1_GPIO	(GPIOD)
#define M1D1_BIT	(BIT2)

#define M1D2_GPIO	(GPIOD)
#define M1D2_BIT	(BIT3)

#define M2D1_GPIO	(GPIOD)
#define M2D1_BIT	(BIT6)

#define M2D2_GPIO	(GPIOD)
#define M2D2_BIT	(BIT7)

/**
 * Description:
 * @param value
 */
void dcMotor1Enable(void);
/**
 * Description:
 * @param value
 */
void dcMotor1Disable(void);
/**
 * Description:
 * @param value
 */
void dcMotor1SetDCD(uint8_t u8_dutyCycle, uint8_t u8_direction);

/**
 * Description:
 * @param value
 */
//----------------------------------
void dcMotor2Enable(void);
/**
 * Description:
 * @param value
 */
void dcMotor2Disable(void);
/**
 * Description:
 * @param value
 */
void dcMotor2SetDCD(uint8_t u8_dutyCycle, uint8_t u8_direction);
//---------------------------------------------------------------------
//----------------------[ Robotic Car Control ]------------------------
/**
 * Description:
 * @param value
 */
void MoveForward(uint8_t u8_dutyCycle);
/**
 * Description:
 * @param value
 */
void MoveBackward(uint8_t u8_dutyCycle);
/**
 * Description:
 * @param value
 */
void CWrotate(uint8_t u8_dutyCycle);
/**
 * Description:
 * @param value
 */
void CCWrotate(uint8_t u8_dutyCycle);
/**
 * Description:
 * @param value
 */
void carSTOP(void);

#endif /* DCMOTOR_H_ */
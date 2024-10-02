/*
 * pwm.h
 *
 *  Created on: Oct 1, 2024
 *      Author: vb
 */

#ifndef PWM_H_
#define PWM_H_

#include "stm32f4xx.h"

#define TCLK    16000000
#define PRSC      16
#define ARR_VAL 100

void pwm_init(void);

#endif /* PWM_H_ */

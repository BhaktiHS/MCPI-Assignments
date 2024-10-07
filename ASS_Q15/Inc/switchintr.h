/*
 * switchintr.h
 *
 *  Created on: Oct 7, 2024
 *      Author: vb
 */

#ifndef SWITCHINTR_H_
#define SWITCHINTR_H_

#include "stm32f4xx.h"

#define GPIO_SWITCH  GPIOA
#define SWITCH_PIN   0
#define SWITCH_CLKEN 0
#define SWITCH_EXTI  0

void switchinit(void);
void EXTI0_IRQHandler(void);

extern uint32_t switchextiflag;

#endif /* SWITCHINTR_H_ */

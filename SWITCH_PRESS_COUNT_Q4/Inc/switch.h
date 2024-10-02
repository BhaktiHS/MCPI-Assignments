/*
 * switch.h
 *
 *  Created on: Sep 21, 2024
 *      Author: vb
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "stm32f4xx.h"

#define GPIO_SWITCH          GPIOA
#define SWITCH_PIN             0
#define GPIO_SWITCH_CLKEN      0

#define SWITCH_EXIT            0

void switchinit(void);
void EXTI0_IRQHandler(void);

extern volatile uint32_t switch_extintr_flag;
extern uint16_t count;

#endif /* SWITCH_H_ */

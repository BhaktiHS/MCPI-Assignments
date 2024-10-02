/*
 * switch.c
 *
 *  Created on: Sep 21, 2024
 *      Author: vb
 */
#include "switch.h"

void switchinit(void)
{
	//enbl GPIOA clock
	RCC->AHB1ENR |= BV(GPIO_SWITCH_CLKEN);
	//MODER 00
	GPIO_SWITCH->MODER &= ~(BV(SWITCH_PIN*2) | BV(SWITCH_PIN*2+1));
	//PUPDR 00
	GPIO_SWITCH->PUPDR &= ~(BV(SWITCH_PIN*2+1) | BV(SWITCH_PIN*2));
	//EN FALLING EDGE DETECTION
	EXTI->FTSR |= BV(SWITCH_EXIT);
	//EN EXT INTR IN IMR
	EXTI->IMR |= BV(SWITCH_EXIT);
	//SEL EXT INTR SYSCFG-EXTICR
	SYSCFG->EXTICR[0] &= ~(BV(3)|BV(2)|BV(1)|BV(0));
	//EN EXT INTR NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
}

volatile uint32_t switch_extintr_flag = 0;
uint16_t count;

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= BV(SWITCH_EXIT);
	count++;
	switch_extintr_flag  = 1;
}

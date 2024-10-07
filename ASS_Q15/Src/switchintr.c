/*
 * switchintr.c
 *
 *  Created on: Oct 7, 2024
 *      Author: vb
 */


#include "i2c_lcd.h"
#include "i2c.h"
#include "adc.h"
#include "switchintr.h"

void switchinit(void)
{
	//rcc EN
	RCC->AHB1ENR |= BV(SWITCH_CLKEN);
	//MODER INPUT 00
	GPIO_SWITCH->MODER &= ~(BV(SWITCH_PIN*2) | (SWITCH_PIN*2+1));
	//PUPDR 0
	GPIO_SWITCH->PUPDR &= ~(BV(SWITCH_PIN*2) | (SWITCH_PIN*2+1));
	EXTI->FTSR |= BV(SWITCH_EXTI);
	EXTI->IMR |= BV(SWITCH_EXTI);
	SYSCFG->EXTICR[0] = ~(BV(3)|BV(2)|BV(1)|BV(0));
	NVIC_EnableIRQ(EXTI0_IRQn);
}

uint32_t switchextiflag=0;
void EXTI0_IRQHandler(void)
{
	EXTI->PR |= BV(SWITCH_EXTI);
	switchextiflag = 1;

}

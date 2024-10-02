/*
 * pwm.c
 *
 *  Created on: Oct 1, 2024
 *      Author: vb
 */

#include "pwm.h"

void pwm_init(void){
	// gpoi pc6 ..tim8 ch1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= BV(6*2+1);
	GPIOC->MODER &= ~BV(6*2);
	GPIOC->AFR[0] |= BV(24) | BV(25);

	//PWM SETUP
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	//	* PCLK = 16MHz, PSC = 16 --> TCLK = 1MHz
	//	* ARR = 100 => PWM output freq = TCLK / ARR = 1 MHz / 100 = 10 KHz
	TIM8->ARR = ARR_VAL;
	//CCR = 0 = 0% DUTY CYCL
	TIM8->CCR1 = 0;
	//o/p mode 00 ccmrx reg
	TIM8->CCMR1 &= ~(TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC1S_1);
	//CCZP 0 - ACTIVE HIGH  CCER
	TIM8-> CCER &= ~TIM_CCER_CC1P;
	//PWM MODE1 110
	TIM8->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
	//CCMR1 - PRELOAD SET, CR1 - ARPE SET
	TIM8->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM8->CR1 |= TIM_CR1_ARPE;
	//Counting mode 00 edge aligned mode
	TIM8->CR1 &= ~(TIM_CR1_CMS_0 | TIM_CR1_CMS_1);
	//EN CCER
	TIM8->CCER |= TIM_CCER_CC1E;
	//EN OP IN BDTR & EN CNTR
	TIM8->BDTR |= TIM_BDTR_MOE;
	TIM8->CR1 |= TIM_CR1_CEN;
}

/*
 * led.c
 *
 *  Created on: Oct 2, 2024
 *      Author: vb
 */

#include "led.h"

void LedInit(uint32_t pin)
{

	RCC->AHB1ENR |= BV(GPIO_LED_CLKEN);
	GPIO_LED->MODER &= ~BV(pin*2+1);
	GPIO_LED->MODER |= BV(pin*2);
	GPIO_LED->OTYPER &= ~BV(pin);
	GPIO_LED->OSPEEDR &= ~(BV(pin*2+1) | BV(pin*2));
	GPIO_LED->PUPDR &= ~(BV(pin*2+1) | BV(pin*2));
}

void LedOn(uint32_t pin)
{
	GPIO_LED->ODR |= BV(pin);
}

void LedOff(uint32_t pin)
{
	GPIO_LED->ODR &= ~BV(pin);
}

void LedBlink(uint32_t pin, uint32_t delayMs)
{
	LedOn(pin);
	DelayMs(delayMs);
	LedOff(pin);
}



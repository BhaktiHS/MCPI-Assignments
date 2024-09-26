/*
 * led.c
 *
 *  Created on: Sep 20, 2024
 *      Author: vb
 */


#include "led.h"

void ledinit(uint32_t pin)
{
	// 3 FOR PORT D
	RCC->AHB1ENR |= BV(GPIO_LED_CLKEN);
	//01: General purpose output mode
	GPIO_LED->MODER &= ~BV(pin*2+1);
	GPIO_LED->MODER |= BV(pin*2);
	//0: Output push-pull (reset state) MODER
	GPIO_LED->OTYPER &= ~BV(pin);
	//SPEED 00 LOW SPEED
	GPIO_LED->OSPEEDR &= ~(BV(pin*2+1) | BV(pin*2));
	//00: No pull-up, pull-down
	GPIO_LED->PUPDR &= ~(BV(pin*2+1) | BV(pin*2));
}

void ledon(uint32_t pin)
{
	//ODR = 1
	GPIO_LED->ODR |= BV(pin);

}

void ledoff(uint32_t pin)
{
	//ODR = 0
	GPIO_LED->ODR &= ~BV(pin);
}

void ledblink(uint32_t pin, uint32_t delayMs)
{
	ledon(pin);
	DelayMs(delayMs);
	ledoff(pin);

}

void ledtoggle(uint32_t pin)
{
	GPIO_LED->ODR ^= BV(pin);
}





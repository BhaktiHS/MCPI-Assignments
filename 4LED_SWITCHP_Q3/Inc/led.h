/*
 * led.h
 *
 *  Created on: Sep 20, 2024
 *      Author: vb
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"

#define GPIO_LED           GPIOD
#define LED_GREEN_PIN        12
#define LED_ORANGE_PIN       13
#define LED_RED_PIN          14
#define LED_BLUE_PIN         15

#define GPIO_LED_CLKEN        3

void ledinit(uint32_t pin);
void ledon(uint32_t pin);
void ledoff(uint32_t pin);
void ledblink(uint32_t pin, uint32_t delayMs);
void ledtoggle(uint32_t pin);

#endif /* LED_H_ */

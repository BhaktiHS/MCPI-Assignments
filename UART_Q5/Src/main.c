/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	char str[30];
	int ch;

	LedInit(LED_RED_PIN);
	LedInit(LED_BLUE_PIN);
	UartInit(9600);

	do
	{
		UartPuts("Enter your choice\r\n1.RED LED ON\r\n2.RED LED OFF\r\n3.BLUE LED ON\r\n4.BLUE LED OFF\r\n5.Exit\r\n");
		UartGets(str);
		sscanf(str,"%d",&ch);
		UartPutch(ch);

		switch(ch)
		{
		case 1: LedOn(LED_RED_PIN);
		        break;
		case 2: LedOff(LED_RED_PIN);
				break;
		case 3: LedOn(LED_BLUE_PIN);
				break;
		case 4: LedOff(LED_BLUE_PIN);
				break;
		case 5: UartPuts("Bye\n");
				break;
		break;
		}
	}while(ch != 5);

	return 0;
}

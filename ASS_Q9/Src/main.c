#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include <ACCEL.h>
#include <I2C.h>
#include <I2C_LCD.h>
#include <SPI.h>
#include "LED.h"

int main(void)
{
	LIS_Data val;
	char str[32];
	char str1[32];
	SystemInit();
	SPI_Init();
	Lcd_Init();
	LIS_Init();
	LedInit(LED_RED_PIN);
	LedInit(LED_BLUE_PIN);
	LedInit(LED_GREEN_PIN);
	LedInit(LED_ORANGE_PIN);
	while(1)
	{
			if(LIS_DRdy())
			{
				while(1)
				{
					val = LIS_GetData();
					sprintf(str, "X=%d, Y=%d\r\n", val.x, val.y);
					sprintf(str1, "Z=%d\r\n", val.z);
					Lcd_Puts(LCD_LINE1,str);
					Lcd_Puts(LCD_LINE2,str1);
					DelayMs(1000);
					if(val.x >= 3000)
					{
						LedOn(LED_RED_PIN);
					}
					else
					{
						LedOff(LED_RED_PIN);
					}
					if(val.y >= 3000)
					{
						LedOn(LED_GREEN_PIN);
					}
					else
					{
						LedOff(LED_GREEN_PIN);
					}
			   }
			}
	}

	return 0;
}


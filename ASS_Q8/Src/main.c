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

int main(void)
{
	LIS_Data val;
	char str[32];
	char str1[32];
	SystemInit();
	SPI_Init();
	Lcd_Init();
	LIS_Init();
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
			   }
			}
	}

	return 0;
}


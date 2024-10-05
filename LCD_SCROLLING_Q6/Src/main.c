#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "i2c_lcd.h"

int main(void)
{
	int ret, count;
	SystemInit();
	ret = Lcd_Init();
	Lcd_Puts(LCD_LINE1, " RAHUL RANJITSING CHANDANSE");
	for(count = 1; count <= 100; count++)
	{
		Lcd_Scroll();
		DelayMs(250);
	}
	return 0;
}


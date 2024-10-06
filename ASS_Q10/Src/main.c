#include <RTC.h>
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "UART.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[64];
	SystemInit();
	UartInit(9600);
	UartPuts("STM32 RTC Demo!!\r\n");
	RTC_Date dt = { .Date = 28, .Month = 2, .Year = 24, .WeekDay = 2 };
	RTC_Time tm = { .Hour = 23, .Minute = 59, .Second = 45 };
	RTC_Init(&dt, &tm);
	while(1)
	{
		RTC_GetDate(&dt);
		RTC_GetTime(&tm);
		sprintf(str, "%02d-%02d-20%02d (%d) %02d:%02d:%02d\r\n",
				dt.Date, dt.Month, dt.Year, dt.WeekDay,
				tm.Hour, tm.Minute, tm.Second);
		UartPuts(str);
		DelayMs(1000);
	}
	return 0;
}

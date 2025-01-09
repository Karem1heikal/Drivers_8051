#include <reg51.h>
#include "LIB/STD_TYPES.h"

#define DAC_PORT	P2

void DACInit();
u8 sin_index=0;

code u8 arr[]={128,176,218,245,255,218,176,128,79,37,10,0,10,37,79};
u8 sd = sizeof(arr)/sizeof(arr[0]);

void timer0_ISR() interrupt 1
{
	DAC_PORT = arr[sin_index];
	sin_index++;
	if(sin_index<sd)
	{
		sin_index=0;
	}
}

void Timer0Init();
void main()
{
	DACInit();
	Timer0Init();
	
	while(1);
}
void DACInit()
{
	DAC_PORT = 00;
}

void Timer0Init()
{
	TMOD = (TMOD &0XF0)|2;
	
	TH0 = 0XA4;
	
	TH0 = 0XA4;
	
	TR0 = 1;
	 
	IE = 0X82;
}
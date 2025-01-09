#include <reg51.h>
#include "LIB/STD_TYPES.h"
#include "ADC/ADC_interface.h"
#include "LCD/LCD_interface.h"
/*
u8 Read;
void main()
{
	Timer0Init();
	ADC_init();
	while(1)
	{
		ADC_u8START_CONV(1,&Read);
		P1=Read;
	}
}

*/

sbit g0 = P0^6;
sbit g1 = P0^7;

u8 Channel[2]= {0,1};
u8 Reault[2];
void Noty_func();
u8 milliVolt;
Chain_t ch1 ={Channel,2,Reault,Noty_func};
void app_delay();
void main()
{
	lcd_init();
	
	Timer0Init();
	ADC_init();
	while(1)
	{
		ADC_u8START_CONV_Chain(&ch1);
	}
	
}

void Noty_func()
{
	g0 = 0;
	g1 = 1;
	milliVolt=(u16)((u32)(ch1.reading[0])*5000UL/256UL);
	LCD_WriteNumber(milliVolt);
	app_delay();
	g1 = 0;
	g0 = 1;
	milliVolt=(u16)((u32)(ch1.reading[1])*5000UL/256UL);
	P1=milliVolt;
	app_delay();
	LCD_WriteNumber(milliVolt);
	
}

void app_delay()
{
	u16 i;
	for(i=0;i<1275;i++);
}



#include <reg51.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "ADC/ADC_private.h"
#include "ADC/ADC_config.h"
#include "ADC/ADC_interface.h"


void Timer0Init()
{
	TMOD = (TMOD & 0XF0) | TIMER0_MODE;
	TH0=0XA4;
	TL0=0XA4;
	IE = 0X82;
	TR0 = 1;
}

void Timer0INT() interrupt 1 
{
	CLK = ~CLK;
}


void ADC_init()
{
	ADC_PORT = 0XFF;
	// OUT 0 / INPUT 1
	P1=0X00;
	ALE   =0 ;
	ADD_A =0 ;
	ADD_B =0 ;
	ADD_C =0 ;
	OE    =0 ;
	EOC   =1 ;
	START =0 ;
	CLK   =0 ;
}

u8 ADC_u8START_CONV(u8 Copy_u8ChannelSel,u8 *Copy_pu8ReadData)
{
	u8 Local_u8StateError = OK;
	if(Copy_pu8ReadData!=NULL)
	{
		if(Copy_u8ChannelSel<7)
		{
			
			ADD_A = Copy_u8ChannelSel & 1;
			ADD_B = Copy_u8ChannelSel>>1  & 1;
			ADD_C = Copy_u8ChannelSel>>2  & 1;
			ALE = 1;
			START = 1;
			ADC_Delay();
			ALE = 0;
			START = 0;
			
			ADC_Delay();
			while(EOC==1);
			while(EOC==0);
			OE = 1;
			ADC_Delay();
			*Copy_pu8ReadData = ADC_PORT;
			OE = 0;
			
		}
		else
			Local_u8StateError = NOTOK;
	}
	else
	{
		Local_u8StateError=NULL_POINTER;
	}
	return Local_u8StateError;
}
u8 ADC_u8START_CONV_Chain(Chain_t* ChainOptions)
{
	u8 Local_u8StateError = OK;
	u8 Local_u8Itration = 0;
	if(ChainOptions->NotificationFunc!=NULL)
	{
		for(Local_u8Itration = 0;Local_u8Itration<ChainOptions->totNoOfChannel;Local_u8Itration++)
		{
			ADC_u8START_CONV(ChainOptions->ChannelArr[Local_u8Itration],(ChainOptions->reading+Local_u8Itration));
		}
		ChainOptions->NotificationFunc();
	}
	else
	{
		Local_u8StateError=NULL_POINTER;
	}
	return Local_u8StateError;
}
static void ADC_Delay()
{
	u8 Count;
	for(Count=0;Count<127;Count++)
	{

	}
}

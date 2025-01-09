

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


typedef struct
{
	u8 *ChannelArr;
	u8	totNoOfChannel;
	u8 *reading;
	void(*NotificationFunc)();
} Chain_t;

#define ADC_PORT P3

sbit ALE   = P2^0;
sbit ADD_A = P2^1; 
sbit ADD_B = P2^2;
sbit ADD_C = P2^3;
sbit OE    = P2^4;
sbit EOC   = P2^5;
sbit START = P2^6;
sbit CLK   = P2^7;

#define TIMER0_MODE  2

void Timer0Init();

void ADC_init();
u8 ADC_u8START_CONV(u8 Copy_u8ChannelSel,u8 *Copy_pu8ReadData);
u8 ADC_u8START_CONV_Chain(Chain_t* ChainOptions);

#endif
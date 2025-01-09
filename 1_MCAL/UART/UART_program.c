

#include <reg51.h>
#include "LIB/STD_TYPES.h"
#include "UART/UART_private.h"
#include "UART/UART_config.h"
#include "UART/UART_interface.h"




static u8 Global_u8BusyFlag= IDLE;  

static void (* Global_NotifictionSend)() = NULL;
static void (* Global_NotifictionRecv)() = NULL;

static u8 *Global_u8Data = NULL;

u8 Local_data;
void UART_init()
{
	TMOD = TIMER_MODE2;
	TH1 = UART_BAUD_RATE;
	SCON &= MODE_MASK; 
	SCON |= UART_MODE;
	TR1 = 1;

}

void UART_SendSynch(u8 Copy_u8Data)
{
	SBUF = Copy_u8Data;
	while(TI == 0);
	TI = 0;
}

u8 UART_RecvSynch()
{
	
	while(RI == 0);
	Local_data = SBUF;
	RI = 0;
	return Local_data;
}
void UART_SendString(const char * str)
{
	u8 i=0;
	while(str[i]!='\0')
	{
		UART_SendSynch(str[i]);
		i++;
	}
}

void UART_SendNumber(u32 Copy_u32Number)
{
	u8 Max_Digits = Num_length(Copy_u32Number);
	s8 i ;
	for (i = Max_Digits; i > 0; i--) {
		UART_SendSynch((Copy_u32Number / Multi_N_10(i - 1)) + '0');
		Copy_u32Number = (Copy_u32Number % Multi_N_10(i - 1));
	}
}

u16 UART_ReceiveNum()
{
	u8 temp = 0;
	u16 RecvByte = 0;
	u8 multi = 1;
	while(1)
	{
		temp = UART_RecvSynch() & 0x0f;
		if(temp==0x0d)
			break;
		RecvByte = temp + (multi*RecvByte);
		multi = 10 ;
	}
	return RecvByte;
}

static u8 Num_length(u16 num) {
	u8 Local_u8Cnt = 0;
	if(num == 0)
		return 1;
	while (num != 0) {
		num /= 10;
		Local_u8Cnt++;
	}
	return Local_u8Cnt;
}
static u16 Multi_N_10(u8 N) {
	u8 Local_u8Cnt;
	u16 p = 1;
	for (Local_u8Cnt = 0; Local_u8Cnt < N; Local_u8Cnt++)
		p *= 10;
	return p;
}


u8 UART_u8Send_Asynch(u8 Copy_u8Data,void *(Notifction)())
{
	u8 Local_u8ErrorState = OK;
	if(Notifction != NULL ){
		if(Global_u8BusyFlag==IDLE)
		{
			Global_u8BusyFlag = BUSY;
			IE |= 0X90;
			Global_NotifictionSend = Notifction;
			SBUF = Copy_u8Data;
		}
		else
			Local_u8ErrorState = BUSY_FUNC;
	}
	else
		Local_u8ErrorState = NULL_POINTER;
	return Local_u8ErrorState;
}
u8 UART_u8Recv_Asynch(u8 *Copy_pu8Data,void *(Notifction)())
{
	u8 Local_u8ErrorState = OK;
	if((Notifction == NULL)||(Copy_pu8Data==NULL)){
		Local_u8ErrorState = NULL_POINTER;
	}
	else{
		if(Global_u8BusyFlag==IDLE)
		{
			Global_u8BusyFlag = BUSY;
			IE |= 0X90;
			Global_NotifictionRecv = Notifction;
			Global_u8Data = Copy_pu8Data;
		}
		else
			Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}
void UART_ISR() interrupt 4
{
	if(TI == 1)
	{
		Global_NotifictionSend();
		TI = 0;
		Global_u8BusyFlag = IDLE; 
	}
	else 
	{
		*Global_u8Data = SBUF ;
		Global_NotifictionRecv();
		RI = 0;
		Global_u8BusyFlag = IDLE; 
	}
		
}


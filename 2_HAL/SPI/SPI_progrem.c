
#include <reg51.h>

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "SPI/SPI_private.h"
#include "SPI/SPI_config.h"
#include "SPI/SPI_interface.h"
sbit DOUT	= P2^4;
sbit DIN =	P2^5;
sbit SCK  = P2^6;
sbit SS 	=	P2^7;


void SPI_init()
{
	DOUT = 1;
	DIN = 0;
	SCK  = 0;
	SS   = 0;
}

void SPI_SEND(u8 Copy_u8Data)
{
	u8 Local_u8Cnt=0;
	SS = 1;
	SS = 0;
	for(Local_u8Cnt=0;Local_u8Cnt<8;Local_u8Cnt++)
	{
		SCK = 0;
		DIN=(Copy_u8Data & (SEND_MASK>>Local_u8Cnt))?1:0;
		//DIN = GET_BIT(Copy_u8Data,(7-Local_u8Cnt));
		SCK = 1;
	}
	SS = 1;
}


u8 SPI_RECV()
{
	u8 Local_u8Cnt=0;
	u8 Local_u8DataBuffer = 0;
	SS = 0;
	for(Local_u8Cnt=0;Local_u8Cnt<8;Local_u8Cnt++)
	{
		SCK = 0;
		if(DOUT)
		{
			//Local_u8DataBuffer |= (SEND_MASK>>Local_u8Cnt);
			SET_BIT(Local_u8DataBuffer,(7-Local_u8Cnt));
		}
		SCK = 1;
	}
	SS = 1;
	return Local_u8DataBuffer;
}

u8 SPI_TRANSCIVE(u8 Copy_u8Data)
{
	u8 Local_u8Cnt=0;
	u8 Loc_storeBit ;
	u8 Local_u8DataBuffer = 0;
	SS = 0;
	for(Local_u8Cnt=0;Local_u8Cnt<8;Local_u8Cnt++)
	{
		SCK = 0;
		Loc_storeBit = GET_BIT(Copy_u8Data,(Local_u8Cnt));
		DIN = (Loc_storeBit);
		SCK = 1;
		if(DOUT)
		{
			SET_BIT(Local_u8DataBuffer,(7-Local_u8Cnt));
		}
		SCK = 0;
	}
	SS = 1;
	return Local_u8DataBuffer;
}
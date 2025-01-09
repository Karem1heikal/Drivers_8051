
#include <reg51.h>
#include "LIB/STD_TYPES.h"

#include "I2C/I2C_interface.h"


void __nop__()
{
	int i=0;
	for(i=0;i<27;i++)
	{
	
	}
}
void I2C_start()
{
	/*
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_HIGH);
	__nop__();__nop__();
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
	__nop__();__nop__();
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_LOW);
	__nop__();__nop__();
	*/
	SDA = 1;
	__nop__();__nop__();
	SCL = 1;
	__nop__();__nop__();
	SDA = 0;
	__nop__();__nop__();
}

void I2C_stop()
{
	/*
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_LOW);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_LOW);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_HIGH);
	*/
	SCL = 0;
	SDA = 0;
	SCL = 1;
	SDA = 1;
}
void I2C_Write(u8 Copy_u8Data)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		/*
		GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_LOW);
		GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,((Copy_u8Data&(0x80>>i))?1:0));
		GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
		*/
		SCL = 0;
		SDA = ((Copy_u8Data&(0x80>>i))?1:0);
		SCL = 1;
	}
}

u8 I2C_Read()
{
	u8 i,buffer=0;
	//u8 SDA_Value;
	for(i=0;i<8;i++)
	{
		/*
		GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_LOW);
		GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
		GPIO_u8GetPinValue(GPIO_U8PORT0,SDA,&SDA_Value);
		if(SDA_Value)
		{
			buffer|=0x80>>i;
		}
		*/
		SCL = 0;
		SCL = 1;
		if(SDA)
			buffer|=0x80>>i;
	}
	return buffer;
}

void I2C_Restart()
{
	/*
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_LOW);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_HIGH);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_LOW);
	*/
	SCL = 0;
	SDA = 1;
	SCL = 1;
	SDA = 0;
}

void I2C_Ack()
{
	/*
	u8 SDA_Value;
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_LOW);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_HIGH);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
	GPIO_u8GetPinValue(GPIO_U8PORT0,SDA,&SDA_Value);
	*/
	SCL = 0;
	SDA = 1;
	SCL = 1;
	while(SDA)
	{
		
	}
}

void I2C_NotAck()
{
	/*
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_LOW);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SDA,GPIO_U8PIN_HIGH);
	GPIO_u8SetPinValue(GPIO_U8PORT0,SCL,GPIO_U8PIN_HIGH);
	*/
	SCL = 0;
	SDA = 1;
	SCL = 1;
}
	















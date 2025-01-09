/*********************************************************************************/
/*********************************************************************************/
/*************************      Auther: karem heikal     *************************/
/*************************      layer : MCAL             *************************/
/*************************      SWC :   GPIO              *************************/
/*************************      Version:1.00             *************************/
/*********************************************************************************/
/*********************************************************************************/

//#include <reg51.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "GPIO/GPIO_register.h"
#include "GPIO/GPIO_config.h"
#include "GPIO/GPIO_interface.h" 




u8 GPIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8direction)
{
	u8 Local_u8ErrorState=OK;
	if(GPIO_U8PORT_OUTPUT==Copy_u8direction)
	{
		switch(Copy_u8Port)
		{
			case GPIO_U8PORT0 : PORT0 = GPIO_U8PORT_OUTPUT  ;break;
			case GPIO_U8PORT1	: PORT1 =	GPIO_U8PORT_OUTPUT  ;break;
			case GPIO_U8PORT2 : PORT2 =	GPIO_U8PORT_OUTPUT  ;break;
			case GPIO_U8PORT3 : PORT3 =	GPIO_U8PORT_OUTPUT  ;break;
			default : Local_u8ErrorState = NOTOK;
		}
	}
	else if(GPIO_U8PORT_INPUT==Copy_u8direction)
	{
		switch(Copy_u8Port)
		{
			case GPIO_U8PORT0 : PORT0 = GPIO_U8PORT_INPUT  ;break;
			case GPIO_U8PORT1	: PORT1 =	GPIO_U8PORT_INPUT  ;break;
			case GPIO_U8PORT2 : PORT2 =	GPIO_U8PORT_INPUT  ;break;
			case GPIO_U8PORT3 : PORT3 =	GPIO_U8PORT_INPUT  ;break;
			default : Local_u8ErrorState = NOTOK;
		}
	}
	else 
		Local_u8ErrorState = NOTOK;
	
	return Local_u8ErrorState;
}

u8 GPIO_u8SetPortValue(u8 Copy_u8Port,  u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
		case GPIO_U8PORT0 : PORT0 = Copy_u8Value  ;break;
		case GPIO_U8PORT1	: PORT1 =	Copy_u8Value  ;break;
		case GPIO_U8PORT2 : PORT2 =	Copy_u8Value  ;break;
		case GPIO_U8PORT3 : PORT3 =	Copy_u8Value  ;break;
		default : Local_u8ErrorState = NOTOK;
	}
	return Local_u8ErrorState;
}

u8 GPIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=OK;
	if(GPIO_U8PIN_OUTPUT==Copy_u8Value)
	{
		if((0<=Copy_u8Pin)&&(Copy_u8Pin<=7))
		{
			switch(Copy_u8Port)
			{
				case GPIO_U8PORT0:CLR_BIT(PORT0,Copy_u8Pin);break;
				case GPIO_U8PORT1:CLR_BIT(PORT1,Copy_u8Pin);break;
				case GPIO_U8PORT2:CLR_BIT(PORT2,Copy_u8Pin);break;
				case GPIO_U8PORT3:CLR_BIT(PORT3,Copy_u8Pin);break;
				default: Local_u8ErrorState=NOTOK;
			}
		}
		else
			Local_u8ErrorState=NOTOK;
	}
	else if(GPIO_U8PIN_INPUT == Copy_u8Value)
	{
		if((0<=Copy_u8Pin)&&(Copy_u8Pin<=7))
		{
			switch(Copy_u8Port)
			{
				case GPIO_U8PORT0:SET_BIT(PORT0,Copy_u8Pin);break;
				case GPIO_U8PORT1:SET_BIT(PORT1,Copy_u8Pin);break;
				case GPIO_U8PORT2:SET_BIT(PORT2,Copy_u8Pin);break;
				case GPIO_U8PORT3:SET_BIT(PORT3,Copy_u8Pin);break;
				default: Local_u8ErrorState=NOTOK;
			}
		}
		else
			Local_u8ErrorState=NOTOK;
	}
	else 
		Local_u8ErrorState = NOTOK;
	return Local_u8ErrorState;
}

u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=OK;
	if(GPIO_U8PIN_HIGH==Copy_u8Value)
	{
		if((0<=Copy_u8Pin)&&(Copy_u8Pin<=7))
		{
			switch(Copy_u8Port)
			{
				case GPIO_U8PORT0:SET_BIT(PORT0,Copy_u8Pin);break;
				case GPIO_U8PORT1:SET_BIT(PORT1,Copy_u8Pin);break;
				case GPIO_U8PORT2:SET_BIT(PORT2,Copy_u8Pin);break;
				case GPIO_U8PORT3:SET_BIT(PORT3,Copy_u8Pin);break;
				default: Local_u8ErrorState=NOTOK;
			}
		}
		else
			Local_u8ErrorState=NOTOK;
	}
	else if(GPIO_U8PIN_LOW==Copy_u8Value)
	{
		if((0<=Copy_u8Pin)&&(Copy_u8Pin<=7))
		{
			switch(Copy_u8Port)
			{
				case GPIO_U8PORT0:CLR_BIT(PORT0,Copy_u8Pin);break;
				case GPIO_U8PORT1:CLR_BIT(PORT1,Copy_u8Pin);break;
				case GPIO_U8PORT2:CLR_BIT(PORT2,Copy_u8Pin);break;
				case GPIO_U8PORT3:CLR_BIT(PORT3,Copy_u8Pin);break;
				default: Local_u8ErrorState=NOTOK;
			}
		}
		else
			Local_u8ErrorState=NOTOK;
	}
	return Local_u8ErrorState;
}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState=OK;
	u8 Local_u8TempPort = 0;
	if((0<=Copy_u8Pin)&&(Copy_u8Pin<=7))
		{
			switch(Copy_u8Port)
			{
				case GPIO_U8PORT0:	Local_u8TempPort = PORT0;
					*Copy_pu8Value = GET_BIT(Local_u8TempPort,Copy_u8Pin);break;
				case GPIO_U8PORT1:	Local_u8TempPort = PORT1;
					*Copy_pu8Value = GET_BIT(Local_u8TempPort,Copy_u8Pin);break;
				case GPIO_U8PORT2:	Local_u8TempPort = PORT2;
					*Copy_pu8Value = GET_BIT(Local_u8TempPort,Copy_u8Pin);break;
				case GPIO_U8PORT3:	Local_u8TempPort = PORT3;
					*Copy_pu8Value = GET_BIT(Local_u8TempPort,Copy_u8Pin);break;
				default: Local_u8ErrorState=NOTOK;
			}
		}
		else
			Local_u8ErrorState=NOTOK;
	
	return Local_u8ErrorState;
}




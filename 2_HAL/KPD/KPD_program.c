/*********************************************************************************/
/*********************************************************************************/
/*************************      Auther: karem heikal     *************************/
/*************************      layer : HAL             *************************/
/*************************      SWC :   KPD              *************************/
/*************************      Version:1.00             *************************/
/*********************************************************************************/
/*********************************************************************************/

#include "LIB/STD_TYPES.h"
#include "GPIO/GPIO_interface.h"
#include "KPD/KPD_private.h"
#include "KPD/KPD_config.h"
#include "KPD/KPD_interface.h"

void KPD_Init()
{
	GPIO_u8SetPortValue(KPD_PORT,0XFF);
}

u8 GetPressedKey()
{
	
	u8 Local_u8PressedState;
	static u8 Local_u8RowsArr[KPD_SIZE_ROW]=KPD_ROWS_ARR;
	static u8 Local_u8ColsArr[KPD_SIZE_COL]=KPD_COLS_ARR;
	
	static u8 Local_u8KeysArr[KPD_SIZE_ROW][KPD_SIZE_COL]=KPD_KEYS_ARR;
	u8 Local_u8Keypress = NOT_PRESSED;
	u8 RowsItration;
	u8 ColsItration;
	for(RowsItration=0;RowsItration<KPD_SIZE_ROW;RowsItration++)
	{
		GPIO_u8SetPinValue(KPD_PORT,Local_u8RowsArr[RowsItration],GPIO_U8PIN_LOW);
		for(ColsItration=0;ColsItration<KPD_SIZE_COL;ColsItration++)
		{
			GPIO_u8GetPinValue(KPD_PORT,Local_u8ColsArr[ColsItration],&Local_u8PressedState);
			if(Local_u8PressedState==GPIO_U8PIN_LOW)
			{
				Local_u8Keypress = Local_u8KeysArr[RowsItration][ColsItration];
				while(Local_u8PressedState==GPIO_U8PIN_LOW)
				{
					GPIO_u8GetPinValue(KPD_PORT,Local_u8ColsArr[ColsItration],&Local_u8PressedState);
				}
				return Local_u8Keypress;
			}
		}
		GPIO_u8SetPinValue(KPD_PORT,Local_u8RowsArr[RowsItration],GPIO_U8PIN_HIGH);
	}
	return Local_u8Keypress;
}


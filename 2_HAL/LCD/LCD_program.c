





#include <reg51.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LCD/LCD_private.h"
#include "LCD/LCD_config.h"
#include "LCD/LCD_interface.h"


void lcd_cmd(u8 command)  //Function to send command instruction to LCD

{

    display_port = command;

    RS= 0;

    RW=0;

    E=1;

    msdelay(1);

    E=0;

}


void lcd_data(u8 disp_data)  //Function to send display data to LCD

{

    display_port = disp_data;

    RS= 1;

    RW=0;

    E=1;

    msdelay(1);

    E=0;

}


 void lcd_init()    //Function to prepare the LCD  and get it ready
{

    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD

    msdelay(10);

    lcd_cmd(0x0F);  // turn display ON, cuRSor blinking

    msdelay(10);

    lcd_cmd(0x01);  //clear screen

    msdelay(10);

    lcd_cmd(0x80);  // bring cuRSor to position 1 of line 1

    msdelay(10);


}
void LCD_String(const char * Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		lcd_data(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_WriteNumber(u16 Copy_u16Number)
{

	u8 Max_Digits = Num_length(Copy_u16Number);
	s8 i;
	for (i = Max_Digits; i > 0; i--) {
		lcd_data((Copy_u16Number / Multi_N_10(i - 1)) + '0');
		Copy_u16Number = (Copy_u16Number % Multi_N_10(i - 1));
	}
}
static void msdelay(u16 time){

    u16 i,j ;

    for(i=0;i<time;i++)    

    for(j=0;j<1275;j++);

}

static u8 Num_length(u16 num)
{
	u8 Local_u8Cnt = 0;
	if(num==0)
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

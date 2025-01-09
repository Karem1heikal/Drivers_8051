

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
void lcd_init(); 
void lcd_cmd(u8 command);
void lcd_data(u8 disp_data);
void LCD_String(const char * Copy_pcString);

void LCD_WriteNumber(u16 Copy_u16Number);

#endif
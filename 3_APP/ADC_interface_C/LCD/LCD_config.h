

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define display_port P1      //Data pins connected to port 2 on microcontroller

sbit RS = P0^0;  //RS pin connected to pin 2 of port 3
sbit RW = P0^2;  // RW pin connected to pin 3 of port 3
sbit E =  P0^1;  //E pin connected to pin 4 of port 3

#endif
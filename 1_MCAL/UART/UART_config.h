
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* Set baud rate of Uart 
 * 	
 * */
#define BR_9600 	-3
#define BR_4800		-6
#define BR_2400		-12
#define BR_1200		-24

#define UART_BAUD_RATE 	BR_9600

/* Set Serial mode of Uart 
 * 	1- MODE0	==> 8-bit shift register
 * 	2- MODE1    ==> 8-bit UART -- with party bit
 * 	3- MODE2    ==> 9-bit UART 
 * 	4- MODE3    ==> 9-bit UART
 * */

#define UART_MODE	MODE1

#endif
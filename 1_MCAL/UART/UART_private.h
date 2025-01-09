
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define TIMER_MODE2 0x20
#define MODE_MASK 	0x0f

#define MODE0	0X10
#define MODE1	0X50
#define MODE2	0X90
#define MODE3	0XD0

#define IDLE 	0
#define BUSY 	1

static u8 Num_length(u16 num);
static u16 Multi_N_10(u8 N) ;
#endif

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init();

void UART_SendSynch(u8 Copy_u8Data);

void UART_SendString(const char * str);

void UART_SendNumber(u32 Copy_u32Number);

u8 UART_RecvSynch(void);

u16 UART_ReceiveNum();

u8 UART_u8Send_Asynch(u8 Copy_u8Data,void *(Notifction)());

u8 UART_u8Recv_Asynch(u8 *Copy_pu8Data,void *(Notifction)());

#endif
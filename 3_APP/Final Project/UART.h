#ifndef UART_COMMUNICATION
#define UART_COMMUNICATION

void UART_Init();
void UART_SendChar(char c);
char UART_ReceiveChar();
void UART_SendString(char *str);

#endif //UART_COMMUNICATION
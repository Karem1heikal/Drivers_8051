#include <reg52.h>
#include "UART.h"

// Initialize UART
void UART_Init() {
    SCON = 0x50; // Mode 1: 8-bit UART
    TMOD |= 0x20; // Timer 1 in Mode 2
    TH1 = 0xFD; // 9600 baud rate
    TR1 = 1; // Start Timer 1
}

// Send a character via UART
void UART_SendChar(char c) {
    SBUF = c;
    while (!TI);
    TI = 0;
}

// Receive a character via UART
char UART_ReceiveChar() {
    while (!RI);
    RI = 0;
    return SBUF;
}

// Send a string via UART
void UART_SendString(char *str) {
    while (*str) {
        UART_SendChar(*str++);
    }
}

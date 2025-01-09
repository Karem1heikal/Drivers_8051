#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_init();

void SPI_SEND(u8 Copy_u8Data);
u8 SPI_RECV();
u8 SPI_TRANSCIVE(u8 Copy_u8Data);
#endif
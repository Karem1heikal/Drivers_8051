

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
/*
#define SDA		GPIO_U8PIN6
#define SCL		GPIO_U8PIN7
*/

sbit SDA =P0^6;
sbit SCL =P0^7;

void I2C_start();
void I2C_stop();

void I2C_Restart();

void I2C_Write(u8 Copy_u8Data);
u8 I2C_Read();

void I2C_Ack();
void I2C_NotAck();


#endif
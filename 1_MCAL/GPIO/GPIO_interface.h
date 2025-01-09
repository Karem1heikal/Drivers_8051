/*********************************************************************************/
/*********************************************************************************/
/*************************      Auther: karem heikal     *************************/
/*************************      layer : MCAL             *************************/
/*************************      SWC :   GPIO              *************************/
/*************************      Version:1.00             *************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_U8PIN_OUTPUT 		0
#define GPIO_U8PIN_INPUT 			1
						 
#define GPIO_U8PORT_OUTPUT 		0
#define GPIO_U8PORT_INPUT 		0xff
						 
						 
#define GPIO_U8PIN_HIGH  	1
#define GPIO_U8PIN_LOW  	0
						 
#define GPIO_U8PORT_HIGH  	0xff
#define GPIO_U8PORT_LOW  		0
						 
#define GPIO_U8PORT0   0
#define GPIO_U8PORT1   1
#define GPIO_U8PORT2   2
#define GPIO_U8PORT3   3
						 
#define GPIO_U8PIN0   0
#define GPIO_U8PIN1   1
#define GPIO_U8PIN2   2
#define GPIO_U8PIN3   3
#define GPIO_U8PIN4   4
#define GPIO_U8PIN5   5
#define GPIO_U8PIN6   6
#define GPIO_U8PIN7   7
		
u8 GPIO_u8SetPortValue(u8 Copy_u8Port,  u8 Copy_u8Value);
 
u8 GPIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
   
u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
  
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);
u8 GPIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8direction);


#endif // GPIO_INTERFACE_H_





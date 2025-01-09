/*********************************************************************************/
/*********************************************************************************/
/*************************      Auther: karem heikal     *************************/
/*************************      layer : HAL             *************************/
/*************************      SWC :   KPD              *************************/
/*************************      Version:1.00             *************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT  GPIO_U8PORT2

#define KPD_ROW0	GPIO_U8PIN0
#define KPD_ROW1  GPIO_U8PIN1
#define KPD_ROW2  GPIO_U8PIN2
#define KPD_ROW3  GPIO_U8PIN3

#define KPD_COL0  GPIO_U8PIN4
#define KPD_COL1  GPIO_U8PIN5
#define KPD_COL2  GPIO_U8PIN6
#define KPD_COL3  GPIO_U8PIN7

#define KPD_SIZE_ROW	4
#define KPD_SIZE_COL	4

#define KPD_KEYS_ARR {{'7','8','9','/'},\
											{'4','5','6','*'},\
											{'1','2','3','-'},\
											{'C','0','=','+'}}


#endif
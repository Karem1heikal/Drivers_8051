/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : MCAL         **********************************/
/************************* SWC    : EXTI          **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define Low_Level   	1
#define Falling_Edge	2

#define EXTI_INT0_ENABLE	1
#define EXTI_INT0_DISABLE	2

#define EXTI_INT1_ENABLE	3
#define EXTI_INT1_DISABLE	4
/*
			//====== before doing interrupt you must enable (global interrupt enable) ======//
*/
void EXTI_u8GlobalIntEnable();
void EXTI_u8GlobalIntDisable();

void EXTI_voidInt0Init();
void EXTI_voidInt1Init();

/* Description : A function to set the required sense control of INT0 using post build configuration
 * input : Copy_u8Sense :
 * 					1- Low_Level
 * 					2- Falling_Edge
 * 	output: Error state with type u8
 * */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

/* Description : A function to set the required sense control of INT1 using post build configuration
 * input : Copy_u8Sense :
 * 					1- Low_Level
 * 					2- Falling_Edge
 * 			
 * 	output: Error state with type u8
 * */
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

/* Description : A function to set the required peripheral interrupt enable of INT0 using post build configuration
 * input : Copy_u8Int :
 * 					1- EXTI_INT0_ENABLE
 * 					2- EXTI_INT1_ENABLE
 * 	output: Error state with type u8
 * */
u8 EXTI_u8IntEnable(u8 Copy_u8INT);
u8 EXTI_u8IntDisable(u8 Copy_u8INT);

u8 EXTI_u8Int0CallBack(void (*Copy_pvInt0Func)());
u8 EXTI_u8Int1CallBack(void (*Copy_pvInt1Func)());
#endif

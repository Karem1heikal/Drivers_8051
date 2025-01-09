/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : MCAL         **********************************/
/************************* SWC    : EXTI          **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "EXTI/EXTI_interface.h"
#include "EXTI/EXTI_private.h"
#include "EXTI/EXTI_config.h"
#include "EXTI/EXTI_register.h"

/*Global pointer to function  */
void (*EXTI_Int0Call_Back_func)()=NULL;

void (*EXTI_Int1Call_Back_func)()=NULL;

void EXTI_voidInt0Init(){

#if	INT0_INITIAL_ENABLE == ENABLE
	/*Peripheral interrupt Enable for INT0*/
		SET_BIT(IE,IE_EX0);
#elif INT0_INITIAL_ENABLE == DISABLEx
		CLR_BIT(IE,IE_EX0);
#else
#error "Wrong, for choosing configuration of enable interrupt 0 "
#endif
		/*Set sence control for INT0 */
#if EXTI_INT0_SCTRL==Falling_Edge
	SET_BIT(TCON,TCON_IT0);
#elif EXTI_INT0_SCTRL==Low_Level
	CLR_BIT(TCON,TCON_IT0);
#else
#error "Wrong, for choosing configuration of sence control(0) "
#endif
	// Enable Glopal interrupt
	//SET_BIT(IE,IE_EA);
	
}
void EXTI_voidInt1Init()
{
	/*Set sence control for INT1 */
#if EXTI_INT1_SCTRL==Falling_Edge
	SET_BIT(TCON,TCON_IT1);
#elif EXTI_INT1_SCTRL==Low_Level
	CLR_BIT(TCON,TCON_IT1);
#else
#error "Wrong, for choosing configuration of sence control(1) "
#endif
#if	INT1_INITIAL_ENABLE == ENABLE
	/*Peripheral interrupt Enable for INT1*/
	SET_BIT(IE,IE_EX1);
#elif INT1_INITIAL_ENABLE == DISABLEx
	CLR_BIT(IE,IE_EX1);
#else
#error "Wrong, for choosing configuration of enable interrupt 1 "
#endif
	// Enable Glopal interrupt
	//SET_BIT(IE,IE_EA);
}

void EXTI_u8GlobalIntEnable()
{
	SET_BIT(IE,IE_EA);
}
void EXTI_u8GlobalIntDisable()
{
	CLR_BIT(IE,IE_EA);
}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8Sense)
	{
		case Falling_Edge:
			SET_BIT(TCON,TCON_IT0);
			break;
		case Low_Level:
			CLR_BIT(TCON,TCON_IT0);
			 break;
		default:
			Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8Sense)
	{
		case Falling_Edge:
			SET_BIT(TCON,TCON_IT1);
			break;
		case Low_Level:
			 CLR_BIT(TCON,TCON_IT1);
			 break;
		default:
			Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8INT)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8INT)
	{
	case EXTI_INT0_ENABLE:
		SET_BIT(IE,IE_EX0);
		break;
	case EXTI_INT1_ENABLE:
		SET_BIT(IE,IE_EX1);
		break;
	default:
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8IntDisable(u8 Copy_u8INT)
{
	u8 Local_u8ErrorState=0;
		switch(Copy_u8INT)
		{
		case EXTI_INT0_DISABLE:
			CLR_BIT(IE,IE_EX0);
			break;
		case EXTI_INT1_DISABLE:
			CLR_BIT(IE,IE_EX1);
			break;
		default:
			Local_u8ErrorState=1;
		}
		return Local_u8ErrorState;
}
u8 EXTI_u8Int0CallBack(void (*Copy_pvInt0Func)())
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt0Func != NULL)
		EXTI_Int0Call_Back_func=Copy_pvInt0Func;
	else
		Local_u8ErrorState=NULL_POINTER;
	return Local_u8ErrorState;
}
u8 EXTI_u8Int1CallBack(void (*Copy_pvInt1Func)())
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt1Func != NULL)
		EXTI_Int1Call_Back_func=Copy_pvInt1Func;
	else
		Local_u8ErrorState=NULL_POINTER;
	return Local_u8ErrorState;
}

void INT0_FUNC() interrupt 0 
{
	if(EXTI_Int0Call_Back_func!=NULL)
		EXTI_Int0Call_Back_func();
	else
	{
		
	}
}
void INT1_FUNC() interrupt 2
{
	if(EXTI_Int1Call_Back_func!=NULL)
		EXTI_Int1Call_Back_func();
	else{
	}
}


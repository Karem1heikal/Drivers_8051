


#include <reg52.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "RTOS_stack/RTOS_interface.h"
#include "RTOS_stack/RTOS_private.h"
#include "RTOS_stack/RTOS_config.h"

//timer0 config
void (*Global_pvTimer0Func)() = NULL;

u8	TIMER0_u8SetCallBack(void (*copy_vFunc)())
{
	u8 Local_u8ErrorState=OK;
	if(copy_vFunc!=NULL)
	{
		Global_pvTimer0Func=copy_vFunc;
	}
	else
		Local_u8ErrorState = NULL_POINTER;
	return Local_u8ErrorState;
}

void Timer0INT() interrupt 1
{
	if(Global_pvTimer0Func!=NULL)
	{
		Global_pvTimer0Func();
		TH0 = 0X03; 
		TL0 = 0X99;
	}
}

// RTOS config
Task_t SystemTasks[TASK_NUM] = {{NULL}};


void RTOS_voidStart()
{
	
	TMOD = 1;
	TIMER0_u8SetCallBack(voidScheduler);
  // 1MS TICKS
	TH0 = 0X03; 
	TL0 = 0X99;
	IE = 0X82;
	TR0 = 1;
}

u8 RTOS_u8CreateTask(u8 Copy_u8Periority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(),Copy_u16FirstDelay){
u8 Local_u8ErrorState=OK;
	// check if the required priority is empty or used before for another task
	if(SystemTasks[Copy_u8Periority].TaskFunc==NULL){
		SystemTasks[Copy_u8Periority].Periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Periority].TaskFunc = Copy_pvTaskFunc;
		SystemTasks[Copy_u8Periority].FirstDelay = Copy_u16FirstDelay;
	}
	else // priority is reserved before ,don't create the task
		Local_u8ErrorState=NULL_POINTER;
	return Local_u8ErrorState;
}
static void voidScheduler()
{
	// Correct the problem  of tick Counter
	u8 Local_u8TaskCounter = 0;
	// Loop on tasks to check their periodicity
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
			if(SystemTasks[Local_u8TaskCounter].FirstDelay == 0)
			{
				// Invoke the function
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();
					// Assign the first delay to the Periodicity
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity - 1;
				}
				else
				{
					// Do nothing
				}
			}
			else
			{
				SystemTasks[Local_u8TaskCounter].FirstDelay--;
			}
		}
}
/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : RTOS Stack    **********************************/
/************************* SWC    : RTOS        **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct 
{
	u16 Periodicity;
	u16 FirstDelay;
	void (*TaskFunc)();
} Task_t;

static void voidScheduler();

#endif

/*********************************************************************************/
/************************* Author : karem heikal **********************************/
/************************* layer  : MCAL         **********************************/
/************************* SWC    : EXTI         **********************************/
/************************* Version: 1.00         **********************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
 *  Set sense control(0) 		Description
 *  ----------------------------------------------------------------------
 * 	Low_Level    	-->		The low level of INT0 generates an interrupt request.
 *  Falling_Edge	--> 	The falling edge of INT0 generates an interrupt request.
 * */
#define EXTI_INT0_SCTRL		Falling_Edge

/*
 *  Set sense control(1) 		Description
 *  ----------------------------------------------------------------------
 * 	Low_Level    	-->		The low level of INT1 generates an interrupt request.
 *  Falling_Edge	--> 	The falling edge of INT1 generates an interrupt request.
 * */
#define EXTI_INT1_SCTRL		Falling_Edge

/*
 * Peripheral interrupt Enable
 * 			1-ENABLE
 * 			2-DISABLE
 * */


#define	INT0_INITIAL_ENABLE		ENABLE

#define	INT1_INITIAL_ENABLE		ENABLE


#endif


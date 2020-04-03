/*
 * Sos_Lcfg.c
 *
 *  Created on: Jan 19, 2020
 *      Author: Ahemd_Elbadwi 
 */


/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "Sos_Lcfg.h"
#include "Timer.h"
/*************************************************************************/
/*                         Static #Defines                               */
/*************************************************************************/
#define SYS_TICK_MSEC   (1U)
/*************************************************************************/
/*                         Typedefs                                      */
/*************************************************************************/

/*************************************************************************/
/*                         Link Configuration Variable                   */
/*************************************************************************/
const SosInit_cfg_t gstr_SosInit_cfg=
{
	.u8_TimerChId=TIMER_CH0,
	.u8_SysTick = SYS_TICK_MSEC
};




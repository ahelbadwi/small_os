/*
 *  File Name    : SosApp_Lcfg.c
 *  Description  : Tasks Linking configuration parameters
 *  Created on   : Jan 21, 2020
 *  Author       : Ahemd_Elbadwi
 */

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "SosApp.h"

/*************************************************************************/
/*          Linking configuration parameters Definitions                 */
/*************************************************************************/

CreatTask_cfg_t gstr_Task1Cfg=
{
		.Task_State=TASK_IDLE_STATE,
		.pfun_CyclicTask=Task1,
		.u8_periodicity=5,
		.u8_priority=1
};

CreatTask_cfg_t gstr_Task2Cfg=
{
		.Task_State=TASK_IDLE_STATE,
		.pfun_CyclicTask=Task2,
		.u8_periodicity=3,
		.u8_priority=0

};

CreatTask_cfg_t gstr_Task3Cfg=
{
		.Task_State=TASK_IDLE_STATE,
		.pfun_CyclicTask=Task3,
		.u8_periodicity=8,
		.u8_priority=2
};


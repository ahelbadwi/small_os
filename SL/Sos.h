/*
 * Sos.h
 *
 *  Created on: Jan 19, 2020
 *      Author: Ahemd_Elbadwi 
 */

#ifndef SOS_H_
#define SOS_H_

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/

#include "std_types.h"
#include "Utils.h"
#include "General_Macros.h"
#include "Retval.h"
#include "Sos_Lcfg.h"
#include "Sos_Cfg.h"
/*************************************************************************/
/*                         #Defines                                      */
/*************************************************************************/
#define TASK_IDLE_STATE      ((en_Task_State_t)0)
#define TASK_READY_STATE     ((en_Task_State_t)1)
#define TASK_RUNNING_STATE   ((en_Task_State_t)2)
#define TASK_WAITTING_STATE  ((en_Task_State_t)3)
/*************************************************************************/
/*                         Typedef                                       */
/*************************************************************************/
typedef ErrorStatus_t (*Sos_FunToDelete_t) (void);

typedef uint8 en_Task_State_t;

typedef struct CreatTask_cfg_t
{
	ErrorStatus_t (*pfun_CyclicTask)(void);
	uint8 u8_priority;
	uint8 u8_periodicity;
	en_Task_State_t Task_State;
}CreatTask_cfg_t;

/*************************************************************************/
/*                         Api.s Exports                                 */
/*************************************************************************/

/*******************************************************************************
 * 	Function name: 		Sos_Init
 *
 * 	Description  :      Initialize system tick timer and configure it
 * 	                    with passed system tick
 *
 * 	Arguments:
 * 		-				Timer Channel Id
 * 		                System tick
 *
 * 	Return:
 * 		-				ERROR_STATUS to report success or failure
 *******************************************************************************/
extern void Sos_Init(const SosInit_cfg_t* pstr_SosInit_Cfg);
/*******************************************************************************
 * 	Function name: 		Sos_Run
 *
 * 	Description  :      Sos Scheduler that decide which task has to run every system tick and call it.
 *
 * 	Arguments:
 * 		-				NA
 *
 * 	Return:
 * 		-				ERROR_STATUS to report success or failure
 *******************************************************************************/

extern ErrorStatus_t Sos_Run(void);

/*******************************************************************************
 * 	Function name: 		Sos_CreateTask
 *
 * 	Description  :      Add new Task to the (time line)Sos Buffer
 *
 * 	Arguments:
 * 		-		        pstr_TaskCfg:Task configuration to be added to the sos buffer
 *
 * 	Return:
 * 		-				ERROR_STATUS to report success or failure
 *******************************************************************************/

extern ErrorStatus_t Sos_CreateTask(CreatTask_cfg_t* pstr_TaskCfg);

/*******************************************************************************
 * 	Function name: 		Sos_DeleteTask
 *
 * 	Description  :      remove certain Task from (Time Line)Sos Buffer.
 *
 * 	Arguments:
 * 		-		        pfun_FunToDelete:Task to be deleted from the(time line)sos buffer
 *
 * 	Return:
 * 		-				ERROR_STATUS to report success or failure
 *******************************************************************************/

extern ErrorStatus_t Sos_DeleteTask(Sos_FunToDelete_t pfun_TaskToDelete);







#endif /* SOS_H_ */

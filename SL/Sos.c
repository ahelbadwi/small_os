/*
 *  File Name        : Sos.c
 *  Layer            : Service Layer
 *  File Description : Contains Sos main used Api.s
 *  Created on: Jan 19, 2020
 *  Author: Ahemd_Elbadwi
 */

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "Sos.h"
#include "Timer.h"
#include "interrupt.h"
#include "sleep.h"

/*************************************************************************/
/*                         Typedef                                       */
/*************************************************************************/


/*************************************************************************/
/*                        #Defines                                       */
/*************************************************************************/
#define LCM (120U)
/*************************************************************************/
/*                         Static Global Variables                       */
/*************************************************************************/
static ErrorStatus_t gErrorStatus_Sos_Init;
static bool gb_SysTickFlag;
static uint16 gu16_TimerPrelodValue;
static volatile uint8 gu8_SysTickCounter;
static CreatTask_cfg_t gastr_SosTaskCfg_Buffer[MAX_NO_TASKS];
static uint8 gu8_SosCurentTaskBufferSize;
static uint8 gu8_SysTickValue;
/*************************************************************************/
/*                         CBF                                           */
/*************************************************************************/
/*******************************************************************************
 * 	Function name: 		Timer_Cbf
 *
 * 	Description  :     increment Sys Tick Counter and  Set Sys Tick Flag
 *
 * 	Arguments:
 * 		-				Na
 * 	Return:
 * 		-				ERROR_STATUS to report success or failure
 *******************************************************************************/

static ErrorStatus_t Timer_Tick_Cbf(void)
{
	ErrorStatus_t ErrorStatus_Timer_Cbf=SUCCESS;
	/*Set Sys Tick interrupt Flag */
	gb_SysTickFlag=TRUE;
	/* preload timer every beginning to achieve SysTick */
	Timer_SetValue(gstr_SosInit_cfg.u8_TimerChId,gu16_TimerPrelodValue);
	return ErrorStatus_Timer_Cbf;
}

/*************************************************************************/
/*                        static Functions                               */
/*************************************************************************/
/*******************************************************************************
 * 	Function name: 		Sos_IdleTask
 *
 * 	Description  :      enter the controller into sleep mode
 *
 * 	Arguments:
 * 		-				NA
 *
 * 	Return:
 * 		-				ERROR_STATUS to report success or failure
 *******************************************************************************/
static ErrorStatus_t Sos_IdleTask(void)
{
	ErrorStatus_t ErrorStatus_Sos_IdleTask=SUCCESS;
	CPU_Sleep(IDLE);
	return ErrorStatus_Sos_IdleTask;

}
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
void Sos_Init(const SosInit_cfg_t* pstr_SosInit_Cfg)
{
	ErrorStatus_t ErrorStatus_TimerInit=TIMER_ERROR;
	uint8 u8_SosTaskBuffer_Index;
	/* Initialize Global Variables */
	gErrorStatus_Sos_Init=SOS_BASE_ERROR+SUCCESS;
	gb_SysTickFlag=ZERO_VALUE;
	gu16_TimerPrelodValue=ZERO_VALUE;
	gu8_SysTickCounter=ZERO_VALUE;
	gu8_SosCurentTaskBufferSize=ZERO_VALUE;
	gu8_SysTickValue=pstr_SosInit_Cfg->u8_SysTick;
	for(u8_SosTaskBuffer_Index=ZERO_VALUE;u8_SosTaskBuffer_Index<MAX_NO_TASKS;u8_SosTaskBuffer_Index++)
	{
		gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].Task_State=TASK_IDLE_STATE;
		gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].pfun_CyclicTask=NULL;
		gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].u8_periodicity=ZERO_VALUE;
		gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].u8_priority=ZERO_VALUE;
	}
	/* Configure Timer */
	Timer_cfg_s Timer_cfg;
	Timer_cfg.Timer_CBF=Timer_Tick_Cbf;
	Timer_cfg.Timer_CH_NO=pstr_SosInit_Cfg->u8_TimerChId;
	Timer_cfg.Timer_Mode=TIMER_MODE;
	Timer_cfg.Timer_Polling_Or_Interrupt=TIMER_INTERRUPT_MODE;
	Timer_cfg.Timer_Prescaler=TIMER_TICK_PRESCALLER;
	/* Init Timer */
	ErrorStatus_TimerInit=Timer_Init(&Timer_cfg);
	if(SUCCESS != ErrorStatus_TimerInit)
	{
		gErrorStatus_Sos_Init=SOS_BASE_ERROR+TIMER_ERROR;
	}
	else
	{
		/* Do Nothing */
	}
}

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

ErrorStatus_t Sos_Run(void)
{
	ErrorStatus_t ErrorStatus_SosRun=SUCCESS;
	uint8 u8_priority,u8_sosBuffer_index;
	/*
	 * Calculate Timer PreValue to maintain Sys_tick Interrupt as I don't have Option
	 *  Of CTC Mode In the Infrastructure code of Timer module.
	 */
	uint16 u16_TimerCounts=((F_CPU*gu8_SysTickValue)/(TIMER_TICK_PRESCALLER_VALUE*1000));
	gu16_TimerPrelodValue=(TIMER_TICK_MAX_COUNTS-u16_TimerCounts);
	/* start system tick timer */
	Timer_Start(gstr_SosInit_cfg.u8_TimerChId,u16_TimerCounts);

	/* Check if the Sos is actually Initialized */
	if(SUCCESS == gErrorStatus_Sos_Init-SOS_BASE_ERROR)
	{
		/* Super loop */
		while(1)
		{
			if(TRUE == gb_SysTickFlag)
			{
				gb_SysTickFlag=FALSE;
				/* Increment Sys tick Counter */
				gu8_SysTickCounter++;
				/* Reset system tick counter each scheduler window = LCM */
				if(LCM == gu8_SysTickCounter)
				{
					gu8_SysTickCounter=0;
				}
				else
				{
					for(u8_priority=ZERO_VALUE;u8_priority <= MIN_PRIORITY;u8_priority++)
					{
						for(u8_sosBuffer_index=ZERO_VALUE;u8_sosBuffer_index<gu8_SosCurentTaskBufferSize;u8_sosBuffer_index++)
						{
							/* check periodicity and priority */
							if(gu8_SysTickCounter % gastr_SosTaskCfg_Buffer[u8_sosBuffer_index].u8_periodicity==ZERO_VALUE)
							{
								gastr_SosTaskCfg_Buffer[u8_sosBuffer_index].Task_State=TASK_READY_STATE;
								if(u8_priority==gastr_SosTaskCfg_Buffer[u8_sosBuffer_index].u8_priority)
								{
									gastr_SosTaskCfg_Buffer[u8_sosBuffer_index].Task_State=TASK_RUNNING_STATE;
									gastr_SosTaskCfg_Buffer[u8_sosBuffer_index].pfun_CyclicTask();
									gastr_SosTaskCfg_Buffer[u8_sosBuffer_index].Task_State=TASK_WAITTING_STATE;
								}
								else
								{
									/* Do Nothing */
								}
							}
							else
							{
								/* Do Nothing */
							}
						}

					}
					/* execute idle task after scheduler execution each system tick */
					Sos_IdleTask();
				}
			}
			else
			{
				/* Do Nothing */
			}
		}

	}
	else
	{
		ErrorStatus_SosRun=NOT_INITIALIZED_ERROR;
	}
	return (SOS_BASE_ERROR+ErrorStatus_SosRun);
}

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

ErrorStatus_t Sos_CreateTask(CreatTask_cfg_t* pstr_TaskCfg)
{
	static uint8 u8_SosTaskBuffer_Index=0;
	ErrorStatus_t ErrorStatus_SosCreateTask=SUCCESS;
	if(NULL != pstr_TaskCfg)
	{
		/* check availability of Sos Task Buffer */
		if(u8_SosTaskBuffer_Index < MAX_NO_TASKS)
		{
			/* Fill SosTask_Buffer */
			gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].Task_State=TASK_READY_STATE;
			gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].pfun_CyclicTask=pstr_TaskCfg->pfun_CyclicTask;
			gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].u8_periodicity=pstr_TaskCfg->u8_periodicity;
			gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].u8_priority=pstr_TaskCfg->u8_priority;
			u8_SosTaskBuffer_Index++;
			gu8_SosCurentTaskBufferSize++;
		}
		else
		{
			ErrorStatus_SosCreateTask=BUFFER_FULL_ERROR;
		}
	}
	else
	{
		ErrorStatus_SosCreateTask=NULL_PTR_ERROR;
	}
	return (SOS_BASE_ERROR+ErrorStatus_SosCreateTask);
}

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

ErrorStatus_t Sos_DeleteTask(Sos_FunToDelete_t pfun_TaskToDelete)
{
	ErrorStatus_t ErrorStatus_Sos_DeleteTask=SUCCESS;
	/* two Local variables as a counters */
	uint8 u8_SosTaskBuffer_Index,u8_Index;
	if(NULL != pfun_TaskToDelete)
	{
		/* loop till Find Index of Required function to Delete in SosTaskBuffer */
		for(u8_SosTaskBuffer_Index=ZERO_VALUE;u8_SosTaskBuffer_Index < gu8_SosCurentTaskBufferSize;u8_SosTaskBuffer_Index++)
		{
			/* Search to the function to be deleted in the sos task buffer */
			if(gastr_SosTaskCfg_Buffer[u8_SosTaskBuffer_Index].pfun_CyclicTask == pfun_TaskToDelete)
			{
				/* remove the required function to delete = Shift gastr_SosTaskCfg_Buffer and decrease gu8_SosCurentTaskBufferSize by one */
				for(u8_Index=u8_SosTaskBuffer_Index;u8_Index < gu8_SosCurentTaskBufferSize;u8_Index++)
				{
					gastr_SosTaskCfg_Buffer[u8_Index].Task_State         =gastr_SosTaskCfg_Buffer[u8_Index+1].Task_State;
					gastr_SosTaskCfg_Buffer[u8_Index].pfun_CyclicTask    =gastr_SosTaskCfg_Buffer[u8_Index+1].pfun_CyclicTask;
					gastr_SosTaskCfg_Buffer[u8_Index].u8_periodicity     =gastr_SosTaskCfg_Buffer[u8_Index+1].u8_periodicity;
					gastr_SosTaskCfg_Buffer[u8_Index].u8_priority        =gastr_SosTaskCfg_Buffer[u8_Index+1].u8_priority;
				}
			}
			/* decrease gu8_SosCurentTaskBufferSize by one */
			gu8_SosCurentTaskBufferSize--;
		}
	}
	else
	{
		ErrorStatus_Sos_DeleteTask=NULL_PTR_ERROR;
	}

	return (SOS_BASE_ERROR+ErrorStatus_Sos_DeleteTask);
}



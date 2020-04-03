/*
 *  main.c
 *
 *  Created on: Jan 19, 2020
 *  Author: Ahemd_Elbadwi
 */

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "SosApp.h"
/*************************************************************************/
/*                         main Function                                 */
/*************************************************************************/
int main(void)
{
	Tasks_Init();
	Sos_Init(&gstr_SosInit_cfg);
	/* Task creations */
	Sos_CreateTask(&gstr_Task1Cfg);
	Sos_CreateTask(&gstr_Task2Cfg);
	Sos_CreateTask(&gstr_Task3Cfg);
	/* Sos scheduler */
	Sos_Run();
	return 0;
}

/*
 *  File Name : SosApp.c
 *  Layer     : Application Layer
 *  Created on: Jan 20, 2020
 *  Author: Ahemd_Elbadwi
 */

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/

#include "SosApp.h"

/*************************************************************************/
/*                         Tasks definitions                             */
/*************************************************************************/

ErrorStatus_t Task1(void)
{
	ErrorStatus_t ErrorStatus_Task1=SUCCESS;
	TOGGLE_BIT(PORTB_DATA,0);
	return ErrorStatus_Task1;
}

ErrorStatus_t Task2(void)
{
	ErrorStatus_t ErrorStatus_Task1=SUCCESS;
	TOGGLE_BIT(PORTB_DATA,1);
	return ErrorStatus_Task1;
}

ErrorStatus_t Task3(void)
{
	ErrorStatus_t ErrorStatus_Task1=SUCCESS;
	TOGGLE_BIT(PORTB_DATA,2);
	return ErrorStatus_Task1;
}

/*************************************************************************/
/*                         Tasks initialization                          */
/*************************************************************************/

ErrorStatus_t Tasks_Init(void)
{
	ErrorStatus_t ErrorStatus_Tasks_Init=SUCCESS;
	SET_BIT(PORTB_DIR,0);
	SET_BIT(PORTB_DIR,1);
	SET_BIT(PORTB_DIR,2);
	SET_BIT(PORTA_DIR,0);
	return ErrorStatus_Tasks_Init;
}


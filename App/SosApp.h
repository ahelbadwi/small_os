/*
 * SosApp.h
 *
 *  Created on: Jan 20, 2020
 *      Author: Ahemd_Elbadwi 
 */

#ifndef SOSAPP_H_
#define SOSAPP_H_

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "std_types.h"
#include "DIO.h"
#include "Sos.h"
#include "SosApp_Lcfg.h"
/*************************************************************************/
/*                         #Defines                                      */
/*************************************************************************/
/*************************************************************************/
/*                        Api.s exports                                  */
/*************************************************************************/
extern ErrorStatus_t Tasks_Init(void);
extern ErrorStatus_t Task1(void);
extern ErrorStatus_t Task2(void);
extern ErrorStatus_t Task3(void);

#endif /* SOSAPP_H_ */

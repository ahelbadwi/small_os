/*
 * Sos_Lcfg.h
 *
 *  Created on: Jan 19, 2020
 *  Author: Ahemd_Elbadwi
 */

#ifndef SOS_LCFG_H_
#define SOS_LCFG_H_

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "std_types.h"
#include "Retval.h"
/*************************************************************************/
/*                         TypeDef.s                                     */
/*************************************************************************/

typedef struct SosInit_cfg_t
{
	uint8 u8_TimerChId;
	uint8 u8_SysTick;
}SosInit_cfg_t;

/*************************************************************************/
/*                           Exports                                     */
/*************************************************************************/
extern const SosInit_cfg_t gstr_SosInit_cfg;

#endif /* SOS_LCFG_H_ */

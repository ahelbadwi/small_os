/*
 * Sos_Cfg.h
 *
 *  Created on: Jan 19, 2020
 *      Author: Ahemd_Elbadwi 
 */
/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "Timer.h"

#ifndef SOS_CFG_H_
#define SOS_CFG_H_

#define TIMER_TICK_PRESCALLER            TIMER_PRESCALER_1024
#define TIMER_TICK_PRESCALLER_VALUE      (1024UL)
#define TIMER_TICK_MAX_COUNTS            (255U)
#define MAX_NO_TASKS                     (3U)
#define MIN_PRIORITY                     (2U)
#endif /* SOS_CFG_H_ */

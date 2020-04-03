/**************************************************************************
 *  File Name:sleep.c
 *  Description : Contains Api's that configure Avr Sleep Modes
 *  Layer : McAl
 *  Created on: Jan 13, 2020
 *  Author: Ahmed_Elbadwi
 *************************************************************************/

/*************************************************************************/
/*                         Includes                                      */
/*************************************************************************/
#include "registers.h"
#include "sleep.h"
/*************************************************************************/
/*                         #Defines                                      */
/*************************************************************************/
/* MCUCR bit Definitions */
#define SE    (7U)
#define SM2   (6U)
#define SM1   (5U)
#define SM0   (4U)

/*************************************************************************/
/*                         Apis's Definitions                            */
/*************************************************************************/
/*************************************************************************
* @brief: CPU_Sleep provides six modes
* 	  IDLE, ADC_NOISE_REDUC, POWER_DOWN, POWER_SAVE, STANDBY, EXT_STANDBY
* 	  Note: STANDBY and EXT_STANDBY sleep modes are only available with
* 	  	external crystal/resonator fuse selection
* @param: E_SleepMode_t enum defines sleep modes
* Input : E_SleepMode_t
* Output: None
* @return: void
**************************************************************************/
void CPU_Sleep(E_SleepMode_t e_mode)
{
  switch (e_mode) {
    case (IDLE):
      /* Set IDLE sleep mode */
      MCUCR &= ~(SM2 | SM1 | SM0);
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (ADC_NOISE_REDUC):
      /* Set ADC noise reduction sleep mode */
      MCUCR &= ~(SM2 | SM1);
      MCUCR |= SM0;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (POWER_DOWN):
      /* Set Power-down sleep mode */
      MCUCR &= ~(SM2 | SM0);
      MCUCR |= SM1;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (POWER_SAVE):
      /* Set Power-save sleep mode */
      MCUCR |= (SM1 | SM0);
      MCUCR &= ~SM2;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (STANDBY):
      /* Set Standby sleep mode */
      MCUCR |= (SM2 | SM1);
      MCUCR &= ~SM0;
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    case (EXT_STANDBY):
      /* Set Extended standby sleep mode */
      MCUCR |= (SM2 | SM1 | SM0);
      /* Enter sleep mode */
      MCUCR |= SE;
      break;
    default:
      break;
  }
  /* Execute SLEEP instruction to put device in selected sleep mode */
  asm("SLEEP");
}

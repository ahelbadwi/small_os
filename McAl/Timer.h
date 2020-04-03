/*
 *  Timer.h
 *  Created on: Dec 21, 2019
 *  Author: Ahemd_Elbadwi
 *  Layer : McAl
 */

#ifndef TIMER_H_
#define TIMER_H_

/************************************************************************/
/*				 INCLUDES			        */
/************************************************************************/

#include "std_types.h"
#include "registers.h"
#include "Utils.h"
#include "DIO.h"

/************************************************************************/
/*				 DEFINES			        */
/************************************************************************/


#define		TIMER_CH0					    ((uint8)0)
#define		TIMER_CH1					    ((uint8)1)
#define		TIMER_CH2					    ((uint8)2)


#define		TIMER_MODE					    ((uint8)0)
#define     COUNTER_FALLING                 ((uint8)1)
#define     COUNTER_RISING                  ((uint8)2)


#define		TIMER_POLLING_MODE				((uint8)0)
#define		TIMER_INTERRUPT_MODE			((uint8)1)

#define		TIMER_NO_CLOCK					((uint8)0)
#define		TIMER_PRESCALER_NO				((uint8)1)
#define		TIMER_PRESCALER_8				((uint8)2)
#define		TIMER_PRESCALER_32				((uint8)3)
#define		TIMER_PRESCALER_64				((uint8)4)
#define		TIMER_PRESCALER_128				((uint8)5)
#define		TIMER_PRESCALER_256				((uint8)6)
#define		TIMER_PRESCALER_1024		    ((uint8)7)



/************************************************************************/
/*			        Structures Decelerations		                    */
/************************************************************************/

typedef struct Timer_cfg_s
{
	uint8 Timer_CH_NO;
	uint8 Timer_Mode;
	uint8 Timer_Polling_Or_Interrupt;
	uint8 Timer_Prescaler;
	ErrorStatus_t (*Timer_CBF) (void);
}Timer_cfg_s;



/************************************************************************/
/*		         TIMER FUNCTIONS' PROTOTYPES		        */
/************************************************************************/


/**
 * Input: Pointer to a structure contains the information needed to initialize the timer. 
 * Output:
 * In/Out:			
 * Return: The error status of the function.			
 * Description: Initiates the module.
 * 							
 */
ErrorStatus_t Timer_Init(Timer_cfg_s* Timer_cfg);

/**
 * Input: 
 * 	Timer_CH_NO: The channel number of the timer needed to be started.
 *	Timer_Count: The start value of the timer.
 * Output:
 * In/Out:			
 * Return: The error status of the function.			
 * Description: This function strats the needed timer.
 * 							
 */
ErrorStatus_t Timer_Start(uint8 Timer_CH_NO, uint16 Timer_Count);

/**
 * Input: 
 * 	Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:			
 * Return: The error status of the function.			
 * Description: This function stops the needed timer.
 * 							
 */
ErrorStatus_t Timer_Stop(uint8 Timer_CH_NO);

/**
 * Input: 
 * 	Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * 	Data: A variable of type bool returns if the flag of the timer is raised or not.
 * In/Out:			
 * Return: The error status of the function.			
 * Description: This function is used to return if the flag of the timer is raised or not.
 * 							
 */
ErrorStatus_t Timer_GetStatus(uint8 Timer_CH_NO, bool* Data);

/**
 * Input: 
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Data: This is the output variable of the function which holds the value of the timer.
 * In/Out:			
 * Return: The error status of the function.			
 * Description: This function is used to return the value of the timer.
 * 							
 */
ErrorStatus_t Timer_GetValue(uint8 Timer_CH_NO, uint16* Data);


/**
 * Input:
 * Timer_CH_NO: The channel number of the timer needed to get its value.
 * Value      : the certain value to set timer register counter .
 * Output: Na
 * In/Out: Na
 * Return: The error status of the function.
 * Description: This function is used to Set value timer register counter.
 */
ErrorStatus_t Timer_SetValue(uint8 Timer_CH_NO,uint16 Value);

ErrorStatus_t Timer_Deinit(uint8 Timer_CH_NO);



#endif /* TIMER_H_ */

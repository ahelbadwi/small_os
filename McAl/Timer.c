/*
 *  Timer.c
 *  Created on: Dec 22, 2019
 *  Author: Ahemd_Elbadwi
 *  Layer:  McAl
 */

/************************************************************************/
/*				 INCLUDES			                                    */
/************************************************************************/

#include "Timer.h"
#include "interrupt.h"

/************************************************************************/
/*				 #Defines  			                                    */
/************************************************************************/
#define TOV0 (0U)
#define TOV1 (1U)
#define TOV2 (6U)

#define TIMER0_MAX_COUNTS ((uint8)0XFF)
#define TIMER1_MAX_COUNTS ((uint16)0XFFFF)
#define TIMER2_MAX_COUNTS ((uint8)0XFF)


/************************************************************************/
/*				Static Global Variables			                        */
/************************************************************************/
static bool gb_TimerInitFlag =FALSE;
static ErrorStatus_t (*gPtrFun_CBF[3]) (void) = {NULL};
static uint8 gu8_TimerCounter0ClockSource=0;
static uint8 gu8_TimerCounter1ClockSource=0;
static uint8 gu8_TimerCounter2ClockSource=0;

static uint8 gau8_TimerCounterNotification_Init[3]={FALSE};       /****Notify that timer/counter has Initialized ***/
static uint8 gau8_TimerCounterNotification_Start[3]={FALSE};     /**** Notify that timer/counter has Started     ***/
/************************************************************************/
/*				Exports Global Variables			                    */
/************************************************************************/

/*   Nothing  */

/************************************************************************/
/*				 Timer Function definitions 			                                    */
/************************************************************************/
/**
 * Input: Pointer to a structure contains the information needed to initialize the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: Initiates the module.
 *
 */
ErrorStatus_t Timer_Init(Timer_cfg_s* Timer_cfg)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	if(NULL!=Timer_cfg)
	{

		switch(Timer_cfg->Timer_CH_NO)
		{
		case TIMER_CH0:
			/* Configure Timer 0 Call Back Function */
			gPtrFun_CBF[TIMER_CH0] = Timer_cfg->Timer_CBF;
			switch(Timer_cfg->Timer_Mode)
			{
			case TIMER_MODE:
				switch(Timer_cfg->Timer_Prescaler)
				{
				case TIMER_NO_CLOCK:
					gu8_TimerCounter0ClockSource=0x00;
					break;
				case TIMER_PRESCALER_NO:
					gu8_TimerCounter0ClockSource=0x01;
					break;
				case TIMER_PRESCALER_8:
					gu8_TimerCounter0ClockSource=0x02;
					break;
				case TIMER_PRESCALER_64:
					gu8_TimerCounter0ClockSource=0x03;
					break;
				case TIMER_PRESCALER_256:
					gu8_TimerCounter0ClockSource=0x04;
					break;
				case TIMER_PRESCALER_1024:
					gu8_TimerCounter0ClockSource=0x05;
					break;
				default:
					ERROR_STATUS=TIMER_ERROR;
					break;
				}
				break;
				case COUNTER_RISING:
					gu8_TimerCounter0ClockSource=0x06;
					break;
				case COUNTER_FALLING:
					gu8_TimerCounter0ClockSource=0x07;
					break;
				default:
					ERROR_STATUS=TIMER_ERROR;
					break;
			}

			switch (Timer_cfg->Timer_Polling_Or_Interrupt)
			{
			case TIMER_POLLING_MODE:
				TIMSK|=0x00;
				break;
			case TIMER_INTERRUPT_MODE:
				/*Handling OVF Interrupt(Low Level Design)*/
				TIMSK|=0x01;
				/* Global Interrupt Enable */
				GIE();
				break;
			default:
				ERROR_STATUS=TIMER_ERROR;
				break;
			}
			break;

			case TIMER_CH1:
				/* Configure Timer 0 Call Back Function */
				gPtrFun_CBF[TIMER_CH1] = Timer_cfg->Timer_CBF;

				switch(Timer_cfg->Timer_Mode)
				{
				case TIMER_MODE:
					switch(Timer_cfg->Timer_Prescaler)
					{
					case TIMER_NO_CLOCK:
						gu8_TimerCounter1ClockSource=0x00;
						break;
					case TIMER_PRESCALER_NO:
						gu8_TimerCounter1ClockSource=0x01;
						break;
					case TIMER_PRESCALER_8:
						gu8_TimerCounter1ClockSource=0x02;
						break;
					case TIMER_PRESCALER_64:
						gu8_TimerCounter1ClockSource=0x03;
						break;
					case TIMER_PRESCALER_256:
						gu8_TimerCounter1ClockSource=0x04;
						break;
					case TIMER_PRESCALER_1024:
						gu8_TimerCounter1ClockSource=0x05;
						break;
					default:
						ERROR_STATUS=TIMER_ERROR;
						break;
					}
					break;
					case COUNTER_RISING:
						gu8_TimerCounter1ClockSource=0x06;
						break;
					case COUNTER_FALLING:
						gu8_TimerCounter1ClockSource=0x07;
						break;
					default:
						ERROR_STATUS=TIMER_ERROR;
						break;
				}

				switch (Timer_cfg->Timer_Polling_Or_Interrupt)
				{
				case TIMER_POLLING_MODE:
					TIMSK|=0x00;
					break;
				case TIMER_INTERRUPT_MODE:
					/*Handling OVF Interrupt(Low Level Design)*/
					TIMSK|=0x04;
					/* Global Interrupt Enable */
					GIE();
					break;
				default:
					ERROR_STATUS=TIMER_ERROR;
					break;
				}
				break;
				case TIMER_CH2:
					/* Configure Timer 0 Call Back Function */
					gPtrFun_CBF[TIMER_CH2] = Timer_cfg->Timer_CBF;

					switch(Timer_cfg->Timer_Mode)
					{
					case TIMER_MODE:
						switch(Timer_cfg->Timer_Prescaler)
						{
						case TIMER_NO_CLOCK:
							gu8_TimerCounter2ClockSource=0x00;
							break;
						case TIMER_PRESCALER_NO:
							gu8_TimerCounter2ClockSource=0x01;
							break;
						case TIMER_PRESCALER_8:
							gu8_TimerCounter2ClockSource=0x02;
							break;
						case TIMER_PRESCALER_32:
							gu8_TimerCounter2ClockSource=0x03;
							break;
						case TIMER_PRESCALER_64:
							gu8_TimerCounter2ClockSource=0x04;
							break;
						case TIMER_PRESCALER_128:
							gu8_TimerCounter2ClockSource=0x05;
							break;
						case TIMER_PRESCALER_256:
							gu8_TimerCounter2ClockSource=0x06;
							break;
						case TIMER_PRESCALER_1024:
							gu8_TimerCounter2ClockSource=0x07;
							break;
						default:
							ERROR_STATUS=TIMER_ERROR;
							break;
						}
						break;
						case COUNTER_RISING:
							ASSR|=0x08;
							break;
						case COUNTER_FALLING:
							ASSR|=0x08;
							break;
						default:
							ERROR_STATUS=TIMER_ERROR;
							break;
					}

					switch (Timer_cfg->Timer_Polling_Or_Interrupt)
					{
					case TIMER_POLLING_MODE:
						TIMSK|=0x00;
						break;
					case TIMER_INTERRUPT_MODE:
						/*Handling OVF Interrupt(Low Level Design)*/
						TIMSK|=0x40;
						/* Global Interrupt Enable */
						GIE();
						break;
					default:
						ERROR_STATUS=TIMER_ERROR;
						break;
					}
					break;
					default:
						ERROR_STATUS=TIMER_ERROR;
						break;
		}

		if(ERROR_STATUS==SUCCESS)
		{
			gau8_TimerCounterNotification_Init[Timer_cfg->Timer_CH_NO]=TRUE;
		}
	}

	else
	{
		ERROR_STATUS=TIMER_ERROR;
	}

	if(SUCCESS == ERROR_STATUS)
	{
		gb_TimerInitFlag=TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	return ERROR_STATUS;
}


/**
 * Input:
 * Timer_CH_NO: The channel number of the timer needed to be started.
 * Timer_Count: Number of counts that timer counts.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function starts the needed timer.
 *
 */
ErrorStatus_t Timer_Start(uint8 Timer_CH_NO, uint16 Timer_Count)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	if(gau8_TimerCounterNotification_Init[Timer_CH_NO]==TRUE)
	{
		switch(Timer_CH_NO)
		{
		case TIMER_CH0:
			TCNT0=TIMER0_MAX_COUNTS-Timer_Count;
			TCCR0|=gu8_TimerCounter0ClockSource;
			break;
		case TIMER_CH1:
			TCNT1=TIMER1_MAX_COUNTS-Timer_Count;
			TCCR1B|=gu8_TimerCounter1ClockSource;
			break;
		case TIMER_CH2:
			TCNT2=TIMER2_MAX_COUNTS-Timer_Count;
			TCCR2|=gu8_TimerCounter2ClockSource;
			break;
		default:
			ERROR_STATUS=TIMER_ERROR;
			break;
		}
	}

	else
	{

	}

	if(ERROR_STATUS==SUCCESS)
	{
		gau8_TimerCounterNotification_Start[Timer_CH_NO]=TRUE;
	}
	else
	{

	}

	return ERROR_STATUS;
}


/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function stops the needed timer.
 *
 */
ErrorStatus_t Timer_Stop(uint8 Timer_CH_NO)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	if(gau8_TimerCounterNotification_Start[Timer_CH_NO]==TRUE)
	{
		switch(Timer_CH_NO)
		{
		case TIMER_CH0:
			TCCR0&=0xF8;
			break;
		case TIMER_CH1:
			TCCR1B&=0xF8;
			break;
		case TIMER_CH2:
			TCCR2&=0xF8;
			break;
		default:
			ERROR_STATUS=TIMER_ERROR;
			break;
		}

	}
	else
	{

	}
	return ERROR_STATUS;
}


/**
 * Input:
 * Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * Data: A variable of type bool returns if the flag of the timer is raised or not.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the timer OVF flag raised or not.
 */
ErrorStatus_t Timer_GetStatus(uint8 Timer_CH_NO, bool* Data)
{
	ErrorStatus_t ERROR_STATUS=TIMER_ERROR;
	if(gau8_TimerCounterNotification_Init[Timer_CH_NO])
	{
		switch(Timer_CH_NO)
		{
		case TIMER_CH0:
			*Data=GET_BIT(TIFR,TOV0);
			break;
		case TIMER_CH1:
			*Data=GET_BIT(TIFR,TOV1);
			break;
		case TIMER_CH2:
			*Data=GET_BIT(TIFR,TOV2);
			break;
		default:
			ERROR_STATUS=TIMER_ERROR;
			break;
		}
	}

	else
	{

	}

	return ERROR_STATUS;
}


/**
 *
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Data: This is the output variable of the function which holds the value of the timer.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the value of the timer.
 *
 */
ErrorStatus_t Timer_GetValue(uint8 Timer_CH_NO, uint16* Data)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	if(gau8_TimerCounterNotification_Init[Timer_CH_NO]==TRUE)
	{
		switch(Timer_CH_NO)
		{
		case TIMER_CH0:
			*Data=TCNT0;
			break;
		case TIMER_CH1:
			*Data=TCNT1;
			break;
		case TIMER_CH2:
			*Data=TCNT2;
			break;
		default:
			ERROR_STATUS=TIMER_ERROR;
			break;
		}
	}
	else
	{

	}
	return ERROR_STATUS;
}


/**
 * Input:
 * Timer_CH_NO: The channel number of the timer needed to get its value.
 * Value      : the certain value to set timer register counter .
 * Output: Na
 * In/Out: Na
 * Return: The error status of the function.
 * Description: This function is used to Set value timer register counter.
 */
ErrorStatus_t Timer_SetValue(uint8 Timer_CH_NO,uint16 Value)
{
	ErrorStatus_t ERROR_STATUS_Timer_SetValue=SUCCESS;
	switch(Timer_CH_NO)
	{
	case TIMER_CH0:
		TCNT0 = Value;
		break;
	case TIMER_CH1:
		TCNT1 = Value;
		break;
	case TIMER_CH2:
		TCNT2 = Value;
		break;
	default:
		ERROR_STATUS_Timer_SetValue =TIMER_ERROR;
	}
	return ERROR_STATUS_Timer_SetValue;
}


ErrorStatus_t Timer_Deinit(uint8 Timer_CH_NO)
{
	/* TODO : this is not the right way to deinit timer */
	ErrorStatus_t ErrorStatus_Dinit=SUCCESS;
	if(TRUE == gb_TimerInitFlag)
	{
		Timer_Stop(Timer_CH_NO);
	}
	else
	{
		ErrorStatus_Dinit=TIMER_ERROR;
	}
	return ErrorStatus_Dinit;
}


/*********************************************************************************/
/*                                ISRs                                           */
/*********************************************************************************/


ISR(TIMER1_OVF_Vect)
{
	if(NULL != gPtrFun_CBF[TIMER_CH1])
	{
		gPtrFun_CBF[TIMER_CH1]();
	}
	else
	{
		/* Do Nothing */
	}
}


ISR(TIMER0_OVF_Vect)
{
	if(NULL != gPtrFun_CBF[TIMER_CH0])
	{
		gPtrFun_CBF[TIMER_CH0]();
	}
	else
	{
		/* Do Nothing */
	}
}

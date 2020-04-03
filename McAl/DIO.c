/*
 * DIO.c
 *
 *  Created on: Dec 22, 2019
 *      Author: Ahemd_Elbadwi 
 */


#include "DIO.h"


/**************************************************************************************
 *Input: DIO_Cfg_s -> to get PORT name, Pins to be initiated and the required direction
 *Output: No output
 *In/Out:
 *Description: This function can set the direction of a full port, a nibble
 * 			  or even one pin.
 ***************************************************************************************/
ErrorStatus_t DIO_init (DIO_Cfg_s *DIO_info)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	if(NULL!=DIO_info)
	{
		{
			switch(DIO_info->GPIO)
			{
			case GPIOA:
				if(DIO_info->dir == INPUT)
				{
					PORTA_DIR&=~(DIO_info->pins);
				}
				else if(DIO_info->dir==OUTPUT)
				{
					PORTA_DIR|=(DIO_info->pins);
				}
				else
				{
					ERROR_STATUS=DIO_ERROR;
				}
				break;
			case GPIOB:
				if(DIO_info->dir==INPUT)
				{
					PORTB_DIR&=~(DIO_info->pins);
				}
				else if(DIO_info->dir==OUTPUT)
				{
					PORTB_DIR|=(DIO_info->pins);
				}
				else
				{
					ERROR_STATUS=DIO_ERROR;
				}
				break;
			case GPIOC:
				if(DIO_info->dir==INPUT)
				{
					PORTC_DIR&=~(DIO_info->pins);
				}
				else if(DIO_info->dir==OUTPUT)
				{
					PORTC_DIR|=(DIO_info->pins);
				}
				else
				{
					ERROR_STATUS=DIO_ERROR;
				}
				break;
			case GPIOD:
				if(DIO_info->dir==INPUT)
				{
					PORTD_DIR&=~(DIO_info->pins);
				}
				else if(DIO_info->dir==OUTPUT)
				{
					PORTD_DIR|=(DIO_info->pins);
				}
				else
				{
					ERROR_STATUS=DIO_ERROR;
				}
				break;
			default:
				ERROR_STATUS=DIO_ERROR;
				break;
			}
		}
	}

	else
	{
		ERROR_STATUS=DIO_ERROR;
	}

	return ERROR_STATUS;

}



/*
 *Input: GPIO -> to get PORT name
 *					- GPIOA
 *					- GPIOB
 *					- GPIOC
 *					- GPIOD
 *		Pins -> Pins to be written at.
 *					- PIN0
 *					- PIN1
 *					- PIN2
 *					- PIN3
 *					- PIN4
 *					- PIN5
 *					- PIN6
 *					- PIN7
 *					- UPPER_NIBBLE
 *					- LOWER_NIBBLE
 *					- FULL_PORT
 *		value 	-> The desired value
 *Output: No output
 *In/Out: No In/Out
 *Description: This function can set the value of a full port, a nibble
 * 			  or even one pin.
 */
ErrorStatus_t DIO_Write (uint8 GPIO, uint8 Pins, uint8 value)
{
	ErrorStatus_t ERROR_STATUS=DIO_ERROR;
	switch(GPIO)
	{
	case GPIOA:
		if(value==LOW)
		{
			PORTA_DATA&=~(Pins);
		}
		else if(value==HIGH)
		{
			PORTA_DATA|=Pins;
		}
		else
		{
			ERROR_STATUS=DIO_ERROR;
		}
		break;
	case GPIOB:
		if(value==LOW)
		{
			PORTB_DATA&=~(Pins);
		}
		else if(value==HIGH)
		{
			PORTB_DATA|=Pins;
		}
		else
		{
			ERROR_STATUS=DIO_ERROR;
		}
		break;
	case GPIOC:
		if(value==LOW)
		{
			PORTC_DATA&=~(Pins);
		}
		else if(value==HIGH)
		{
			PORTC_DATA|=Pins;
		}
		else
		{
			ERROR_STATUS=DIO_ERROR;
		}
		break;
	case GPIOD:
		if(value==LOW)
		{
			PORTD_DATA&=~(Pins);
		}
		else if(value==HIGH)
		{
			PORTD_DATA|=Pins;
		}
		else
		{
			ERROR_STATUS=DIO_ERROR;
		}
		break;
	default:
		ERROR_STATUS=DIO_ERROR;
		break;
	}

	return ERROR_STATUS;
}

/*
 *Input: GPIO -> to get PORT name
 *					- GPIOA
 *					- GPIOB
 *					- GPIOC
 *					- GPIOD
 *		Pins -> Pins to be written at.
 *					- PIN0
 *					- PIN1
 *					- PIN2
 *					- PIN3
 *					- PIN4
 *					- PIN5
 *					- PIN6
 *					- PIN7
 *					- UPPER_NIBBLE
 *					- LOWER_NIBBLE
 *					- FULL_PORT
 *Output: data -> the acquired data wether it was PORT data or Pins data
 *In/Out:
 *Description: This function gets the value of a full port, a nibble
 * 			  or even one pin.
 */
ErrorStatus_t DIO_Read (uint8 GPIO,uint8 Pins, uint8 *data)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	if(NULL != data)
	{
		switch(GPIO)
		{

		case GPIOA:
			*data=PORTA_PIN&Pins;
			break;
		case GPIOB:
			*data=PORTB_PIN&Pins;
			break;
		case GPIOC:
			*data=PORTC_PIN&Pins;
			break;
		case GPIOD:
			*data=PORTD_PIN&Pins;
			break;
		default:
			ERROR_STATUS=DIO_ERROR;
			break;
		}

		if((*data)==Pins)
		{
			*data=HIGH;
		}
		else
		{
			*data=LOW;
		}
	}

	return ERROR_STATUS;
}

/*
 *Input: GPIO -> to get PORT name
 *					- GPIOA
 *					- GPIOB
 *					- GPIOC
 *					- GPIOD
 *		pins -> pins to be written at.
 *					- PIN0
 *					- PIN1
 *					- PIN2
 *					- PIN3
 *					- PIN4
 *					- PIN5
 *					- PIN6
 *					- PIN7
 *					- UPPER_NIBBLE
 *					- LOWER_NIBBLE
 *					- FULL_PORT
 *Output: data -> No output
 *In/Out:
 *Description: This function toggles the value of a full port, a nibble
 * 			  or even one pin.
 */
ErrorStatus_t DIO_Toggle (uint8 GPIO, uint8 Pins)
{
	ErrorStatus_t ERROR_STATUS=SUCCESS;
	switch(GPIO)
	{
	case GPIOA:
		PORTA_DATA^=Pins;
		break;
	case GPIOB:
		PORTB_DATA^=Pins;
		break;
	case GPIOC:
		PORTC_DATA^=Pins;
		break;
	case GPIOD:
		PORTD_DATA^=Pins;
		break;
	default:
		ERROR_STATUS=DIO_ERROR;
		break;
	}
	return ERROR_STATUS;
}



/*
 *  File name: Retval.h
 *  Description: holds common errors returned over modules
 *  Created on: Jan 14, 2020
 *  Author: Ahemd_Elbadwi
 */

#ifndef RETVAL_H_
#define RETVAL_H_

#include "std_types.h"
/************************************************************************/
/*		                        Typedefs                  		        */
/************************************************************************/

typedef sint8 ErrorStatus_t;

/************************************************************************/
/*		                        Defines                 		        */
/************************************************************************/
/****** modules bases *******/
#define TMU_BASE_ERROR				          (-50)
#define BCM_BASE_ERROR                        (-70)
#define SOS_BASE_ERROR                        (-90)
/****** error types**********/
#define SUCCESS 				              (0)
#define INVALID_ARGU_ERROR    	              (-1)
#define NOT_INITIALIZED_ERROR  	              (-2)
#define ALREADY_INITIALIZED_ERROR  	          (-3)
#define NULL_PTR_ERROR 			              (-4)
#define RESOURCE_NOT_FOUND_ERROR 	          (-5)
#define HW_CONSTRAIN_ERROR		              (-6)
#define BUFFER_FULL_ERROR			          (-7)
#define UART_ERROR					          (-8)
#define SPI_ERROR				              (-9)
#define TIMER_ERROR					          (-10)
#define RESOURCE_NOT_AVAILABLE_ERROR          (-11)
#define NOT_SUPPORTED				          (-12)
#define NOT_DEFINED_ERROR                     (-13)
#define DEINIT_ERROR                          (-14)
#define DIO_ERROR                             (-15)
#define COMMUNICATION_CHANNLE_BUSY_ERROR      (-16)
#define CBK_ERROR                             (-17)
#define DATA_CORRUPTION_ERROR                 (-18)
#endif /* RETVAL_H_ */

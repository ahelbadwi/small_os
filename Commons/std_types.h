/*
 * std_types.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Sprints
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/

#define NULL	((void *)0)

typedef unsigned char bool;
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long int sint32;
typedef signed long long sint64;
typedef volatile uint8* const reg_type8;
typedef volatile uint16* const reg_type16;


/************************************************************************/
/*				 		defining boolean values                         */
/************************************************************************/
#define FALSE 	((bool)0)
#define TRUE 	((bool)1)

/************************************************************************/
/*						 LOW/HIGH defines                               */
/************************************************************************/
#define LOW  0
#define HIGH 0xFF

/************************************************************************/
/*                       Error handling                                 */
/************************************************************************/
#define E_OK        0
#define E_NOK       1

#endif /* STD_TYPES_H_ */

/*
 * General_Macros.h
 *
 *  Created on: Dec 23, 2019
 *      Author: Ahemd_Elbadwi 
 */

#ifndef GENERAL_MACROS_H_
#define GENERAL_MACROS_H_

#ifdef F_CPU
#undef F_CPU
#define F_CPU (16000000UL)
#endif

#define ZERO_VALUE         (0U)
#define ONE_VALUE          (1U)
#define ZERO_VALUE_ASCII (48)
#endif /* GENERAL_MACROS_H_ */

/*
 * interrupts.h
 *
 *  Created on: Dec 9, 2019
 *      Author: ahmed
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "Utils.h"

#define Ext_Inter_Req0_Vect              __vector_1
#define Ext_Inter_Req1_Vect              __vector_2
#define Ext_Inter_Req2_Vect              __vector_3
#define TIMER2_COMP_Vect                 __vector_4
#define TIMER2_OVF_Vect                  __vector_5
#define TIMER1_CAPT_Vect                 __vector_6
#define TIMER1_COMPA_Vect                __vector_7
#define TIMER1_COMPB_Vect                __vector_8
#define TIMER1_OVF_Vect                  __vector_9
#define TIMER0_COMP_Vect                 __vector_10
#define TIMER0_OVF_Vect                  __vector_11
#define SPI_COMPLETE_Vect                __vector_12
#define USART_RXC_Vect                   __vector_13
#define USART_UDRE_Vect                  __vector_14
#define USART_TXC_Vect                   __vector_15
#define ADC_Conv_Comp_Vect               __vector_16
#define EE_RDY_Vect                      __vector_17
#define ANA_COMP_Vect                    __vector_18
#define TWI_Vect                         __vector_19
#define SPM_RDY_Vect                     __vector_20


#define __INTR_ATTRS used, externally_visible

#define ISR(vector, ...)            \
		void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
		void vector (void)


#define GIE() SET_BIT(SREG,7)  /*global interrupt enable*/
#define GID() CLEAR_BIT(SREG,7) /*global interrupt disable */

#define sei() __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)


#endif /* INTERRUPTS_H_ */

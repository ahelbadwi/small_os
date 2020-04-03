/*
 * Utils.h
 *
 *  Created on: Dec 7, 2018
 *      Author: ahmed
 */

#ifndef UTILS_H_
#define UTILS_H_


#define SET_BIT_MASK(VAR,BIT_MASK) 		        (VAR)|=(BIT_MASK)
#define CLR_BIT_MASK(VAR,BIT_MASK) 		        (VAR)&=~(BIT_MASK)
#define GET_BIT_MASK(VAR,BIT_NB) 		        (((VAR)&(BIT_NB))/(BIT_NB))
#define SET_BIT(Reg,Bit_no)                     Reg=Reg|((uint8)(0x01)<<Bit_no)
#define CLEAR_BIT(Reg,Bit_no)                   Reg=(Reg)&(~((uint8)(0x01) <<Bit_no))
#define TOGGLE_BIT(Reg,Bit_no)                  Reg=(Reg)^((uint8)(0x01)<<Bit_no)
#define GET_BIT(Reg,Bit_no)                     (((Reg)>>(Bit_no))&0x01)
#define ASSIGN_LOW_NIBBLE(reg,val)              reg=( (reg&(0xf0) )|(val) )
#define ASSIGN_HIGH_NIBBLE(reg,val)             reg=( (reg&(0x0f) )|(val) )
#define ASSIGN_BIT(Reg,Bit_no,val)              Reg=((Reg)&(~((uint8)(0x01)<<(Bit_no))))|(val<<Bit_no)
#define GET_LOW_NIBBLE(reg)                     (reg&0x0f)
#define GET_HIGH_NIBBLE(reg)                    ((reg&0xf0)>>4)
#define GET_LOW_BYTE(u16_reg)                   (u16_reg&0x00FF)
#define GET_HIGH_BYTE(u16_reg)                  ((u16_reg&0xFF00)>>8)

#endif /* UTILS_H_ */

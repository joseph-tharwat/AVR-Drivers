

/* 
 * File:   GIE private
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef GIE_PRIV_H
#define	GIE_PRIV_H

#include "STD_Types.h"

//GIE bit in SREG register is 7
#define GIE_BIT    7

//address of SREG register
#define SREG_REGISTER   (*((volatile u8 *)0x5F))



#endif


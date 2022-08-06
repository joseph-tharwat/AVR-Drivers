
/* 
 * File:   
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef EXTERNAL_INTERRUPT_PRIV_H
#define	EXTERNAL_INTERRUPT_PRIV_H
#include "STD_Types.h"


//address of MCUCR_REGISTER 
#define MCUCR_REGISTER    (*((volatile u8 *)0x55))
//ISC00 bit is num 0,  ISC01 bit is num 1 >> select mode (falling - rising - onChange) 
#define MCUCR_ISC00_BIT    0
#define MCUCR_ISC01_BIT    1

//Moods of signal (falling - rising - onChange) 
#define FALLING_MODE    0
#define RISING_MODE     1
#define ONCHANGE_MODE   2


//GICR Register 
#define GICR_REGISTER    (*((volatile u8 *)0x5B))  //PIE
#define GICR_INT0_BIT    6


//GIFR Register
#define GIFR_REGISTER  (*((volatile u8 *)0x5A))  //PIF
#define GIFR_INT0_BIT    6





#endif	


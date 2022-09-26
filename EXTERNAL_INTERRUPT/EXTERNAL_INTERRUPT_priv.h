/***************************************************/
/* Title       : EXTERNAL INTERRUPT private file   */
/* Author      : Joseph Tharwat                    */
/* Release     : 1.0                               */
/* Last Update : 6-9-2022                          */
/***************************************************/

#ifndef EXTERNAL_INTERRUPT_PRIVITE_H_
#define EXTERNAL_INTERRUPT_PRIVITE_H_

#define MCUCR				*((volatile u8*)0x55)
#define MCUCR_ISC00_BIT		0
#define MCUCR_ISC01_BIT		1
#define MCUCR_ISC10_BIT		2
#define MCUCR_ISC11_BIT		3

#define GICR 				*((volatile u8*)0x5B)
#define GICR_INT2_BIT		5
#define GICR_INT0_BIT		6
#define GICR_INT1_BIT		7

//INT number
#define INT0	 0
#define INT1 	 1
#define INT2 	 2

//MODE
#define INT0_LowLevel				9
#define INT0_ON_CHANGING			10
#define INT0_RISING_EDGE			11
#define INT0_FALLING_EDGE			12

#define INT1_LowLevel				13
#define INT1_ON_CHANGING			14
#define INT1_RISING_EDGE			15
#define INT1_FALLING_EDGE			16

#define INT2_RISING_EDGE			17
#define INT2_FALLING_EDGE			18

#define MCUCSR						*((volatile u8*)0x54)
#define MCUCSR_ISC2_BIT				6

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

//Flag is diabled atomaticly when ISR is started (not used)
#define GIFR 				*((volatile u8*)0x5A)
#define GIFR_INTF2_BIT		5
#define GIFR_INTF0_BIT		6
#define GIFR_INTF1_BIT		7



#endif

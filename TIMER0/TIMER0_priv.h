/***************************************************/
/* Title       : TIMER0 private file 			   */
/* Author      : Joseph Tharwat                    */
/* Release     : 1.0                               */
/* Last Update : 6-9-2022                          */
/***************************************************/

#ifndef TIMER0_PRIVITE_H_
#define TIMER0_PRIVITE_H_

//Timer/Counter Control Register
#define TCCR0 		*((volatile u8*)0x53)
#define TCCR0_FOC0_BIT		7
#define TCCR0_WGM00_BIT		6
#define TCCR0_COM01_BIT		5
#define TCCR0_COM00_BIT		4
#define TCCR0_WGM01_BIT		3
#define TCCR0_CS02_BIT		2
#define TCCR0_CS01_BIT		1
#define TCCR0_CS00_BIT		0

//Timer/Counter Register
#define TCNT0 		*((volatile u8*)0x52)

//Output Compare Register
#define OCR0 		*((volatile u8*)0x5C)

//Timer/Counter Interrupt Mask
#define TIMSK 		*((volatile u8*)0x59)
#define TIMSK_OCIE0_BIT		1
#define TIMSK_TOIE0_BIT		0

//TIMER0 mode select
#define NORMAL_MODE			9
#define PWM_MODE			10
#define CTC_MODE			11
#define FASTPWM_MODE		12



//OC0 pin mode select
#define OC0_DISCONNECTED													13
#define OC0_TOGGLE															14
#define OC0_CLEAR															15
#define OC0_SET																16
#define OC0_CLEAR_ON_COMPARE_SET_AT_TOP										17
#define OC0_SET_ON_COMPARE_CLEAR_AT_TOP										18
#define OC0_CLEAR_ON_COMPARE_COUNTING_UP_SET_ON_COMPARE_COUNTING_DOWN	19
#define OC0_SET_ON_COMPARE_COUNTING_UP_CLEAR_ON_COMPARE_COUNTING_DOWN	20


//Choose clock frequency
#define STOPPED							21
#define CLK								22
#define CLK_DIV_8						23
#define CLK_DIV_64						24
#define CLK_DIV_256						25
#define CLK_DIV_1024					26
#define EXTERNAL_FALLING_EDGE			27
#define EXTERNAL_RISING_EDGE			28

#define TIMER0_MAX_VALUE 				255

////////////////////////////////////////////////////////

//Timer/Counter Interrupt Flag	(not used)
#define TIFR 				*((volatile u8*)0x58)
#define TIFR_TOV0_BIT		0
#define TIFR_OCF0_BIT		1




#endif

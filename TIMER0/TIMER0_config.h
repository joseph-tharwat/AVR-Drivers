/******************************************************/
/* Title       : TIMER0 configration file 			  */
/* Author      : Joseph Tharwat                    	  */
/* Release     : 1.0                                  */
/* Last Update : 6-9-2022                             */
/******************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_
#include "TIMER0_priv.h"

/*Choose Timer0 mode:
 *NORMAL_MODE
 *PWM_MODE
 *CTC_MODE
 *FASTPWM_MODE
 */
#define TIMER0_MODE		NORMAL_MODE

/*Choose OC0 pin mode:
 *DISCONNECTED														//Used in: PWM Mode, Fast PWM Mode, non-PWM Mode only
 *TOGGLE															//Used in: non-PWM Mode	only
 *CLEAR																//Used in: non-PWM Mode	only
 *SET																//Used in: non-PWM Mode	only
 *CLEAR_ON_COMPARE_SET_AT_TOP										//Used in: Fast PWM Mode only
 *SET_ON_COMPARE_CLEAR_AT_TOP										//Used in: Fast PWM Mode only
 *CLEAR_ON_COMPARE_COUNTING_UP__SET_ON_COMPARE__N_COUNTING_DOWN		//Used in: PWM Mode	only
 *SET_ON_COMPARE_COUNTING_UP__CLEAR_ON_COMPARE__N_COUNTING_DOWN		//Used in: PWM Mode	only
 */
#define OC0_MODE		CLEAR_ON_COMPARE_COUNTING_UP__SET_ON_COMPARE_COUNTING_DOWN

/*Choose clock frequency
 *STOPPED
 *CLK
 *CLK_DIV_8
 *CLK_DIV_64
 *CLK_DIV_256
 *CLK_DIV_1024
 *EXTERNAL_FALLING_EDGE
 *EXTERNAL_RISING_EDGE
 */
#define CLOCK_MODE		CLK

#endif

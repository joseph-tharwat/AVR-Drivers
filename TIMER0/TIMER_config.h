
/* 
 * File:   
 * Author: Joseph Thawrat
 * Comments:
 * Revision history: 
 */

#ifndef TIMER_CONFIG_H
#define	TIMER_CONFIG_H

/*
 * Waveform Generation Mode
 00 > Normal
 01 > PWM_Phase_Correct_MODE
 10 > CTC_MODE
 11 > Fast PWM
 */
#define Waveform_Generation_Mode  Normal_MODE

/*
 *CLOCK select :
 NO_CLK                  10
 CLK_NO_PRESCALING       20
 CLK_8                   8
 CLK_64                  64
 CLK_256                 256
 CLK_1024                1024
 CLK_EXTERNAL_FALLING    30
 CLK_EXTERNAL_RISING     40
 */
#define CLK_SELECT CLK_NO_PRESCALING 



/*
 * Select OC0_pin_otput
 OC0_NORMAL 
 OC0_TOGGLE 
 OC0_CLEAR  
 OC0_SET    
 */
#define OC0_pin_output   OC0_TOGGLE


#endif	



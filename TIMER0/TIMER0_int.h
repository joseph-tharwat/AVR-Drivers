/***************************************************/
/* Title       : TIMER0 Interface file */
/* Author      : Joseph Tharwat                    */
/* Release     : 1.0                               */
/* Last Update : 6-9-2022                          */
/***************************************************/

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#include"STD_Types.h"

void TIMER0_SetCallBack_OVERFLOW( void (*func_address)(void) );
void TIMER0_SetCallBack_COMP( void (*func_address)(void) );

void TIMER0_vid_CompareOnMatchInterruptSetEnable();
void TIMER0_vid_OverflowInterruptSetEnable();
void TIMER0_vid_CompareOnMatchInterruptSetDisable();
void TIMER0_vid_OverflowInterruptSetDisable();

void TIMER0_vid_SetTimerRegister(u8 u8_TimerRegisterValue);
void TIMER0_vid_SetOutputCompareRegister(u8 u8_OutputCompareRegisterValue);

void TIMER0_vid_SetTimer0DefultMode();
void TIMER0_vid_SetTimer0Mode(u8 u8_Timer0Mode);

void TIMER0_vid_SetClock(u8 u8_ClockFrequency);
void TIMER0_vid_SetOC0Mode(u8 u8_OC0Mode);

#endif

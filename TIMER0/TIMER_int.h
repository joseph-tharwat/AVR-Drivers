
/* 
 * File:   
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef TIMER_INT_H
#define	TIMER_INT_H

void TIMER0_vid_Init(void);
void TIMER0_vid_SetTimerReg(u8 Copy_u8_Val);
void TIMER0_vid_SetCompareReg(u8 Copy_u8_Val);

void TIMER0_vid_EnableOVInt(void);
void TIMER0_vid_DisableOVInt(void);

void TIMER0_vid_EnableCTCInt(void);
void TIMER0_vid_DisableCTCInt(void);

void TIMER0_vid_SetOVIntCallBack(void (*Copy_ptr)(void));
void TIMER0_vid_SetCTCIntCallBack(void (*Copy_ptr)(void));

#endif	


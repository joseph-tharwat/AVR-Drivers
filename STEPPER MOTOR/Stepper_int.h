
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef STEPPER_INT_H
#define	STEPPER_INT_H
#include "STD_Types.h"

#define STEPPER_DIRECTION_ANTI_CLK   0
#define STEPPER_DIRECTION_CLK        1


void STEPPER_vid_Init(void);
void STEPPER_vid_SetSpeed(u8 STEPPER_Speed);
void STEPPER_vid_SetDirection(u8 STEPPER_Direction);
void STEPPER_vid_SetPosition(u8 STEPPER_Position);


#endif	



/* 
 * File:   
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef EXTERNAL_INTERRUPT__INT_H
#define	EXTERNAL_INTERRUPT__INT_H


void EXTERNAL_INTERRUPT_Init(void);
void EXTERNAL_INTERRUPT_SetCallBack( void (*func_address)(void) );

#endif	


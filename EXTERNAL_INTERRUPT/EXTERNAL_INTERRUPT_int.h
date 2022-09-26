/***************************************************/
/* Title       : EXTERNAL INTERRUPT Interface file */
/* Author      : Joseph Tharwat                    */
/* Release     : 1.0                               */
/* Last Update : 6-9-2022                          */
/***************************************************/

#ifndef EXTERNAL_INTERRUPT_INT_H_
#define EXTERNAL_INTERRUPT_INT_H_

#include"STD_Types.h"

/*Chose interrupt pin INTn:
 *INT0
 *INT1
 *INT2
 */

/*Choose MODE for INT0:
 *INT0_ON_CHANGING
 *INT0_RISING_EDGE
 *INT0_FALLING_EDGE
 */

/*Choose MODE for INT1:
 *INT1_ON_CHANGING
 *INT1_RISING_EDGE
 *INT1_FALLING_EDGE
 */
void EXTERNAL_INTERRUPT_vid_EnableDefultConfigration(u8 u8_INTn);
void EXTERNAL_INTERRUPT_vid_EnableSetConfigration(u8 u8_INTn,u8 u8_configrationPin);
void EXTERNAL_INTERRUPT_vid_Disable(u8 u8_INTn);

void EXTERNAL_INTERRUPT_SetCallBack_INT0( void (*func_address)(void) );
void EXTERNAL_INTERRUPT_SetCallBack_INT1( void (*func_address)(void) );
void EXTERNAL_INTERRUPT_SetCallBack_INT2( void (*func_address)(void) );

#endif

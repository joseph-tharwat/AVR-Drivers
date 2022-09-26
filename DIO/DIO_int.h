/************************************************/
/* Title       : DIO Interface file             */
/* Author      : Joseph Tharwat                 */
/* Release     : 1.0                            */
/* Last Update : 5-9-2022                       */
/************************************************/

#ifndef DIO_int_H_
#define DIO_int_H_

#include"STD_Types.h"

/* value in get and set is:
 * PinValue_HIGH  	= 1
 * PinValue_LOW		= 0
*/

/*Chose pin number from 0 to 31 as DIO_u8_PIN_n
 * PORTA: from 0 to 7
 * PORTA: from 8 to 15
 * PORTA: from 16 to 23
 * PORTA: from 24 to 31
 */


void DIO_vid_Init();
void DIO_vid_SetPinValue(u8 DIO_u8_PinNumber,u8 DIO_u8_Value);
u8 DIO_u8_GetPinValue(u8 DIO_u8_PinNumber);
void DIO_vid_SetPullUp(u8 DIO_u8_PinNumber);
void DIO_vid_SetPortA(u8 u8_Data);
void DIO_vid_SetPortB(u8 u8_Data);
void DIO_vid_SetPortC(u8 u8_Data);
void DIO_vid_SetPortD(u8 u8_Data);
#endif


/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef KEYPAD_CONFIG_H
#define	KEYPAD_CONFIG_H
#include "DIO_int.h"


#define KEYPAD_R1C1   '7'
#define KEYPAD_R1C2   '8'
#define KEYPAD_R1C3   '9'
#define KEYPAD_R1C4   '/'

#define KEYPAD_R2C1   '4'
#define KEYPAD_R2C2   '5'
#define KEYPAD_R2C3   '6'
#define KEYPAD_R2C4   '*'

#define KEYPAD_R3C1   '1'
#define KEYPAD_R3C2   '2'
#define KEYPAD_R3C3   '3'
#define KEYPAD_R3C4   '-'

#define KEYPAD_R4C1   ' '
#define KEYPAD_R4C2   '0'
#define KEYPAD_R4C3   '='
#define KEYPAD_R4C4   '+'


#define KEYPAD_ROW1     DIO_u8_PIN_16
#define KEYPAD_ROW2     DIO_u8_PIN_17
#define KEYPAD_ROW3     DIO_u8_PIN_18
#define KEYPAD_ROW4     DIO_u8_PIN_19

#define KEYPAD_COLUMN1  DIO_u8_PIN_20
#define KEYPAD_COLUMN2  DIO_u8_PIN_21    
#define KEYPAD_COLUMN3  DIO_u8_PIN_22   
#define KEYPAD_COLUMN4  DIO_u8_PIN_23    

/*internal
  external*/
#define MODE  internal

#endif	


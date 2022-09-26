/* 
 * File:   LCD_configration
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef LCD_config_H
#define	LCD_config_H

#include "../DIO/DIO_priv.h"
/*Write your configration as you connect the LCD*/
//Data pins
#define LCD_PIN_D0    DIO_u8_PIN_16
#define LCD_PIN_D1    DIO_u8_PIN_17
#define LCD_PIN_D2    DIO_u8_PIN_18
#define LCD_PIN_D3    DIO_u8_PIN_19
#define LCD_PIN_D4    DIO_u8_PIN_20
#define LCD_PIN_D5    DIO_u8_PIN_21
#define LCD_PIN_D6    DIO_u8_PIN_22
#define LCD_PIN_D7    DIO_u8_PIN_23
//instruction pins
#define LCD_PIN_E      DIO_u8_PIN_24
#define LCD_PIN_RW     DIO_u8_PIN_25
#define LCD_PIN_RS     DIO_u8_PIN_26



#endif	


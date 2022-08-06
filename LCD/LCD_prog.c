/*
 * File:   LCD_prog.c
 * Author: Joseph Tharwat
 *
 * Created on August 17, 2021, 10:45 PM
 */

#include "STD_types.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"
#include "DIO_int.h"
#include "BIT_math.h"
#include <avr/delay.h>


void LCD_vid_init()
{
    _delay_ms(35);
    LCD_vid_WrithCMD(FUNCTION_SET);
    _delay_ms(1);
    LCD_vid_WrithCMD(DISPLAY_ON_OFF);
    _delay_ms(1);
    LCD_vid_WrithCMD(DISPLAY_CLEAR);
    _delay_ms(2);
    LCD_vid_WrithCMD(ENTERY_SET_MODE);
    
}

void LCD_ExecutData(u8 u8_DATA)
{
    DIO_vid_SetPinValue(LCD_PIN_RW,0);
    _delay_ms(1);
    DIO_vid_SetPinValue(LCD_PIN_E,1);
    _delay_ms(1);
    if(GET_BIT(u8_DATA,0)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D0,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D0,0);
    }
    
    if(GET_BIT(u8_DATA,1)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D1,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D1,0);
    }
    
    if(GET_BIT(u8_DATA,2)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D2,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D2,0);
    }
    
    if(GET_BIT(u8_DATA,3)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D3,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D3,0);
    }
    
    if(GET_BIT(u8_DATA,4)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D4,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D4,0);
    }
    
    if(GET_BIT(u8_DATA,5)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D5,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D5,0);
    }
    
    if(GET_BIT(u8_DATA,6)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D6,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D6,0);
    }
    
    if(GET_BIT(u8_DATA,7)==1)
    {
        DIO_vid_SetPinValue(LCD_PIN_D7,1);
    }
    else
    {
        DIO_vid_SetPinValue(LCD_PIN_D7,0);
    }
    
    DIO_vid_SetPinValue(LCD_PIN_E,0);
    _delay_ms(1);
    
}


void LCD_vid_WrithCMD(u8 u8_cmd)
{
    DIO_vid_SetPinValue(LCD_PIN_RS,0);
    LCD_ExecutData(u8_cmd);
    
}

void LCD_vid_WrithChar(u8 u8_char)
{
    DIO_vid_SetPinValue(LCD_PIN_RS,1);
    LCD_ExecutData(u8_char);
}

void LCD_vid_WrithString(u8* string)
{
    u8 index=0;
    while(string[index] != '\0')
    {
        LCD_vid_WrithChar(string[index]);
        index++;
    }
}
 
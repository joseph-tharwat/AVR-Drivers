/*
 * File:   UART_prog.c
 * Author: joseph
 *
 * Created on August 30, 2021, 8:17 AM
 */
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "UART_priv.h"

void UART_vid_Init()
{
    
    //set transimet enable
    SET_BIT(UCSRB,TXEN);
    
    //set character size 8 bit
    SET_BIT(UCSRC,UCSZ0);
    SET_BIT(UCSRC,UCSZ1);
    CLEAR_BIT(UCSRB,UCSZ2);
    
    //Mode sync
    SET_BIT(UCSRC,URSEL);//to write in UCSRC 
    SET_BIT(UCSRC,UMSEL);
    
    //Parity mode disable
    CLEAR_BIT(UCSRC,UPM0);
    CLEAR_BIT(UCSRC,UPM1);
    
    //Clock Polarity
    CLEAR_BIT(UCSRC,UCPOL); 
    
    //Bude rate 90
    UBRRL=6;
    CLEAR_BIT(UCSRC,URSEL); //to write in UBRRH
    UCSRC = 0;
    
}

void UART_vid_Send(u8 data)
{
    //set embty
    SET_BIT(UCSRA,UDRE);
    UDR =  data;
}

u8 UART_u8_Receive()
{
    u8 data = UDR;
    return data;
}
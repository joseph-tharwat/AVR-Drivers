/*
 * File:   SPI_prog.c
 * Author: joseph
 *
 * Created on August 31, 2021, 3:26 PM
 */

#include "STD_Types.h"
#include "SPI_priv.h"
#include "BIT_MATH.h"

void SPI_vid_Enable()
{
 //SPI enable
 SET_BIT(SPCR,SPE);
    
}
void SPI_vid_Init()
{
  
    //set interrupt enable
   // SET_BIT(SPCR,SPIE);
    //data order LSB
    SET_BIT(SPCR,DORD);
    //Master mode 
    SET_BIT(SPCR,MSTR);
    //Clock Polarity falling
    SET_BIT(SPCR,CPOL);
    //Clock Phase
    SET_BIT(SPCR,CPHA);
    //clock rate
    SET_BIT(SPCR,SPR0);
    CLEAR_BIT(SPCR,SPR1);
    CLEAR_BIT(SPSR,SPI2X);
    
    
}

void SPI_vid_Send(u8 data)
{
    SPDR = data;
}

u8 SPI_u8_Receive()
{
    u8 data = SPDR;
    return data;
}
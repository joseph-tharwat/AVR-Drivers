/*
 * File:   Stepper_prog.c
 * Author: joseph
 *
 * Created on August 21, 2021, 3:46 PM
 */

#include "DIO_int.h"
#include "Stepper_config.h"
#include "Stepper_int.h"
#include "Stepper_priv.h"
#include "STD_Types.h"
#include <util/delay.h>
        
u8 Globle_u8_STEPPER_DIRECTION = STEPPER_DIRECTION_ANTI_CLK;

void STEPPER_vid_Init(void)
{
    DIO_vid_SetPinValue(STEPPER_COIL_0,0);
    DIO_vid_SetPinValue(STEPPER_COIL_1,0);
    DIO_vid_SetPinValue(STEPPER_COIL_2,0);
    DIO_vid_SetPinValue(STEPPER_COIL_3,0);
    
}

void STEPPER_vid_SetSpeed(u8 STEPPER_Speed)
{
    //need to calc delay consider to speed
    u16 Local_delay=1000;
    
    u8 sequence[4]={STEPPER_COIL_0,STEPPER_COIL_1,STEPPER_COIL_2,STEPPER_COIL_3};
    
    if(Globle_u8_STEPPER_DIRECTION==STEPPER_DIRECTION_ANTI_CLK)
    {
        u8 index=0;
        //stop when the press button 
        while(!DIO_u8_GetPinValue(DIO_u8_PIN_16))
        {
            DIO_vid_SetPinValue(sequence[index],1);
            
            //stop the previous coil
            if(index==0)
            {
                 DIO_vid_SetPinValue(sequence[3],0); 
            }
            else
            {
                DIO_vid_SetPinValue(sequence[index-1],0); 
            }
            
            _delay_ms(Local_delay);
            
            index=(index+1)%4;
            
        }
        
    }
    else if(Globle_u8_STEPPER_DIRECTION==STEPPER_DIRECTION_CLK)
    {
        u8 index=3;
        while(!DIO_u8_GetPinValue(DIO_u8_PIN_16))
        {
            DIO_vid_SetPinValue(sequence[index],1);
            _delay_ms(Local_delay);
            
            //stop the previous coil
            if(index==3)
            {
                 DIO_vid_SetPinValue(sequence[0],0); 
            }
            else
            {
                DIO_vid_SetPinValue(sequence[index+1],0); 
            }
            
            if(index==0)
            {
                index=3;
            }
            else
            {
                index = index-1;
            }
            
            
        } 
    }
    STEPPER_vid_Init();
    
}

void STEPPER_vid_SetDirection(u8 STEPPER_Direction)
{
    Globle_u8_STEPPER_DIRECTION = STEPPER_Direction;
}

void STEPPER_vid_SetPosition(u8 STEPPER_Position)
{
    u16 Local_Nm_step = STEPPER_Position/STEP_SIZE;
    u8 sequence[4]={STEPPER_COIL_0,STEPPER_COIL_1,STEPPER_COIL_2,STEPPER_COIL_3};
    
    //need to calc delay consider to speed
    u16 Local_delay=1000;
    if(Globle_u8_STEPPER_DIRECTION==STEPPER_DIRECTION_ANTI_CLK)
    {
        u8 index=0;
        for(u16 i=0; i<Local_Nm_step; i++)
        {
            DIO_vid_SetPinValue(sequence[index],1);

                //stop the previous coil
                if(index==0)
                {
                     DIO_vid_SetPinValue(sequence[3],0); 
                }
                else
                {
                    DIO_vid_SetPinValue(sequence[index-1],0); 
                }

                _delay_ms(Local_delay);

                index=(index+1)%4;
        }
    }
    else if( Globle_u8_STEPPER_DIRECTION == STEPPER_DIRECTION_CLK )
    {
        u8 index=3;
        for(u16 i=0; i<Local_Nm_step; i++)
        {
            DIO_vid_SetPinValue(sequence[index],1);
            _delay_ms(Local_delay);
            
            //stop the previous coil
            if(index==3)
            {
                 DIO_vid_SetPinValue(sequence[0],0); 
            }
            else
            {
                DIO_vid_SetPinValue(sequence[index+1],0); 
            }
            
            if(index==0)
            {
                index=3;
            }
            else
            {
                index = index-1;
            }
        }  
    }
    
}

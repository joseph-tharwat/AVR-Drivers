/*
 * File:   KeyPad_prog.c
 * Author: joseph
 *
 * Created on August 19, 2021, 1:33 PM
 */
#include "STD_Types.h"
#include "KeyPad_config.h"
#include "KeyPad_init.h"
void KEYPAD_vid_init()
{
    #if MODE == internal
        DIO_vid_SetPinValue(KEYPAD_ROW1,1);
        DIO_vid_SetPinValue(KEYPAD_ROW2,1);
        DIO_vid_SetPinValue(KEYPAD_ROW3,1);
        DIO_vid_SetPinValue(KEYPAD_ROW4,1);
    #endif
    //else:
        //do nothing, the pull up resistor must put externally
    
}

u8 KEYPAD_GetButtonValueHelper(u8 cl)
{
    u8 btn='\n';
        DIO_vid_SetPinValue(KEYPAD_ROW1,0);
        DIO_vid_SetPinValue(KEYPAD_ROW2,1);
        DIO_vid_SetPinValue(KEYPAD_ROW3,1);
        DIO_vid_SetPinValue(KEYPAD_ROW4,1);
        if(DIO_u8_GetPinValue(cl)==0)
        {
            if(cl==KEYPAD_COLUMN1)
            {
               btn= KEYPAD_R1C1;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN2)
            {
               btn= KEYPAD_R1C2;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN3)
            {
               btn= KEYPAD_R1C3;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN4)
            {
               btn= KEYPAD_R1C4;
               return btn; 
            } 
        }
        
        DIO_vid_SetPinValue(KEYPAD_ROW1,1);
        DIO_vid_SetPinValue(KEYPAD_ROW2,0);
        DIO_vid_SetPinValue(KEYPAD_ROW3,1);
        DIO_vid_SetPinValue(KEYPAD_ROW4,1);
        if(DIO_u8_GetPinValue(cl)==0)
        {
            if(cl==KEYPAD_COLUMN1)
            {
               btn= KEYPAD_R2C1;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN2)
            {
               btn= KEYPAD_R2C2;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN3)
            {
               btn= KEYPAD_R2C3;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN4)
            {
               btn= KEYPAD_R2C4;
               return btn; 
            } 
        }
        
        DIO_vid_SetPinValue(KEYPAD_ROW1,1);
        DIO_vid_SetPinValue(KEYPAD_ROW2,1);
        DIO_vid_SetPinValue(KEYPAD_ROW3,0);
        DIO_vid_SetPinValue(KEYPAD_ROW4,1);
        if(DIO_u8_GetPinValue(cl)==0)
        {
            if(cl==KEYPAD_COLUMN1)
            {
               btn= KEYPAD_R3C1;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN2)
            {
               btn= KEYPAD_R3C2;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN3)
            {
               btn= KEYPAD_R3C3;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN4)
            {
               btn= KEYPAD_R4C4;
               return btn; 
            } 
        }
        
        DIO_vid_SetPinValue(KEYPAD_ROW1,1);
        DIO_vid_SetPinValue(KEYPAD_ROW2,1);
        DIO_vid_SetPinValue(KEYPAD_ROW3,1);
        DIO_vid_SetPinValue(KEYPAD_ROW4,0);
        if(DIO_u8_GetPinValue(cl)==0)
        {
            if(cl==KEYPAD_COLUMN1)
            {
               btn= KEYPAD_R4C1;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN2)
            {
               btn= KEYPAD_R4C2;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN3)
            {
               btn= KEYPAD_R4C3;
               return btn; 
            }
            else if(cl==KEYPAD_COLUMN4)
            {
               btn= KEYPAD_R4C4;
               return btn; 
            } 
        }
        
        return btn;
}

u8 KEYPAD_u8_GetButtonValue()
{
    u8 button='\n';
    
    if(DIO_u8_GetPinValue(KEYPAD_COLUMN1)==1)
    {
        button= KEYPAD_GetButtonValueHelper(KEYPAD_COLUMN1);
        KEYPAD_vid_init();
        return button;
    }
    else if(DIO_u8_GetPinValue(KEYPAD_COLUMN2)==1)
    {
        button= KEYPAD_GetButtonValueHelper(KEYPAD_COLUMN2);
        KEYPAD_vid_init();
        return button;
    }
    else if(DIO_u8_GetPinValue(KEYPAD_COLUMN3)==1)
    {
        button= KEYPAD_GetButtonValueHelper(KEYPAD_COLUMN3);
        KEYPAD_vid_init();
        return button;
    }
    else if(DIO_u8_GetPinValue(KEYPAD_COLUMN4)==1)
    {
        button= KEYPAD_GetButtonValueHelper(KEYPAD_COLUMN4);
        KEYPAD_vid_init();
        return button;
    }
    KEYPAD_vid_init();
    return button;
           
}

/*
 * File:   KeyPad_prog.c
 * Author: joseph
 *
 * Created on August 19, 2021, 1:33 PM
 */
#include "../DIO/STD_Types.h"
#include "../DIO/DIO_priv.h"
#include "KeyPad_config.h"
#include "KeyPad_init.h"
void KEYPAD_vid_init()
{
    #if MODE == internal
        DIO_vid_SetPinValue(KEYPAD_ROW1,1);
        DIO_vid_SetPinValue(KEYPAD_ROW2,1);
        DIO_vid_SetPinValue(KEYPAD_ROW3,1);
        DIO_vid_SetPinValue(KEYPAD_ROW4,1);

       // DIO_vid_SetPullUp(DIO_u8_PIN_12);
    #endif
    //else:
        //do nothing, the pull up resistor must put externally
    
}

u8 KEYPAD_u8_GetButtonValue()
{
	u8 ButtonValue='\n';

	DIO_vid_SetPinValue(KEYPAD_ROW1,0);
	DIO_vid_SetPinValue(KEYPAD_ROW2,1);
	DIO_vid_SetPinValue(KEYPAD_ROW3,1);
	DIO_vid_SetPinValue(KEYPAD_ROW4,1);
	if(DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R1C1;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R1C2;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R1C3;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R1C4;
	}

	DIO_vid_SetPinValue(KEYPAD_ROW1,1);
	DIO_vid_SetPinValue(KEYPAD_ROW2,0);
	DIO_vid_SetPinValue(KEYPAD_ROW3,1);
	DIO_vid_SetPinValue(KEYPAD_ROW4,1);
	if(DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R2C1;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R2C2;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R2C3;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R2C4;
	}

	DIO_vid_SetPinValue(KEYPAD_ROW1,1);
	DIO_vid_SetPinValue(KEYPAD_ROW2,1);
	DIO_vid_SetPinValue(KEYPAD_ROW3,0);
	DIO_vid_SetPinValue(KEYPAD_ROW4,1);
	if(DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R3C1;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R3C2;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R3C3;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R3C4;
	}

	DIO_vid_SetPinValue(KEYPAD_ROW1,1);
	DIO_vid_SetPinValue(KEYPAD_ROW2,1);
	DIO_vid_SetPinValue(KEYPAD_ROW3,1);
	DIO_vid_SetPinValue(KEYPAD_ROW4,0);
	if(DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R4C1;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R4C2;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R4C3;
	}
	else if(DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_u8_LOW)
	{
		ButtonValue = KEYPAD_R4C4;
	}

	DIO_vid_SetPinValue(KEYPAD_ROW1,1);
	DIO_vid_SetPinValue(KEYPAD_ROW2,1);
	DIO_vid_SetPinValue(KEYPAD_ROW3,1);
	DIO_vid_SetPinValue(KEYPAD_ROW4,1);

	return ButtonValue;




}

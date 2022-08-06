/*
 * File:   GIE_prog.c
 * Author: Joseph Tharwat
 *
 * Created on August 22, 2021, 4:39 PM
 */

#include "GIE_priv.h"
#include "BIT_MATH.h"

void GIE_vid_SetEnable()
{
    SET_BIT(SREG_REGISTER,GIE_BIT);    
}

void GIE_vid_Set_Disable()
{
    CLEAR_BIT(SREG_REGISTER,GIE_BIT);
}
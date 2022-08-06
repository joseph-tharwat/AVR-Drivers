/*
 * File:   EXTERNAL INTERRUPT_prog.c
 * Author: joseph
 *
 * Created on August 22, 2021, 5:04 PM
 */

#include "BIT_MATH.h"
#include "EXTERNAL_INTERRUPT_priv.h"
#include "EXTERNAL_INTERRUPT_config.h"

void (*EXTERNAL_INTERRUPT_SetCallBackFunc)(void);

void __vector_1(void) __attribute__((signal,used));

void __vector_1(void)
{
    EXTERNAL_INTERRUPT_SetCallBackFunc();
}

void EXTERNAL_INTERRUPT_Init()
{
SET_BIT(GICR_REGISTER,GICR_INT0_BIT);

#if (MOODE == FALLING_MODE)//10
    CLEAR_BIT(MCUCR_REGISTER,MCUCR_ISC00_BIT);
    SET_BIT(MCUCR_REGISTER,MCUCR_ISC01_BIT);
#elif (MOODE == RISING_MODE)//11
    SET_BIT(MCUCR_REGISTER,MCUCR_ISC00_BIT);
    SET_BIT(MCUCR_REGISTER,MCUCR_ISC01_BIT);
#elif (MOODE==ONCHANGE_MODE)//01
    SET_BIT(MCUCR_REGISTER,MCUCR_ISC00_BIT);
    CLEAR_BIT(MCUCR_REGISTER,MCUCR_ISC01_BIT);
#endif
    
}

void EXTERNAL_INTERRUPT_SetCallBack( void (*func_address)(void) )
{
    EXTERNAL_INTERRUPT_SetCallBackFunc = func_address;
}
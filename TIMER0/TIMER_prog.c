/*
 * File:   TIMER_prog.c
 * Author: joseph
 *
 * Created on August 24, 2021, 2:26 PM
 */
#include "STD_Types.h"
#include "TIMER_priv.h"
#include "DIO_int.h"
#include "BIT_MATH.h"
#include "TIMER_config.h"

void (*TIMER_OVERFLOW_INTERRUPT)(void);
void (*TIMER_COMPARE_INTERRUPT)(void);


void __vector_10(void) __attribute__((signal,used));    //compare 
void __vector_11(void) __attribute__((signal,used));    //overflow

void __vector_10(void)
{
    TIMER_COMPARE_INTERRUPT();
}

void __vector_11(void)
{
    TIMER_OVERFLOW_INTERRUPT();
}




void TIMER0_vid_Init(void)
{
 /*
 * Select Waveform Generation Mode :
 00 > Normal
 01 > PWM, Phase Correct
 10 > CTC
 11 > Fast PWM
 */
//#define WGM00 6
//#define WGM01 3
    
#if (Waveform_Generation_Mode == Normal_MODE)
    CLEAR_BIT(TCCR0,WGM00);
    CLEAR_BIT(TCCR0,WGM01);
#elif (Waveform_Generation_Mode == PWM_Phase_Correct_MODE) 
    CLEAR_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);
#elif (Waveform_Generation_Mode == CTC_MODE)
    SET_BIT(TCCR0,WGM00);
    CLEAR_BIT(TCCR0,WGM01);
#elif (Waveform_Generation_Mode == Fast_PWM_MODE)
    SET_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);
#endif
    
    
 /*
 * OC0 pin:
 *Compare Output Mode, non-PWM Mode
 00 >  Normal port operation, OC0 disconnected.
 01 >  Toggle OC0 on compare match
 10 >  Clear OC0 on compare match
 11 >  Set OC0 on compare match
 
 *Compare Output Mode, Fast PWM Mode
 
 *Compare Output Mode, Phase Correct PWM Mode
 
 */
#if (OC0_pin_output == OC0_NORMAL)
   CLEAR_BIT(TCCR0,COM00);
   CLEAR_BIT(TCCR0,COM01);  
#elif (OC0_pin_output == OC0_TOGGLE)
   SET_BIT(TCCR0,COM00);
   CLEAR_BIT(TCCR0,COM01);  
#elif (OC0_pin_output == OC0_CLEAR)
    CLEAR_BIT(TCCR0,COM00);
    SET_BIT(TCCR0,COM01);
#elif (OC0_pin_output == OC0_SET)
    SET_BIT(TCCR0,COM00);
    SET_BIT(TCCR0,COM01);
#endif
    
   
 /*
 *Set in initialization function
 000 >  No clock source (Timer/Counter stopped)
 001 > clk/(No prescaling)
 010 > clkI/8 (From prescaler)
 011 > clk/64 (From prescaler)
 100 > clk/256 (From prescaler)
 101 > clk/1024 (From prescaler)
 110 > External clock source on T0 pin. Clock on falling edge
 111 > External clock source on T0 pin. Clock on rising edge
 */
    
#if ( CLK_SELECT == NO_CLK )    
    CLEAR_BIT(TCCR0,CS00);
    CLEAR_BIT(TCCR0,CS01);
    CLEAR_BIT(TCCR0,CS02);
#elif (CLK_SELECT == CLK_NO_PRESCALING)
    SET_BIT(TCCR0,CS00);
    CLEAR_BIT(TCCR0,CS01);
    CLEAR_BIT(TCCR0,CS02);
#elif (CLK_SELECT == CLK_8)
    CLEAR_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    CLEAR_BIT(TCCR0,CS02);
#elif (CLK_SELECT == CLK_64)
    SET_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    CLEAR_BIT(TCCR0,CS02);
#elif (CLK_SELECT == CLK_256)
    CLEAR_BIT(TCCR0,CS00);
    CLEAR_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
#elif (CLK_SELECT == CLK_1024)
    SET_BIT(TCCR0,CS00);
    CLEAR_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
#elif(CLK_SELECT == CLK_EXTERNAL_FALLING)
    CLEAR_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
#elif(CLK_SELECT == CLK_EXTERNAL_RISING)
    SET_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
#endif
     
    //Enable the interrupts (logic 0)
    CLEAR_BIT(TIMSK,TOIE0);
    CLEAR_BIT(TIMSK,OCIE0);
    //clear the flags (clear with logic 1)
    SET_BIT(TIFR,TOV0);
    SET_BIT(TIFR,OCF0);
    //Clear Register
    TCNT0 = 0 ;
	OCR0 = 0 ;
    
}

void TIMER0_vid_SetTimerReg(u8 Copy_u8_Val)
{
    TCNT0 = Copy_u8_Val;
}

void TIMER0_vid_SetCompareReg(u8 Copy_u8_Val)
{
    OCR0 = Copy_u8_Val;
}

void TIMER0_vid_EnableOVInt(void)
{
    SET_BIT(TIMSK,TOIE0);
    
}

void TIMER0_vid_DisableOVInt(void)
{
    CLEAR_BIT(TIMSK,TOIE0);
}

void TIMER0_vid_EnableCTCInt(void)
{
    SET_BIT(TIMSK,OCIE0);
}
void TIMER0_vid_DisableCTCInt(void)
{
    CLEAR_BIT(TIMSK,OCIE0);
}

void TIMER0_vid_SetOVIntCallBack(void (*Copy_ptr)(void))
{
     TIMER_OVERFLOW_INTERRUPT = Copy_ptr;
}
void TIMER0_vid_SetCTCIntCallBack(void (*Copy_ptr)(void))
{
    TIMER_COMPARE_INTERRUPT = Copy_ptr;
}
/***************************************************/
/* Title       : TIMER0 program file   */
/* Author      : Joseph Tharwat                    */
/* Release     : 1.0                               */
/* Last Update : 6-9-2022                          */
/***************************************************/

#include "BIT_MATH.h"
#include "TIMER0_int.h"
#include "TIMER0_config.h"
#include "TIMER0_priv.h"

u8 u8_TIMER0_MODE = TIMER0_MODE;

void (*TIMER0_SetCallBackFunc_OVERFLOW)(void);

void __vector_11(void) __attribute__((signal,used));

void __vector_11(void)
{
	TIMER0_SetCallBackFunc_OVERFLOW();
}

void TIMER0_SetCallBack_OVERFLOW( void (*func_address)(void) )
{
    TIMER0_SetCallBackFunc_OVERFLOW = func_address;
}
//////////////

void (*TIMER0_SetCallBackFunc_COMP)(void);

void __vector_10(void) __attribute__((signal,used));

void __vector_10(void)
{
	TIMER0_SetCallBackFunc_COMP();
}

void TIMER0_SetCallBack_COMP( void (*func_address)(void) )
{
    TIMER0_SetCallBackFunc_COMP = func_address;
}
//////////

void TIMER0_vid_CompareOnMatchInterruptSetEnable()
{
	SET_BIT(TIMSK,TIMSK_OCIE0_BIT);
}

void TIMER0_vid_OverflowInterruptSetEnable()
{
	SET_BIT(TIMSK,TIMSK_TOIE0_BIT);
}

void TIMER0_vid_CompareOnMatchInterruptSetDisable()
{
	CLEAR_BIT(TIMSK,TIMSK_OCIE0_BIT);
}

void TIMER0_vid_OverflowInterruptSetDisable()
{
	CLEAR_BIT(TIMSK,TIMSK_TOIE0_BIT);
}

void TIMER0_vid_SetTimerRegister(u8 u8_TimerRegisterValue)
{
	TCNT0 = u8_TimerRegisterValue;
}

void TIMER0_vid_SetOutputCompareRegister(u8 u8_OutputCompareRegisterValue)
{
	OCR0 = u8_OutputCompareRegisterValue;
}

void TIMER0_vid_SetDutyCycle(u8 u8_DutyCyclePrcent)
{
	u8 u8_OCR0Value = (u8)(u8_DutyCyclePrcent* TIMER0_MAX_VALUE / 100);
	OCR0 = u8_OCR0Value;
	/*if(u8_OCR0Value >= 1)
	{
		OCR0 = u8_OCR0Value;
	}
	else
	{
		OCR0 = 0;
	}*/
}
/*
void TIMER0_vid_SetTimer0DefultMode()
{
	if(TIMER0_MODE == NORMAL_MODE)
	{
		CLEAR_BIT(TCCR0,TCCR0_WGM00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_BIT);
	}
	else if(TIMER0_MODE == PWM_MODE)
	{
		SET_BIT(TCCR0,TCCR0_WGM00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_BIT);
	}
	else if(TIMER0_MODE == CTC_MODE)
	{
		SET_BIT(TCCR0,TCCR0_WGM01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM00_BIT);
	}
	else if(TIMER0_MODE == FASTPWM_MODE)
	{
		SET_BIT(TCCR0,TCCR0_WGM01_BIT);
		SET_BIT(TCCR0,TCCR0_WGM00_BIT);
	}
}
*/

void TIMER0_vid_SetTimer0Mode(u8 u8_Timer0Mode)
{
	u8_TIMER0_MODE = u8_Timer0Mode;

	if(u8_Timer0Mode == NORMAL_MODE)
	{
		SET_BIT(TCCR0,TCCR0_FOC0_BIT);

		CLEAR_BIT(TCCR0,TCCR0_WGM00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_BIT);
	}
	else if(u8_Timer0Mode == PWM_MODE)
	{
		CLEAR_BIT(TCCR0,TCCR0_FOC0_BIT);

		SET_BIT(TCCR0,TCCR0_WGM00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_BIT);
	}
	else if(u8_Timer0Mode == CTC_MODE)
	{
		SET_BIT(TCCR0,TCCR0_FOC0_BIT);

		SET_BIT(TCCR0,TCCR0_WGM01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM00_BIT);
	}
	else if(u8_Timer0Mode == FASTPWM_MODE)
	{
		CLEAR_BIT(TCCR0,TCCR0_FOC0_BIT);

		SET_BIT(TCCR0,TCCR0_WGM01_BIT);
		SET_BIT(TCCR0,TCCR0_WGM00_BIT);
	}
}

void TIMER0_vid_SetClock(u8 u8_ClockFrequency)
{
	if(u8_ClockFrequency == STOPPED)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == CLK)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == CLK_DIV_8)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == CLK_DIV_64)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == CLK_DIV_256)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == CLK_DIV_1024)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == EXTERNAL_FALLING_EDGE)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(u8_ClockFrequency == EXTERNAL_RISING_EDGE)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
}

void TIMER0_vid_SetOC0Mode(u8 u8_OC0Mode)
{
	if(u8_TIMER0_MODE == NORMAL_MODE || u8_TIMER0_MODE == CTC_MODE)
	{
		if(u8_OC0Mode == OC0_DISCONNECTED)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_TOGGLE)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_CLEAR)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_SET)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
	}
	else if(u8_TIMER0_MODE == PWM_MODE)
	{
		if(u8_OC0Mode == OC0_DISCONNECTED)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_CLEAR_ON_COMPARE_COUNTING_UP_SET_ON_COMPARE_COUNTING_DOWN)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_SET_ON_COMPARE_COUNTING_UP_CLEAR_ON_COMPARE_COUNTING_DOWN)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
	}
	else if(u8_TIMER0_MODE == FASTPWM_MODE)
	{
		if(u8_OC0Mode == OC0_DISCONNECTED)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_CLEAR_ON_COMPARE_SET_AT_TOP)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(u8_OC0Mode == OC0_SET_ON_COMPARE_CLEAR_AT_TOP)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
	}

}





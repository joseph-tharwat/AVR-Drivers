/***************************************************/
/* Title       : EXTERNAL INTERRUPT program file   */
/* Author      : Joseph Tharwat                    */
/* Release     : 1.0                               */
/* Last Update : 6-9-2022                          */
/***************************************************/

#include "EXTERNAL_INTERRUPT_int.h"
#include "BIT_MATH.h"
#include "EXTERNAL_INTERRUPT_priv.h"
#include "EXTERNAL_INTERRUPT_config.h"

void (*EXTERNAL_INTERRUPT_SetCallBackFunc_INT0)(void);

void __vector_1(void) __attribute__((signal,used));

void __vector_1(void)
{
	EXTERNAL_INTERRUPT_SetCallBackFunc_INT0();
}

void EXTERNAL_INTERRUPT_SetCallBack_INT0( void (*func_address)(void) )
{
    EXTERNAL_INTERRUPT_SetCallBackFunc_INT0 = func_address;
}
////////////////////////////////////////////////////////////////////
void (*EXTERNAL_INTERRUPT_SetCallBackFunc_INT1)(void);

void __vector_2(void) __attribute__((signal,used));

void __vector_2(void)
{
	EXTERNAL_INTERRUPT_SetCallBackFunc_INT1();
}

void EXTERNAL_INTERRUPT_SetCallBack_INT1( void (*func_address)(void) )
{
    EXTERNAL_INTERRUPT_SetCallBackFunc_INT1 = func_address;
}
/////////////////////////////////////////////////////////////////////
void (*EXTERNAL_INTERRUPT_SetCallBackFunc_INT2)(void);

void __vector_3(void) __attribute__((signal,used));

void __vector_3(void)
{
	EXTERNAL_INTERRUPT_SetCallBackFunc_INT2();
}

void EXTERNAL_INTERRUPT_SetCallBack_INT2( void (*func_address)(void) )
{
    EXTERNAL_INTERRUPT_SetCallBackFunc_INT2 = func_address;
}


void EXTERNAL_INTERRUPT_vid_EnableDefultConfigration(u8 u8_INTn)
{
	if(u8_INTn == INT0)
	{
		SET_BIT(GICR,GICR_INT0_BIT);
		if(INT0_MODE == INT0_LowLevel)
		{
			CLEAR_BIT(MCUCR,MCUCR_ISC00_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC01_BIT);
		}
		else if(INT0_MODE == INT0_ON_CHANGING)
		{
			SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC01_BIT);
		}
		else if(INT0_MODE == INT0_FALLING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC01_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC00_BIT);
		}
		else if(INT0_MODE == INT0_RISING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR,MCUCR_ISC01_BIT);
		}
	}
	else if(u8_INTn == INT1)
	{
		SET_BIT(GICR,GICR_INT1_BIT);
		if(INT1_MODE == INT1_LowLevel)
		{
			CLEAR_BIT(MCUCR,MCUCR_ISC11_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC10_BIT);
		}
		else if(INT1_MODE == INT1_ON_CHANGING)
		{
			SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC11_BIT);
		}
		else if(INT1_MODE == INT1_FALLING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC11_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC10_BIT);
		}
		else if(INT1_MODE == INT1_RISING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			SET_BIT(MCUCR,MCUCR_ISC11_BIT);
		}
	}
	else if(u8_INTn == INT2)
	{
		SET_BIT(GICR,GICR_INT2_BIT);
		if(INT2_MODE == INT2_RISING_EDGE)
		{
			SET_BIT(MCUCSR,MCUCSR_ISC2_BIT);
		}
		else if(INT2_MODE == INT2_FALLING_EDGE)
		{
			CLEAR_BIT(MCUCSR,MCUCSR_ISC2_BIT);
		}
	}
}

void EXTERNAL_INTERRUPT_vid_EnableSetConfigration(u8 u8_INTn,u8 u8_configrationPin)
{


	if(u8_INTn == INT0)
	{
		SET_BIT(GICR,GICR_INT0_BIT);
		if(u8_configrationPin == INT0_LowLevel)
		{
			CLEAR_BIT(MCUCR,MCUCR_ISC00_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC01_BIT);
		}
		else if(u8_configrationPin == INT0_ON_CHANGING)
		{
			SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC01_BIT);
		}
		else if(u8_configrationPin == INT0_FALLING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC01_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC00_BIT);
		}
		else if(u8_configrationPin == INT0_RISING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR,MCUCR_ISC01_BIT);
		}
	}
	else if(u8_INTn == INT1)
	{
		SET_BIT(GICR,GICR_INT1_BIT);
		if(u8_configrationPin == INT1_LowLevel)
		{
			CLEAR_BIT(MCUCR,MCUCR_ISC11_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC10_BIT);
		}
		else if(u8_configrationPin == INT1_ON_CHANGING)
		{
			SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC11_BIT);
		}
		else if(u8_configrationPin == INT1_FALLING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC11_BIT);
			CLEAR_BIT(MCUCR,MCUCR_ISC10_BIT);
		}
		else if(u8_configrationPin == INT1_RISING_EDGE)
		{
			SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			SET_BIT(MCUCR,MCUCR_ISC11_BIT);
		}
	}
	else if(u8_INTn == INT2)
	{
		SET_BIT(GICR,GICR_INT2_BIT);
		if(u8_configrationPin == INT2_RISING_EDGE)
		{
			SET_BIT(MCUCSR,MCUCSR_ISC2_BIT);
		}
		else if(u8_configrationPin == INT2_FALLING_EDGE)
		{
			CLEAR_BIT(MCUCSR,MCUCSR_ISC2_BIT);
		}
	}
}

void EXTERNAL_INTERRUPT_vid_Disable(u8 u8_INTn)
{
	if(u8_INTn == INT0)
		CLEAR_BIT(GICR,GICR_INT0_BIT);
	else if(u8_INTn == INT1)
			CLEAR_BIT(GICR,GICR_INT1_BIT);
	else if(u8_INTn == INT2)
			CLEAR_BIT(GICR,GICR_INT2_BIT);
}





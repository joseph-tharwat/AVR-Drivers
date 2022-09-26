/************************************************/
/* Title       : DIO program file               */
/* Author      : Joseph Tharwat                 */
/* Release     : 1.0                            */
/* Last Update : 5-9-2022                       */
/************************************************/


#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "BIT_MATH.h"

void DIO_vid_Init()
{
	DDRA =CONC_BIT(DIO_U8_Direction_PIN_7,DIO_U8_Direction_PIN_6,DIO_U8_Direction_PIN_5,DIO_U8_Direction_PIN_4,DIO_U8_Direction_PIN_3,DIO_U8_Direction_PIN_2,DIO_U8_Direction_PIN_1,DIO_U8_Direction_PIN_0);
	DDRB =CONC_BIT(DIO_U8_Direction_PIN_15,DIO_U8_Direction_PIN_14,DIO_U8_Direction_PIN_13,DIO_U8_Direction_PIN_12,DIO_U8_Direction_PIN_11,DIO_U8_Direction_PIN_10,DIO_U8_Direction_PIN_9,DIO_U8_Direction_PIN_8);
	DDRC =CONC_BIT(DIO_U8_Direction_PIN_23,DIO_U8_Direction_PIN_22,DIO_U8_Direction_PIN_21,DIO_U8_Direction_PIN_20,DIO_U8_Direction_PIN_19,DIO_U8_Direction_PIN_18,DIO_U8_Direction_PIN_17,DIO_U8_Direction_PIN_16);
	DDRD =CONC_BIT(DIO_U8_Direction_PIN_31,DIO_U8_Direction_PIN_30,DIO_U8_Direction_PIN_29,DIO_U8_Direction_PIN_28,DIO_U8_Direction_PIN_27,DIO_U8_Direction_PIN_26,DIO_U8_Direction_PIN_25,DIO_U8_Direction_PIN_24);
}

void DIO_vid_SetPinValue(u8 DIO_u8_PinNumber,u8 DIO_u8_Value)
{
	if(DIO_u8_PinNumber >= PORTA_START && DIO_u8_PinNumber <= PORTA_END)
	{
		if(DIO_u8_Value == DIO_u8_HIGH)
			SET_BIT(PORTA,DIO_u8_PinNumber);
		else if(DIO_u8_Value == DIO_u8_LOW)
			CLEAR_BIT(PORTA,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTB_START && DIO_u8_PinNumber <= PORTB_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTB_START;

		if(DIO_u8_Value == DIO_u8_HIGH)
			SET_BIT(PORTB,DIO_u8_PinNumber);
		else if(DIO_u8_Value == DIO_u8_LOW)
			CLEAR_BIT(PORTB,DIO_u8_PinNumber);

	}
	else if(DIO_u8_PinNumber >= PORTC_START && DIO_u8_PinNumber <= PORTC_END)
	{
		DIO_u8_PinNumber =DIO_u8_PinNumber - PORTC_START;

		if(DIO_u8_Value == DIO_u8_HIGH)
			SET_BIT(PORTC,DIO_u8_PinNumber);
		else if(DIO_u8_Value == DIO_u8_LOW)
			CLEAR_BIT(PORTC,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTD_START && DIO_u8_PinNumber <= PORTD_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber- PORTD_START;

		if(DIO_u8_Value == DIO_u8_HIGH)
			SET_BIT(PORTD,DIO_u8_PinNumber);
		else if(DIO_u8_Value == DIO_u8_LOW)
			CLEAR_BIT(PORTD,DIO_u8_PinNumber);

	}
}

void DIO_vid_SetPortA(u8 u8_Data)
{
	PORTA = u8_Data;
}
void DIO_vid_SetPortB(u8 u8_Data)
{
	PORTB = u8_Data;
}
void DIO_vid_SetPortC(u8 u8_Data)
{
	PORTC = u8_Data;
}
void DIO_vid_SetPortD(u8 u8_Data)
{
	PORTD = u8_Data;
}
u8 DIO_u8_GetPinValue(u8 DIO_u8_PinNumber)
{
	u8 u8_return;
	if(DIO_u8_PinNumber >= PORTA_START && DIO_u8_PinNumber <= PORTA_END)
	{
		u8_return = GET_BIT(PINA,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTB_START && DIO_u8_PinNumber <= PORTB_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTB_START;
		u8_return = GET_BIT(PINB,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTC_START && DIO_u8_PinNumber <= PORTC_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTC_START;
		u8_return = GET_BIT(PINC,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTD_START && DIO_u8_PinNumber <= PORTD_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTD_START;
		u8_return = GET_BIT(PIND, DIO_u8_PinNumber);
	}
	return u8_return;
}

void DIO_vid_SetPullUp(u8 DIO_u8_PinNumber)
{
	if(DIO_u8_PinNumber >= PORTA_START && DIO_u8_PinNumber <= PORTA_END)
	{
		SET_BIT(PORTA,DIO_u8_PinNumber);
		CLEAR_BIT(DDRA,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTB_START && DIO_u8_PinNumber <= PORTB_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTB_START;
		SET_BIT(PORTB,DIO_u8_PinNumber);
		CLEAR_BIT(DDRB,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTC_START && DIO_u8_PinNumber <= PORTC_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTC_START;
		SET_BIT(PORTC,DIO_u8_PinNumber);
		CLEAR_BIT(DDRC,DIO_u8_PinNumber);
	}
	else if(DIO_u8_PinNumber >= PORTD_START && DIO_u8_PinNumber <= PORTD_END)
	{
		DIO_u8_PinNumber = DIO_u8_PinNumber - PORTD_START;
		SET_BIT(PORTD,DIO_u8_PinNumber);
		CLEAR_BIT(DDRD,DIO_u8_PinNumber);
	}
}

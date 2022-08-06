/************************************************/
/* Title       : DIO program file               */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/


#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"


void DIO_vid_Init(void)
{
	DDRA = DIO_u8_PORTA_DIRECTION ;
	DDRB = DIO_u8_PORTB_DIRECTION ;
	DDRC = DIO_u8_PORTC_DIRECTION ;
	DDRD = DIO_u8_PORTD_DIRECTION ;

}

void DIO_vid_SetPinValue(u8 Copy_u8_PinNo , u8 Copy_u8_Value)
{
	if( (Copy_u8_PinNo >=DIO_u8_PORTA_START) && (Copy_u8_PinNo <=DIO_u8_PORTA_END) )
			{
				/*Get Valid Range for PORTB pins */
				//Copy_u8PinNum = Copy_u8PinNum - DIO_u8_PORTA_SIZE ;
				if(Copy_u8_Value == DIO_u8_HIGH)
				{
					SET_BIT(PORTA , Copy_u8_PinNo);
				}
				else
				{
					CLEAR_BIT(PORTA , Copy_u8_PinNo);
				}
			}
	if( (Copy_u8_PinNo >= DIO_u8_PORTB_START) && (Copy_u8_PinNo <= DIO_u8_PORTB_END) )
		{
			/*Get Valid Range for PORTB pins */
			Copy_u8_PinNo = Copy_u8_PinNo - DIO_u8_PORTA_SIZE ;
			if(Copy_u8_Value == DIO_u8_HIGH)
			{
				SET_BIT(PORTB , Copy_u8_PinNo);
			}
			else
			{
					CLEAR_BIT(PORTB , Copy_u8_PinNo);
			}
		}

		if( (Copy_u8_PinNo >=DIO_u8_PORTC_START) && (Copy_u8_PinNo <=DIO_u8_PORTC_END) )
		{
			/*Get Valid Range for PORTC pins */
			Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORTA_SIZE  + DIO_u8_PORTB_SIZE ) ;
			if(Copy_u8_Value == DIO_u8_HIGH)
			{
				SET_BIT(PORTC , Copy_u8_PinNo);
			}
			else
			{
					CLEAR_BIT(PORTC , Copy_u8_PinNo);
			}
		}

		if( (Copy_u8_PinNo >=DIO_u8_PORTD_START) && (Copy_u8_PinNo <=DIO_u8_PORTD_END) )
		{
			/*Get Valid Range for PORTD pins */
			Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE) ;
			if(Copy_u8_Value == DIO_u8_HIGH)
			{
				SET_BIT(PORTD , Copy_u8_PinNo);
			}
			else
			{
					CLEAR_BIT(PORTD , Copy_u8_PinNo);
			}
		}

}

u8 DIO_u8_GetPinValue(u8 Copy_u8_PinNo)
{
	u8 Local_u8Result;

		/* Find PORTA Pins                        */
		if( (Copy_u8_PinNo >=DIO_u8_PORTA_START) && (Copy_u8_PinNo <=DIO_u8_PORTA_END) )
		{
			/*Get Valid Range for PORTA pins */
			//Copy_u8_PinNo = Copy_u8_PinNo - DIO_u8_PORTA_SIZE ;
			Local_u8Result = GET_BIT(PINA , Copy_u8_PinNo);
			if(Local_u8Result == 1)
			{
				Local_u8Result = DIO_u8_HIGH ;
			}
			else
			{
				Local_u8Result = DIO_u8_LOW ;
			}
		}

		if( (Copy_u8_PinNo >=DIO_u8_PORTB_START) && (Copy_u8_PinNo <=DIO_u8_PORTB_END) )
		{
			/*Get Valid Range for PORTB pins */
			Copy_u8_PinNo = Copy_u8_PinNo - DIO_u8_PORTA_SIZE ;
			Local_u8Result = GET_BIT(PINB , Copy_u8_PinNo);
			if(Local_u8Result == 1)
			{
				Local_u8Result = DIO_u8_HIGH ;
			}
			else
			{
				Local_u8Result = DIO_u8_LOW ;
			}
		}

		if( (Copy_u8_PinNo >=DIO_u8_PORTC_START) && (Copy_u8_PinNo <=DIO_u8_PORTC_END) )
		{
			/*Get Valid Range for PORTC pins */
			Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORTA_SIZE  + DIO_u8_PORTB_SIZE ) ;
			Local_u8Result = GET_BIT(PINC , Copy_u8_PinNo);
			if(Local_u8Result == 1)
			{
				Local_u8Result = DIO_u8_HIGH ;
			}
			else
			{
				Local_u8Result = DIO_u8_LOW ;
			}
		}

		if( (Copy_u8_PinNo >=DIO_u8_PORTD_START) && (Copy_u8_PinNo <=DIO_u8_PORTD_END) )
		{
			/*Get Valid Range for PORTD pins */
			Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE) ;
			Local_u8Result = GET_BIT(PIND , Copy_u8_PinNo);
			if(Local_u8Result == 1)
			{
				Local_u8Result = DIO_u8_HIGH ;
			}
			else
			{
				Local_u8Result = DIO_u8_LOW ;
			}
		}

		return Local_u8Result ;


}

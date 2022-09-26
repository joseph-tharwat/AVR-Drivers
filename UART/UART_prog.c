/****************************************************/
/* Title       : UART program file 		            */
/* Author      : Joseph Tharwat                 	*/
/* Release     : 1.0                            	*/
/* Last Update : 12-9-2022                       	*/
/****************************************************/
#include "../DIO/BIT_MATH.h"
#include "../DIO/STD_Types.h"
#include "UART_priv.h"


void (*UART_SetCallBackFunc_RxComplete)(void);

void __vector_13(void) __attribute__((signal,used));

void __vector_13(void)
{
	UART_SetCallBackFunc_RxComplete();
}

void UART_SetCallBack_RxComplete( void (*func_address)(void) )
{
	UART_SetCallBackFunc_RxComplete = func_address;
}
///////////
void (*UART_SetCallBackFunc_DataRegisterEmpty)(void);

void __vector_14(void) __attribute__((signal,used));

void __vector_14(void)
{
	UART_SetCallBack_DataRegisterEmpty();
}

void UART_SetCallBack_DataRegisterEmpty( void (*func_address)(void) )
{
	UART_SetCallBackFunc_DataRegisterEmpty = func_address;
}
/////////////
void (*UART_SetCallBackFunc_TxComplete)(void);

void __vector_15(void) __attribute__((signal,used));

void __vector_15(void)
{
	UART_SetCallBack_TxComplete();
}

void UART_SetCallBack_TxComplete( void (*func_address)(void) )
{
	UART_SetCallBackFunc_TxComplete = func_address;
}
////////


void UART_vid_SendData(u8 u8_Data)
{
	while(0 == GET_BIT(UCSRA, UCSRA_UDRE_BIT));

	UDR = u8_Data;
}

u8 UART_vid_ResiveData()
{
	while(0 == GET_BIT(UCSRA, UCSRA_RXC_BIT));

	return UDR;
}

u8 UART_u8_IsReadyToRecive()
{
	return GET_BIT(UCSRA,UCSRA_UDRE_BIT);
}

void UART_vid_SetResiveInterruptEnable()
{
	SET_BIT(UCSRB,UCSRB_RXCIE_BIT);
}

void UART_vid_SetReciveInterruptDisable()
{
	CLEAR_BIT(UCSRB,UCSRB_RXCIE_BIT);
}

void UART_vid_SetTransimitInterruptEnable()
{
	SET_BIT(UCSRB,UCSRB_TXCIE_BIT);
}

void UART_vid_SetTransimitInterruptDisable()
{
	CLEAR_BIT(UCSRB,UCSRB_TXCIE_BIT);
}

void UART_vid_SetEmptyInterruptEnable()
{
	SET_BIT(UCSRB,UCSRB_UDRIE_BIT);
}

void UART_vid_SetEmptyInterruptDisable()
{
	CLEAR_BIT(UCSRB,UCSRB_UDRIE_BIT);
}

void UART_vid_SetResiveEnable()
{
	SET_BIT(UCSRB,UCSRB_RXEN_BIT);
}

void UART_vid_SetResiveDisable()
{
	CLEAR_BIT(UCSRB,UCSRB_RXEN_BIT);
}

void UART_vid_SetTransimitEnable()
{
	SET_BIT(UCSRB,UCSRB_TXEN_BIT);
}

void UART_vid_SetTransimitDisable()
{
	CLEAR_BIT(UCSRB,UCSRB_TXEN_BIT);
}

void UART_vid_SetCharacterSize(u8 u8_UartCharacterSize)
{
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register

	if(u8_UartCharacterSize == UART_Data_5_Bit)
	{
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	}
	else if(u8_UartCharacterSize == UART_Data_6_Bit)
	{
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	}
	else if(u8_UartCharacterSize == UART_Data_7_Bit)
	{
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	}
	else if(u8_UartCharacterSize == UART_Data_8_Bit)
	{
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	}
	else if(u8_UartCharacterSize == UART_Data_9_Bit)
	{
		SET_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	}

}

void UART_vid_ModeSelect(u8 UART_u8_Mode)
{
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register

	if(UART_u8_Mode == UART_Asynchronous)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UMSEL_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCPOL_BIT);
	}
	else if(UART_u8_Mode == UART_Synchronous)
	{
		SET_BIT(UCSRC_UBRRH,UCSRC_UMSEL_BIT);
	}
}

void UART_vid_SyncClockPolarity(u8 u8_ClockPolarity)
{
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register

	if(u8_ClockPolarity == UART_ClockPolarity_FR)
		SET_BIT(UCSRC_UBRRH,UCSRC_UCPOL_BIT);
	else if(u8_ClockPolarity == UART_ClockPolarity_RF)
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCPOL_BIT);
}

void UART_vid_ParityModeSelect(u8 UART_u8_ParityMode)
{
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register

	if(UART_u8_ParityMode == UART_PriatyModeDisabled)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UPM0_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UPM1_BIT);
	}
	else if(UART_u8_ParityMode == UART_PriatyModeEven)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UPM0_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UPM1_BIT);
	}
	else if(UART_u8_ParityMode == UART_PriatyModeOdd)
	{
		SET_BIT(UCSRC_UBRRH,UCSRC_UPM0_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UPM1_BIT);
	}
}

void UART_vid_StopBitSelect(u8 UART_u8_StopBitNumber)
{

	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register

	if(UART_u8_StopBitNumber == UART_1_stopBit)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_USBS_BIT);
	}
	else if(UART_u8_StopBitNumber == UART_2_stopBit)
	{
		SET_BIT(UCSRC_UBRRH,UCSRC_USBS_BIT);
	}
}

void UART_vid_SetBaudRate(u16 u16_BuadeRateValue)
{
	//CLEAR_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UBRRH register	(Confeused!!)
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UBRRH register

	UBRRL = (u8)(u16_BuadeRateValue & 0xFF);				//8 least significant bits
	UCSRC_UBRRH = (u8)((u16_BuadeRateValue>>8) & 0x0F);			//4 most significant bits
}


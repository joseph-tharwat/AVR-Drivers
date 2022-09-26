/****************************************************/
/* Title       : UART Interface file                */
/* Author      : Joseph Tharwat                 	*/
/* Release     : 1.0                            	*/
/* Last Update : 12-9-2022                       	*/
/****************************************************/
#ifndef UART_INT
#define	UART_INT

#include "../DIO/STD_Types.h"


void UART_vid_SendData(u8 u8_Data);
u8 UART_vid_ResiveData();

void UART_SetCallBack_RxComplete( void (*func_address)(void) );
void UART_vid_SetResiveInterruptEnable();
void UART_vid_SetResiveInterruptDisable();

void UART_SetCallBack_TxComplete( void (*func_address)(void) );
void UART_vid_SetTransimitInterruptEnable();
void UART_vid_SetTransimitInterruptDisable();

void UART_SetCallBack_DataRegisterEmpty( void (*func_address)(void) );
void UART_vid_SetEmptyInterruptDisable();
void UART_vid_SetEmptyInterruptEnable();

void UART_vid_SetResiveEnable();
void UART_vid_SetResiveDisable();

void UART_vid_SetTransimitEnable();
void UART_vid_SetTransimitDisable();

void UART_vid_ModeSelect(u8 UART_u8_Mode);
void UART_vid_SyncClockPolarity(u8 u8_ClockPolarity);
void UART_vid_SetCharacterSize(u8 u8_UartCharacterSize);
void UART_vid_ParityModeSelect(u8 UART_u8_ParityMode);
void UART_vid_StopBitSelect(u8 UART_u8_StopBitNumber);
void UART_vid_SetBaudRate(u16 u8_BuadeRateValue);
#endif	


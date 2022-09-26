/****************************************************/
/* Title       : UART private file		            */
/* Author      : Joseph Tharwat                 	*/
/* Release     : 1.0                            	*/
/* Last Update : 12-9-2022                       	*/
/****************************************************/

#ifndef UART_PRIV
#define	UART_PRIV

#define UDR  	*((volatile u8*)(0x2C))

#define UCSRA  	*((volatile u8*)(0x2B))
#define UCSRA_RXC_BIT	7
#define UCSRA_TXC_BIT	6
#define UCSRA_UDRE_BIT	5
#define UCSRA_FE_BIT	4
#define UCSRA_DOR_BIT	3
#define UCSRA_PE_BIT	2
#define UCSRA_U2X_BIT	1
#define UCSRA_MPCM_BIT	0

#define UCSRB  				*((volatile u8*)(0x2A))
#define UCSRB_RXCIE_BIT		7
#define UCSRB_TXCIE_BIT		6
#define UCSRB_UDRIE_BIT		5
#define UCSRB_RXEN_BIT		4
#define UCSRB_TXEN_BIT		3
#define UCSRB_UCSZ2_BIT		2
#define UCSRB_RXB8_BIT		1
#define UCSRB_TXB8_BIT		0

#define UCSRC_UBRRH  		*((volatile u8*)(0x40))
#define UCSRC_URSEL_BIT		7		//1 to use as UCSRC and 0 to use as UBRRH
#define UCSRC_UMSEL_BIT		6
#define UCSRC_UPM1_BIT		5
#define UCSRC_UPM0_BIT		4
#define UCSRC_USBS_BIT		3
#define UCSRC_UCSZ1_BIT		2
#define UCSRC_UCSZ0_BIT		1
#define UCSRC_UCPOL_BIT		0

#define UBRRL  	*((volatile u8*)(0x29))


#define UART_Data_5_Bit				5
#define UART_Data_6_Bit				6
#define UART_Data_7_Bit				7
#define UART_Data_8_Bit				8
#define UART_Data_9_Bit				9

#define UART_Asynchronous			10
#define UART_Synchronous			11

#define UART_PriatyModeDisabled		12
#define UART_PriatyModeEven			13
#define UART_PriatyModeOdd			14

#define UART_1_stopBit				1
#define UART_2_stopBit				2

#define UART_ClockPolarity_RF		15
#define UART_ClockPolarity_FR		16

#endif



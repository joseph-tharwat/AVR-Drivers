
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef UART_PRIV
#define	UART_PRIV

//data Register
#define UDR     (*((volatile u8 *)0x2C))

//USART Control and Status Register A
#define UCSRA   (*((volatile u8 *)0x2B))  
#define RXC 7   //USART Receive Complete(flag)
#define TXC 6   //USART Transmit Complete(flag)
#define UDRE 5  //USART Data Register Empty(flag)

//USART Control and Status Register B
#define UCSRB   (*((volatile u8 *)0x2A))
#define RXCIE 7 //RX Complete Interrupt Enable
#define TXCIE 6 //TX Complete Interrupt Enable
#define UDRIE 5 //USART Data Register Empty Interrupt Enable
#define RXEN  4 // Receiver Enable
#define TXEN  3 // Transmitter Enable
#define UCSZ2 2 //Character Size (combined with the UCSZ1:0 bit in UCSRC to select the size)
#define RXB8  1 // Receive Data Bit 8(RXB8 is the ninth data bit in received)
#define TXB8  0 //Transmit Data Bit 8(TXB8 is the ninth data bit in transmitted)

//USART Control and Status Register C
#define UCSRC   (*((volatile u8 *)0x40))
#define URSEL 7 //Register Select between UCSRC or the UBRRH (0 to write in UBRRH and 1 to write in UCSRC)
#define UMSEL 6 //USART Mode Select between Asynchronous and Synchronous
    #define Asynchronous_Operation  0
    #define Synchronous_Operation   1
#define UPM0 4  //Parity Mode 
#define UPM1 5  //Parity Mode
    /*
     00 > Disabled
     10 > Enabled, Even Parity
     11 > Enabled, Odd Parity
     */
    #define Disabled_Parity_Mode    10
    #define Even_Parity_Mode        11
    #define Odd_Parity_Mode         12
#define UCSZ0 1 //Character Size (combined with the UCSZ2 bit in UCSRB to select the size)
#define UCSZ1 2 //Character Size (combined with the UCSZ2 bit in UCSRB to select the size)
#define UCPOL 0 //Clock Polarity (falling or rising)

//USART Baud Rate Registers UBRRL
#define UBRRL    (*((volatile u8 *)0x29))   //8 least significant bits of theUSART baud rate 

#endif



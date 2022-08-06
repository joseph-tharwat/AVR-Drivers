
/* 
 * File:   
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef SPI_PRIV_H
#define	SPI_PRIV_H

//SPI Control Register
#define SPCR   (*((volatile u8 *)0x2D))
#define SPIE 7  //SPI Interrupt Enable
#define SPE  6  //SPI Enable
#define DORD 5  //Data Order (1 to LSB and 0 to MSB)
#define MSTR 4  //Master/Slave Select (1 to Master and 0 to Slave)
#define CPOL 3  //Clock Polarity (0 to rising and 1 to falling)
#define CPHA 2  //Clock Phase
#define SPR1 1  //SPI Clock Rate Select 
#define SPR0 0  //SPI Clock Rate Select

//SPI Status Register
#define SPSR   (*((volatile u8 *)0x2E))
#define SPIF  7  //SPI Interrupt Flag
#define SPI2X 0  //Double SPI Speed Bit and used with SPR1 and SPR0 to select clock rate


//SPI Data Register
#define SPDR  (*((volatile u8 *)0x2F))



#endif	


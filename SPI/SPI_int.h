
/* 
 * File:   
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */

#ifndef SPI_INT_H
#define	SPI_INT_H

void SPI_vid_Enable(void);
void SPI_vid_Init(void);
void SPI_vid_Send(u8 data);
u8 SPI_u8_Receive(void);

#endif


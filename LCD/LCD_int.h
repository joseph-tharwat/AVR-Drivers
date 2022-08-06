/* 
 * File:   LCD Interface
 * Author: Joseph Tharwat
 * Comments:
 * Revision history: 
 */


#ifndef LCD_INT_H
#define	LCD_INT_H


void LCD_vid_init();
void LCD_vid_WrithCMD(u8 u8_cmd);
void LCD_vid_WrithChar(u8 u8_char);
void LCD_vid_WrithString(u8* string);


#endif 



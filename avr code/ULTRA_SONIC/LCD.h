/*
 * LCD.h
 * Created: 7/12/2017 10:00:00 PM
 *  Author: HUSSIEN
 */ 
#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL 
#include <util/delay.h>
#include <avr/io.h>


#define LCD_CMD_PORT PORTD
#define LCD_CMD_DIR DDRD
#define LCD_CMD_PIN PIND


#define LCD_DATA_PORT PORTC
#define LCD_DATA_DIR DDRC
#define LCD_DATA_PIN PINC


#define RS 0
#define RW 1
#define E 2

#define CLEAR 1
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define TURN_OFF_CURSOR 0x0C
#define TURN_ON_CURSOR 0x0E

#define SET_CURSOR_SECOND_LINE 0x80
#define SET_CURSOR_FIRST_LINE 0xC0

#define SHIFT_CURSOR_LEFT 0x10 
#define SHIFT_CURSOR_RIGHT 0x14 
void PULSE(void);
void LCD_ClearScreen();
void SEND_COOMAND( uint8_t  CMD);
void LCD_START(void);
void DISP_CHAR(unsigned char c);
void DISP_WORD( char *word);
void LCD_GoTo_XY( uint8_t row, uint8_t col);




 #endif /* LCD_H_ */
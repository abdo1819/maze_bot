/*
 * LCD.c
 * Created: 7/12/2017 10:00:00 PM
 *  Author: HUSSIEN
 */ 
#include "LCD.h"
#include <stdlib.h>
void PULSE()
{
	//send pulse to process commands
	LCD_CMD_PORT|=(1<<E);
	_delay_ms(2);//wait for processing data
	LCD_CMD_PORT&=~(1<<E);
	_delay_ms(2);
	
}

void SEND_COOMAND(uint8_t CMD)
{
	//put command on data pins
	LCD_DATA_PORT=CMD;
	//accept commands
	LCD_CMD_PORT&=~(1<<RS);//write to lcd
	LCD_CMD_PORT&=~(1<<RW);//write instructions
	PULSE();
}
void LCD_START()
{
	LCD_CMD_DIR|= (1<<E) | (1<<RS) | (1<<RW); ;//sets all pins to be output 
	LCD_CMD_PORT=0;//set all to zero
	LCD_DATA_DIR=0xFF;;
	LCD_DATA_PORT=0;
	//STARTING
	_delay_ms(10);
	//8bits and 5*7 dots mode
	SEND_COOMAND(TWO_LINE_LCD_Eight_BIT_MODE);
	//Turn on cursor
	SEND_COOMAND(TURN_ON_CURSOR);
	_delay_ms(500);
	//Turn off cursor
	SEND_COOMAND(TURN_OFF_CURSOR);
	//clear screen
	LCD_ClearScreen();	
}

void LCD_ClearScreen()
{
	SEND_COOMAND(CLEAR);
}
void DISP_CHAR( unsigned char c)
{
	//put CHAR DATA on data pins
	LCD_DATA_PORT=c;
	_delay_us(100);
	LCD_CMD_PORT&=~(1<<RW);//write data
	LCD_CMD_PORT|=(1<<RS);//write to lcd
	
	_delay_us(100);
	PULSE();
}
void DISP_WORD( char *word)
{
	for ( uint16_t i=0;word[i]!=0;i++)
	{
		DISP_CHAR(word[i]);
	}
}
void DISP_INT( uint16_t NUM)
{
	char buff[16];
	itoa(NUM,buff,10);
	DISP_WORD(buff);
}
void LCD_GoTo_XY(uint8_t row,uint8_t col)
{
	uint8_t ADRESS=col;
	if (row==0)
	{
		ADRESS=col;
	}
	else if(row==1)
	{
		ADRESS=col+0x40;
	}
	SEND_COOMAND(ADRESS | 0x80);
}




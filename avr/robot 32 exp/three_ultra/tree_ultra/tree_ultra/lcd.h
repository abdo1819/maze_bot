#ifndef _lcd_h
#define _lcd_h 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <math.h>

/*lcd library use portd for data and rs,rw,e in potrc0,1,2 */
//add struct for port and rs,rw,e


void init(void);
void cmd(int);
void data(char);
void display(const char*);
void display_int(int);
int reverse(int);

#endif
//	init();
//	display_int(123);

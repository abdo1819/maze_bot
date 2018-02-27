#include "lcd.h"

void init(){
	DDRC=0xff;
	DDRD=0xff;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x0e);
	cmd(0x06);

}


void cmd(int a)
{
	PORTB=a;
	PORTC=0x00;
	PORTC=0x04;
	_delay_ms(200);  //check if busy or not
	PORTC=0x00;
	
}
void data(char s)
{
	PORTB=s;
	PORTC=0x01;
	PORTC=0x05;
	_delay_ms(200);  //check if busy or not
	PORTC=0x01;
}
void display(const char*p)
{
	while (*p!='\0')
	{
		data(*p);
		p++;
	}
}

void display_int(int value){
	int put_zero = 0;
	if ((value%10)==0){
		put_zero = 1;
	}
	
	value = reverse(value);
	
	int i ,size  = log10(value)+1;
	for (i=0;i<size;i++){
		data(value%10+48);
		value = value/10;
	}
	if(put_zero){
		data(48);
	}
}
int reverse(int x){
	int i , reversed = 0, size = log10(x)+1;
	for (i = 0; i<size ;i++){
		reversed += x%10;
		if (i==size-1){
			break;
		}
		reversed *= 10;
		x /= 10;
	}
	return reversed ;
}
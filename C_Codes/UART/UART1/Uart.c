
#include <reg51.h>
#include "Uart.h"

void Uart_Init(unsigned int Value)
{
	char i;
	if( Value == 9600) i = -3;
	if( Value == 4800) i = -6;
	if( Value == 2400) i = -12;
	if (Value == 19200)
	{
		PCON = 0x80;
		i = -3;
	}
	TMOD = 0X20;
	TH1 = i;
	SCON = 0X50;
	TR1 = 1;
}
void Uart_Tx(unsigned char Value)
{
	SBUF = Value;
	while(TI == 0);
	TI = 0;
}
unsigned char Uart_Rx()
{
	while(RI == 0);
	RI = 0;
	return SBUF;
}
void Uart_Tx_Str( unsigned char *Str)
{
	while(*Str)
	{
	Uart_Tx(*Str);
		Str++;
	}
}

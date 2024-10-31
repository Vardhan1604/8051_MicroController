#include <reg51.h>

sbit LED=P2^0;
unsigned char i,j;

void Delay(unsigned char num)
{
	for(i = 0; i < num; i++)
	{
		TMOD = 0x01;
		TL0 = 0xEE;
		TH0 = 0xFC;
		TR0 = 1;
		while(TF0 == 0);
		TF0 = 0;
		TR0 = 0;
	}
}

void main()
{
	for(j = 0; j < 100; j++)
	{
		LED=~LED;
		Delay(j);
	}
}
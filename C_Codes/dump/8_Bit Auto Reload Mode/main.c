#include <reg51.h>

sbit Pluse = P2^0;

void main()
{
	TMOD = 0x02;
  TH0 = 0x00;
	TR0 = 1;
   while(1)
	{	
		Pluse =~Pluse;
		while(TF0 == 0);
		TF0 = 0;	
	}
} 
#include <reg51.h>

sbit PWM = P2^0;

 unsigned char i,j,k;
	
void Long_Delay(unsigned char num)
{
for(k = 0; k<num; k++)
	{
TMOD = 0x01;
TL0 = 0x40;
TH0 = 0x4C;
TR0 = 1;
while(TF0 == 0);
TF0 = 0;
TR0 = 0;
	}	
}

void Short_Delay()
{

TMOD = 0x01;
TL0 = 0x00;
TH0 = 0xA6;
TR0 = 1;
while(TF0 == 0); 
TF0 = 0;
TR0 = 0;
}

void main()
{
	

	for(i = 0; i<10; i++)
	{
		PWM= ~PWM;
		Long_Delay(1);
	}
	PWM = 0;
	Long_Delay(4);
	for(j = 0; j<20; j++)
	{
				PWM= ~PWM;
		Short_Delay();
	}
	PWM = 1;
	
	while(1);
}
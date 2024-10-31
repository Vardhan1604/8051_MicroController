#include <reg51.h>

sbit out =P2^0;
sbit out1 =P1^0;


#include <reg51.h>

/*void H_Delay_ms(unsigned int num) 
{
	while( num--)
	{
    TMOD = 0x10; 
    TH1 = 0xFC;   
    TL1 = 0x66;   
    TR1 = 1; 
    while(TF1 == 0);
    TR1 = 0; 
	  TF1 = 0;
	}
   	
}
*/
void H_Delay_us(unsigned int num) 
{
	while(num--)
	{
    TMOD = 0x01; 
    TH0 = 0xFC;   
    TL0 = 0x66 + num;   
    TR0 = 1; 
    while(TF0 == 0);
    TR0 = 0; 
	  TF0 = 0;	
	}
}
void main()

{
	while(1)
	{
	out1 = 0;
	H_Delay_us(1000);
	out1 = 1;
	H_Delay_us(1000);
	}
}
#include <reg51.h>
void delay()
{
	unsigned int i,j;
	for(i =0; i<500; i ++)
	{
		for(j =0; j<113; j++);
	}
}
void main()
{
	P0 = 0x00;
    TMOD = 0x20;  
    TH1 = 0xFD;   
    SCON = 0x50;  
    TR1 = 1;      

    while(1)
    {

        while(RI == 0);
        RI = 0; 
        P0 = SBUF;
			 delay();
    }
}



#include <reg51.h>
#include "LCD.h"
#include "Delay.h"
sbit sw1=P3^5;

void main()
{
	int i,j;
	
	char a[8]={0x0E, 0x1B, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00};
	char b[8]={0x0E, 0x1B, 0x11, 0x11, 0x1f, 0x1f, 0x1F, 0x00};
	char c[8]={0x0E, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1F, 0x00};

	
	LCD_init();
	
	for(i = 0; i < 8; i++)
	{
		LCD_cmd(0x40 + i);
		LCD_data(a[i]);
		LCD_cmd(0x48 + i);
		LCD_data(b[i]);
		LCD_cmd(0x50 + i);
		LCD_data(c[i]);
		
	}
	while(1)
	{
		if(sw1 == 0)
		{
			Delay(25);
			if(sw1 == 1)
			{
			j++;
				if(j == 3)
				{
					j=0;
				}
			}
		}
		LCD_cmd(0x82);
		LCD_data(j);
	}
}
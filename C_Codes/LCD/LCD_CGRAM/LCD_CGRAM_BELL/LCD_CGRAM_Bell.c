

#include <reg51.h>
#include "LCD.h"
#include "Delay.h"

void main()
{
	int i;
	
	char a[7]={0x04,0x0e,0x1f,0x1f,0x1f,0x00,0x04};
	
	LCD_init();
	
	for(i = 0; i < 7; i++)
	{
		LCD_cmd(0x40 + i);
		LCD_data(a[i]);
		
	}
	while(1)
	{
		LCD_cmd(0x80);
		LCD_data(0);
	}
	
}

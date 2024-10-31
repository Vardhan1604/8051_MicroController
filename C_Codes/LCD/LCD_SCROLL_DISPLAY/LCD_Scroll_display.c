

#include <reg51.h>
#include "LCD.h"
#include "Delay.h"


void main()
{
	int i;
	
	char a[]="vijayawada is a wonderful city. because of its geological location  ";
	int len=sizeof(a)-1;
	
	
	
	LCD_init();
	
	
	
	
	while(1)
	{
		for(i = 0; i < len ; i++)
		{
			
		  LCD_cmd(0x80);
			LCD_print(&a[i]);
			Delay(100);
		}
	}
	
}





#include <reg51.h>
#include "LCD.h"
#include "Delay.h"
#include "CGRAM_SP.h"

void main()
{
	int i;
	
	LCD_init();
	while(1)
	{
for(i=0; i<8 ; i++)
	{
		
	LCD_CGRAM(i , 0x80 + i*2);
		
	}
}
}

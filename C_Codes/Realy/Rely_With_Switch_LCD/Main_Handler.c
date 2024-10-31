#include "LCD.h"
#include "Delay.h"
#include <reg51.h>
#include "Relay.h"



void main()
{
	Relay1 = 0;
	Relay2 = 0;
	LCD_Init();
	LCD_Print("Press To Start");
	while(1)
	{
	Relay1_Call(Switch1);
	Relay2_Call(Switch2);
		
	}
}
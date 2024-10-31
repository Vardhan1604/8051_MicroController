
#include "Relay.h"
#include "Delay.h"
#include "LCD.h"



void Relay1_Call(unsigned char num)
{
  if(num == 0)
	{
		Delay(400);
		if(num == 0)
		{ 
			Relay1 = ~Relay1;

			if( Relay1 ==1)
			{
				LCD_Cmd_Write(0x01);
				LCD_Cmd_Write(0x80);
				LCD_Print("Relay1 Turned ON");
			}
			else
			{
				LCD_Cmd_Write(0x01);
				LCD_Cmd_Write(0x80);
				LCD_Print("Relay1 Turn OFF");
			}
		}

}
}

void Relay2_Call(unsigned char num)
{
  if(num == 0)
	{
		Delay(400);
		if(num == 0)
		{ 
			Relay2 = ~Relay2;

			if( Relay2 ==1)
			{
				LCD_Cmd_Write(0x01);
				LCD_Cmd_Write(0x80);
				LCD_Print("Relay2 Turned ON");
			}
			else
			{
				LCD_Cmd_Write(0x01);
				LCD_Cmd_Write(0x80);
				LCD_Print("Relay2 Turn OFF");
			}
		}

}
}

#include <reg51.h>
#include "LCD.h"
#include "Delay.h"

sbit rs=P0^6;
sbit en=P0^7;
sfr LCD =0x90;

 void LCD_Cmd(unsigned char cmd)
 {
	 void LCD_busy();
	 LCD = cmd;
	 rs=0;
	 en=1;
	 Delay(1);
	 en=0;
 }

 void LCD_Data(unsigned char data1)
 {
	 void LCD_busy();
	 LCD = data1;
	 rs=1;
	 en=1;
	 Delay(1);
	 en=0;
 }

 void LCD_Init()
 {
	 int i;
	 unsigned char a[5]={0x01,0x0c,0x06,0x38,0x80};
	 for(i = 0; i < 5; i++)
	 {
		 LCD_Cmd(a[i]);
		 Delay(10);
	 }
	 
 }
 
  void Sprint(unsigned char *str)
	{
		while(*str != '\0')
		{
			LCD_Data(*str);
			str++;
		}
	}
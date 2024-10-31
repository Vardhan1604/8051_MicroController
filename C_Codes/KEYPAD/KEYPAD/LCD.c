

#include "LCD.h"
#include "Delay.h"


void LCD_Busy()
{
	RS=0;
	RW=1;
	while(Busy == 1)
	{
	EN = 1;
		Delay(1);
		EN = 0;
	}
}
 void LCD_Cmd_Write(unsigned char cmd)
 {
	 void LCD_Busy();
	 LCD = cmd;
	 RS=0;
	 RW=0;
	 EN=1;
	 Delay(1);
	 EN=0;
 }

 void LCD_Data_Write(unsigned char data1)
 {
	 void LCD_Busy();
	 LCD = data1;
	 RS=1;
	 RW=0;
	 EN=1;
	 Delay(1);
	 EN=0;
 }

 void LCD_INIT()
 {
	 int i;
	 
	 unsigned char a[5]={0x01,0x0c,0x06,0x38,0x80};
	 
	 for(i = 0; i < 5; i++)
	 {
		 LCD_Cmd_Write(a[i]);
		 Delay(10);
	 }
	 
 }
  void LCD_Print(const char *str)
	{
		while(*str)
			LCD_Data_Write(*str++);
	}
	
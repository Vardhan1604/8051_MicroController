

#include "LCD.h"
#include "Delay.h"


void LCD_busy()
{
	rs=0;
	rw=1;
	while(busy == 0);
	
}
 void LCD_cmd(unsigned char cmd)
 {
	 void LCD_busy();
	 LCD = cmd;
	 rs=0;
	 rw=0;
	 en=1;
	 Delay(1);
	 en=0;
 }

 void LCD_data(unsigned char data1)
 {
	 void LCD_busy();
	 LCD = data1;
	 rs=1;
	 rw=0;
	 en=1;
	 Delay(1);
	 en=0;
 }

 void LCD_init()
 {
	 int i;
	 unsigned char a[5]={0x01,0x0c,0x06,0x38,0x80};
	 
	 for(i = 0; i < 5; i++)
	 {
		 LCD_cmd(a[i]);
		 Delay(10);
	 }
	 
 }
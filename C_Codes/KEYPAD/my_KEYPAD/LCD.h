
#include <reg51.h>
sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^4;
sbit busy=P2^7;
sfr LCD = 0xA0;
 
 void LCD_busy();
 void LCD_cmd(unsigned char);
 void LCD_data(unsigned char);
 void LCD_init(); 
 void LCD_Print(const char*);

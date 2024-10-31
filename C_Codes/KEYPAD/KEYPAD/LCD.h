
#include <reg51.h>
sbit RS=P3^2;
sbit RW=P3^3;
sbit EN=P3^4;
sbit Busy=P2^7;
sfr LCD = 0xA0;
 
 void LCD_Busy();
 void LCD_Cmd_Write(unsigned char);
 void LCD_Data_Write(unsigned char);
 void LCD_INIT(); 
 void LCD_Print(const char*);
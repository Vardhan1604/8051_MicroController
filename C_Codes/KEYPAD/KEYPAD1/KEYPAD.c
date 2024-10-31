

#include <reg51.h>
#include "KEYPAD.h"
#include "Delay.h"
#include "LCD.h"





void main()
{
	char num1[10];
	int i=0;
	while(1)
	{
			
		C2=1;C1=0;C3=1;C2 = 1;
		
		  if(R1 == 0){ Delay(500); LCD_data('7'); num1[i++]='7'; }
		  if(R2 == 0){ Delay(500); LCD_data('8'); num1[i++]='8'; }
			if(R3 == 0){ Delay(500); LCD_data('9'); num1[i++]='9'; }
		  if(R4 == 0){ Delay(500); LCD_data('/'); num1[i++]='/';}	 
			
	 
	 C1=1;C2 = 0;C3=1;C4 = 1;
	
		  if(R1 == 0){ Delay(500); LCD_data('4'); num1[i++]='4'; }
		  if(R2 == 0){ Delay(500); LCD_data('5'); num1[i++]='5'; }
			if(R3 == 0){ Delay(500); LCD_data('6'); num1[i++]='6'; }
		  if(R4 == 0){ Delay(500); LCD_data('*'); num1[i++]='*';}	 
			
	 C2=1;C1=1;C3=0;C4 =1; 
		
		  if(R1 == 0){ Delay(500); LCD_data('1'); num1[i++]='1'; }
		  if(R2 == 0){ Delay(500); LCD_data('2'); num1[i++]='2'; }
			if(R3 == 0){ Delay(500); LCD_data('3'); num1[i++]='3'; }
		  if(R4 == 0){ Delay(500); LCD_data('-'); num1[i++]='-';}	 

	 
	 C1 =1;C2 =1;C3 =1;C4 =0;
		  
		  if(R2 == 0){ Delay(500); LCD_data('0'); num1[i++]='0'; }
			if(R3 == 0){ Delay(500); LCD_data('='); num1[i++]='='; }
		  if(R4 == 0){ Delay(500); LCD_data('+'); num1[i++]='+'; }	 
			if(R1 == 0 ){ Delay(500); LCD_cmd(0x01); }
    C4 = 1;
			
	 }
 }

 
	
	
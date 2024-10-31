

#include "KEYPAD.h"
#include "Delay.h"
#include "LCD.h"

     extern char num1[10];
		 
     int i=0;

void KEYPAD()
{
	  
		C2=1;C1=0;C3=1;C2 = 1;
		
		  if(R1 == 0){ Delay(500);  num1[i++]='7'; }
		  if(R2 == 0){ Delay(500);  num1[i++]='8'; }
			if(R3 == 0){ Delay(500);  num1[i++]='9'; }
		  if(R4 == 0){ Delay(500);  num1[i++]='/'; }	 
			
	 
	 C1=1;C2 = 0;C3=1;C4 = 1;
	
		  if(R1 == 0){ Delay(500); num1[i++]='4'; }
		  if(R2 == 0){ Delay(500); num1[i++]='5'; }
			if(R3 == 0){ Delay(500); num1[i++]='6'; }
		  if(R4 == 0){ Delay(500); num1[i++]='*';}	 
			
	 C2=1;C1=1;C3=0;C4 =1; 
		
		  if(R1 == 0){ Delay(500); num1[i++]='1'; }
		  if(R2 == 0){ Delay(500); num1[i++]='2'; }
			if(R3 == 0){ Delay(500); num1[i++]='3'; }
		  if(R4 == 0){ Delay(500); num1[i++]='-'; }	 

	 
	 C1 =1;C2 =1;C3 =1;C4 =0;
			
		  if(R1 == 0){ 
				Delay(500); 
				i=0;
     		Clear_Array(num1,10);

			}
		  if(R2 == 0){ Delay(500); num1[i++]='0'; }
			if(R3 == 0){ Delay(500); num1[i++]='='; }
		  if(R4 == 0){ Delay(500); num1[i++]='+'; }	 
								
			C4=1;
	}


 
	
	
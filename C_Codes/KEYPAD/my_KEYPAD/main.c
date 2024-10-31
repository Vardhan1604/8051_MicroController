
#include "LCD.h"
#include "KEYPAD.h"
#include "LCD_ITOA.h"
#include "Delay.h"

char num1[10];

int m;

void Clear_Array(char *array, int size) {
    for (m = 0; m < size; m++) {
        array[m] = 0;
    }
		LCD_cmd(0x01);
	}
void main() {
    int j, n1, n2;
    
    char temp1;
	  float temp;
	
    
    LCD_init();
    
	
    while (1) {
		
			  n1 = 0;
        n2 = 0;
        j = 0;
        
        KEYPAD();
        LCD_cmd(0x80);
        LCD_Print(num1);
        
        while (num1[j] >= '0' && num1[j] <= '9') {
            n1 = n1 * 10 + (num1[j] - '0');
            j++;
        }
        
        if (num1[j] == '+' || '-' || '*' || '/') {
					
					   temp1 = num1[j];
            j++;
        } else {
            continue; 
        }
        
        while (num1[j] >= '0' && num1[j] <= '9') {
            n2 = n2 * 10 + (num1[j] - '0');
            j++;
        }
        
        if (num1[j] == '=') 
					{
						 LCD_cmd(0xc0);
						if(temp1 == '+')
							{ 
            temp = n1 + n2; 
							}
					else if(temp1 == '-')
							{ 
            temp = n1 - n2; 
							}
					else if(temp1 == '*')
							{ 
            temp = n1 * n2; 
							}
					else if(temp1 == '/')
							{ 
            temp = n1 / n2; 
							}
          LCD_ADD(temp);
        }	
}       
}
	
 
	
	
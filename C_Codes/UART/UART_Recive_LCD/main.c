#include <reg51.h>
#include <LCD.h>
#include <Delay.h>
sbit sw = P2^0;

void main() {
    TMOD = 0x20;        
    TH1 = 0xFD;          
    SCON = 0x50;
    TR1 = 1;           
    LCD_Init();
	  Sprint("UART IS TO R");
	  Delay(1000);
	  LCD_Cmd(0x01);
    while(1) {
            if(RI == 1)
						{							
                RI = 0;
                LCD_Data(SBUF);		
						}
             if(sw == 0)
							 {
								 Delay(250);
								 SBUF = 'M';
								 while(TI == 0);  
                 TI = 0;
								 
						 }							 
            }
        }

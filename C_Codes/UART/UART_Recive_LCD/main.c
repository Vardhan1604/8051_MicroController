#include <reg51.h>
#include <LCD.h>
#include <Delay.h>
#include <Uart.h>


void main() {
	  
	  Uart_Init(9600);
    LCD_Init();
	  Sprint("UART IS Ready");
	  Delay(1000);
	  LCD_Cmd(0x01);
    while(1) {
            if(RI == 1)
						{							
                LCD_Data(Uart_Rx());		
						}		 
            }
        }

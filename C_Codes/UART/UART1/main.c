//#include <reg51.h>

#include "Uart.h"

void main() {
	
  Uart_Init(); 	        
	Uart_Tx_Str("WELCOME");
	
	while(1);
}
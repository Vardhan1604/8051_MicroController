//#include <reg51.h>

#include "Uart.h"

void main() {
	
  Uart_Init(9600); 	        
	Uart_Tx_Str("Happy Diwali");
	
	while(1);
}
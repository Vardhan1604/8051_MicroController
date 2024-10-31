

#include "Ports.h"
#include "KEYPAD.h"
#include "Delay.h"


unsigned char KeyPad_Lockup_Table[4][4] =  {{'1', '2', '3', 'A'},
																						{'4', '5', '6', 'B'},
																						{'7', '8', '9', 'C'},
																						{'*', '0', '#', 'D'}};
unsigned char Row, Col;
															
															
unsigned char KeyPad_SCAN()
{
	

  
  //  a =  Keypad_Port; 
	
    A = 0x0F;
    A = A &  0x0F;

         if (A == 0x0E) { Delay(10);  Row = 0; }
    else if (A == 0x0D) { Delay(10);  Row = 1; }
    else if (A == 0x0B) { Delay(10);  Row = 2; }
    else if (A == 0x07) { Delay(10);  Row = 3; }
		 else {         return 0x00;               }
		 
    A = 0xF0;	 
    A = A &  0xF0;
		 
         if (A == 0xE0) { Delay(10);  Col = 0; }
    else if (A == 0xD0) { Delay(10);  Col = 1; }
    else if (A == 0xB0) { Delay(10);  Col = 2; }
    else if (A == 0x70) { Delay(10);  Col = 3; }
		 else {         return 0x00;               }
		 
    return KeyPad_Lockup_Table[Row][Col];
}
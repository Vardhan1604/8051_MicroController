

#include "7_Segment_diaply.h"

unsigned char Lookup_Table[16] = {   0x3F,0x06,0x5B,0x4F,
																		 0x66,0x6D,0x7D,0x07,
																		 0x7F,0x6F,0x77,0x7C,
																		 0x39,0x5E,0x79,0x71};

void Seven_Segment1(unsigned char Key)	
{
	
	if(Key >= '0' && Key <= '9')
				 {
					Seven_Segment = Lookup_Table[Key - '0'];
				 }
				 else 
				 {
					 Seven_Segment = Lookup_Table[Key - 'A' + 10];
				 }
	
}	

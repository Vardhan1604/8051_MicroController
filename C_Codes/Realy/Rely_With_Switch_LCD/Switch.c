 
#include "Switch.h"
#include "Delay.h"

bit status =0;

bit Switch_Call()
{
	
     if( SW1 == 0)
	 {
		 Delay(250);
		 if( SW1 == 1){
	   status = !status;
   }
 }
	 return status;
}

#include "Switch.h"

bit status =0;

bit Switch_Call()
{
	
     if( SW1 == 0)
	 {
	   status = !status;
		
      }
	  return status;
}
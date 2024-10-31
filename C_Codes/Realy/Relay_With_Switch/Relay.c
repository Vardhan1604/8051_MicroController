
#include "Relay.h"
#include "Delay.h"

void Relay1_Call(unsigned char num)
{
  if(num == 0)
	{
		Delay(400);
		if(num == 0)
		{ 
			Relay1 = ~Relay1;

		}
  }
}

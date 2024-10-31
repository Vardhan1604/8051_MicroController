
#include "Relay.h"
#include "Delay.h"

void Relay_Call()
{

  Relay1 = 0;
	Delay(250);
  Relay2 = 1;
	Delay(250);
	Relay2 = 0;
	Delay(250);
  Relay1 = 1;
	Delay(250);

}
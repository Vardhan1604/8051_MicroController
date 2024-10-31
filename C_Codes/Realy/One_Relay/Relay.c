
#include "Relay.h"
#include "Delay.h"

void Relay_Call()
{

  Relay = 0;
  Delay(2000);
  Relay = 1;
  Delay(2000);
}
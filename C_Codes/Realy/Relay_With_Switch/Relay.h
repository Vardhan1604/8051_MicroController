
#include <reg51.h>

sbit Relay1 = P1^0;
sbit Switch = P1^1;


void Relay1_Call(unsigned char);
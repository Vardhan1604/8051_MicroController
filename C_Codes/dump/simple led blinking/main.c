
#include <reg51.h>

sbit Led= P2^0;

void main()
{
  while(1)
	{
		Led=~Led;
	}
}
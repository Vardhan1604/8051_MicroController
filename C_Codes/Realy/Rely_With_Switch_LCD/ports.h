#ifndef __PORTS_H_
#define __PORTS_H_

#include <reg51.h>

sbit RS=P3^2;
sbit RW=P3^3;
sbit EN=P3^4;
sbit Busy=P2^7;
sfr LCD = 0xA0;

sbit Relay1  = P1^0;
sbit Relay2  = P1^1;
sbit Switch1 = P1^2;
sbit Switch2 = P1^3;

#endif


#ifndef __PORTS_H__
#define __PORTS_H__

#include <reg51.h>

// LCD Pins
sbit RS=P3^2;
sbit RW=P3^3;
sbit EN=P3^4;
sbit Busy=P2^7;
sfr LCD = 0xA0;

//Matrix_Keypad Pins

sfr A = 0x80;

//7Segment Pins

sfr Seven_Segment = 0x90;


#endif
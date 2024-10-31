

#include <reg51.h>



sbit C1=P1^0;
sbit C2=P1^1; 
sbit C3=P1^2;
sbit C4=P1^3;
sbit R1=P1^4;
sbit R2=P1^5;
sbit R3=P1^6;
sbit R4=P1^7;

void Clear_Array(char*, int);

void KEYPAD();
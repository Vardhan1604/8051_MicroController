
#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "Delay.h"

unsigned char INPUT[16];
unsigned char Key;
unsigned char i;

void Input_Password(unsigned char *INPUT, unsigned char Key)
{

    INPUT[i++] = Key;
    INPUT[i] = '\0';
}

void main()
{
    LCD_INIT();

    while (1)
    {

        Key = KeyPad_SCAN();
        if (Key != 0)
        {
            Input_Password(INPUT, Key);
            LCD_Cmd_Write(0x80);
            LCD_Print(INPUT);
        }
    }
}
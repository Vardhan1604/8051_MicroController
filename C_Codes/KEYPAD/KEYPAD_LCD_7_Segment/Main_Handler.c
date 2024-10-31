
#include "LCD.h"
#include "KEYPAD.h"
#include "Delay.h"
#include "7_Segment_diaply.h"

unsigned char INPUT[16];
unsigned char i;
unsigned int Key;

void Key_Scan(unsigned char *INPUT, unsigned char Key)
{

    INPUT[i++] = Key;
    INPUT[i] = '\0';
    LCD_Cmd_Write(0x80);
    LCD_Print(INPUT);
}

void main()
{
    LCD_INIT();

    while (1)
    {
        Key = KeyPad_SCAN();

        if (Key != 0)
        {
            Key_Scan(INPUT, Key);
            Seven_Segment1(Key);
        }
    }
}
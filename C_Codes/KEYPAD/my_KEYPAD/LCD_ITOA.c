

#include "LCD_ITOA.h"
#include "LCD.h"

void LCD_ADD(signed int num)
{
    int i = 0;

    char temp[10];

    if (num == 0)
    {
        LCD_data('0');
    }
    if (num < 0)
    {
        LCD_data('-');
        num = -num;
    }

    while (num > 0)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }
    for (--i; i >= 0; i--)
    {
        LCD_data(temp[i]);
    }
}
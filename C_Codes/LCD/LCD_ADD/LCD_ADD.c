

#include <reg51.h>
#include "LCD.h"
#include "Delay.h"
#include "LCD_ITOA.h"

sbit sw1 = P3 ^ 5;

void main()
{
    int j;

    char a[4] = {'+', '-', '*', '/'};

    int num1 = 200;
    int num2 = 100;
    int result;

    LCD_init();

    while (1)
    {
        if (sw1 == 0)
        {
            Delay(50);
            j++;
            LCD_cmd(0x01);
            if (j >= 4)
            {
                j = 0;
            }
            while (sw1 == 0)
                ;
        }

        switch (j)
        {
        case 0:
            result = num1 + num2;
            break;
        case 1:
            result = num1 - num2;
            break;
        case 2:
            result = num1 * num2;
            break;
        case 3:
            result = num1 / num2;
            break;
        }

        LCD_cmd(0x80);
        LCD_ADD(num1);
        LCD_data(a[j]);
        LCD_ADD(num2);
        LCD_data('=');
        LCD_ADD(result);
    }
}
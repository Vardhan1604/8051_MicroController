
#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "Delay.h"
#include <string.h>

unsigned char INpass[5];             // INpass is User Enterted Password
unsigned char MASK[5];               // For Masking the Input password
unsigned char Key, i, j, l, m;
unsigned int REMAIN_Attempt = 3;     // attempts to remaning Entering the Password
unsigned char PASSWORD[4] = "D1*B";  // Default Password

// Storing the User Enterted Password in the INpass array
void Scan_Password(unsigned char *INpass, unsigned char *MASK, unsigned char Key)
{
    INpass[i++] = Key;
    INpass[i] = '\0';
    MASK[j++] = '*';
    MASK[j] = '\0';
}

// Checking the Orginal Password and user input password
bit Check_Password()
{

    bit result;

    result = strcmp(PASSWORD, INpass);

    return result;
}

// Verifying The Password That Entered by the User is Correct or Not
unsigned char Verify_Password()
{

    LCD_Cmd_Write(0x80);
    LCD_Print("ENTER THE PASSWORD");

    Key = KeyPad_SCAN();

    if (Key != 0)

    {
        LCD_Cmd_Write(0x80);
        LCD_Print("ENTER THE PASS");
        Scan_Password(INpass, MASK, Key);
        LCD_Cmd_Write(0xC0);
        LCD_Print(MASK);

        if (i == 4)
        {

            if (Check_Password() == 0)
            {
                Delay(100);
                LCD_Cmd_Write(0xC0);
                LCD_Print("PASSWORD MATCHED");

                Delay(200);
                LCD_Cmd_Write(0x01);

                i = 0;
							  j = 0;
                for (l = 0; l < 4; l++)
                {
                    INpass[l] = 0;
                }
                return 1;
            }
            else
            {
                REMAIN_Attempt--;
                LCD_Cmd_Write(0x01);
                LCD_Cmd_Write(0x80);
                LCD_Print("WRONG PASSWORD");

                LCD_Cmd_Write(0xC0);
                LCD_Print("ATTEMPTS_RIM:");

                LCD_Data_Write(REMAIN_Attempt + 48);

                if (REMAIN_Attempt == 0)
                {
                    Delay(250);
                    LCD_Cmd_Write(0x80);
                    LCD_Print("DEVICE IS LOCKED");

                    LCD_Cmd_Write(0xC0);
                    LCD_Print("TRYAGAIN AFT 1MIN");
                    Delay(500);

                    REMAIN_Attempt = 3;

                    LCD_Cmd_Write(0x01);
                }
                Delay(500);
                LCD_Cmd_Write(0x01);
            }
            i = 0;
						j = 0;
            for (l = 0; l < 4; l++)
            {
                INpass[l] = 0;
            }
        }
    }
    return 0;
}
void main()
{

    LCD_Init();

    while (1)
    {
        if (Verify_Password() == 1)
        {
            break;
        }
    }
    while (1)
    {
        LCD_Cmd_Write(0x80);
        LCD_Print("ACCESS GRANTED");
    }
}

#include <reg51.h>
#include <stdio.h>
#include "LCD.h" // Include the LCD header file
#include "ports.h"

#define DHT11_PIN P1 // Define the pin connected to DHT11
sbit DHT11 = DHT11_PIN^0; // Define DHT11 pin

void delay_us(unsigned int us);
void delay_ms(unsigned int ms);
void start_signal(void);
bit response_signal(void);
unsigned char read_byte(void);
bit read_dht11(unsigned char *temp, unsigned char *hum);

void main(void) {
    unsigned char temperature = 0, humidity = 0;
    char buffer[16];

    LCD_Init(); // Initialize the LCD

    while (1) {
        if (read_dht11(&temperature, &humidity)) {
            // Prepare strings to display
            sprintf(buffer, "Temp: %d C", temperature);
            LCD_Print(buffer); // Display temperature
            delay_ms(2000); // Wait 2 seconds to display

            LCD_Cmd_Write(0xC0); // Move to the second line
            sprintf(buffer, "Hum: %d %%", humidity);
            LCD_Print(buffer); // Display humidity
            delay_ms(2000); // Wait 2 seconds to display

            LCD_Cmd_Write(0x01); // Clear display
        }
    }
}

void delay_us(unsigned int us) {
    // This function assumes a 12MHz clock; adjust as necessary
    while (us--) {
        // Each loop iteration takes approximately 1 탎
      ; // Do nothing for one clock cycle
    }
}

void delay_ms(unsigned int ms) {
    while (ms--) {
        delay_us(1000); // 1000 탎 in 1 ms
    }
}

void start_signal(void) {
    DHT11 = 0; // Send low signal
    delay_ms(18); // Delay for 18 ms
    DHT11 = 1; // Release the bus
    delay_us(30); // Wait for the response
}

bit response_signal(void) {
    bit response = 0;
    delay_us(1); // Wait for 1 탎

    if (!DHT11) { // Check for low signal
        delay_us(80); // Wait for 80 탎
        if (DHT11) { // Check for high signal
            response = 1; // Response received
        }
    }
    delay_us(80); // Wait for 80 탎
    return response;
}

unsigned char read_byte(void) {
    unsigned char i, byte = 0;

    for (i = 0; i < 8; i++) {
        while (!DHT11); // Wait for the pin to go high
        delay_us(30); // Wait for 30 탎
        if (DHT11) {
            byte |= (1 << (7 - i)); // Read the bit
        }
        while (DHT11); // Wait for the pin to go low
    }
    return byte; // Return the byte read
}

bit read_dht11(unsigned char *temp, unsigned char *hum) {
    start_signal(); // Start the communication
    if (response_signal()) { // Check for response
        *hum = read_byte(); // Read humidity
        *temp = read_byte(); // Read temperature
        read_byte(); // Read checksum (discard)
        return 1; // Successful read
    }
    return 0; // Read failed
}

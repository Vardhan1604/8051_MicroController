#include "DHT11.h"

// Function Prototypes
void delay(unsigned int time);
bit read_dht11(unsigned char *temp, unsigned char *hum);
void start_signal(void);
bit response_signal(void);
unsigned char read_byte(void);

void main(void) {
    unsigned char temperature = 0, humidity = 0;

    while (1) {
        if (read_dht11(&temperature, &humidity)) {
            // Successful read
            // You can now use temperature and humidity values
            // For example, send them via UART, display them, etc.
        }
        delay(10000); // Delay for 10 seconds before next read
    }
}

void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++); // Approx. delay
    }
}

void start_signal(void) {
    DHT11 = 0; // Send low signal
    delay(18); // Delay for 18 ms
    DHT11 = 1; // Release the bus
    delay(30); // Wait for the response
}

bit response_signal(void) {
    bit response = 0;
    delay(1); // Wait for 1 ms

    if (!DHT11) { // Check for low signal
        delay(1); // Wait for 80 us
        if (DHT11) { // Check for high signal
            response = 1; // Response received
        }
    }
    delay(1); // Wait for 80 us
    return response;
}

unsigned char read_byte(void) {
    unsigned char i, byte = 0;

    for (i = 0; i < 8; i++) {
        while (!DHT11); // Wait for the pin to go high
        delay(2); // Wait for 2 ms
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

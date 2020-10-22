#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "serial.h"

#define BAUD    38400
//#define F_CPU   16000000
#define UBBR    ((F_CPU / 16 / BAUD) - 1)

void uart_init(void){

    // Load baudrate to register
    UBRR0H = (UBBR >> 8);
    UBRR0L = UBBR;

    // Enable transmitter and reciever
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Set frame format: 8 data 1 stop bit (8N1)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char chr){
    // Wait fot empty transmit buffer
	while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = chr;

    // If char contains \r add \n
    if(chr == '\r'){
        uart_putchar('\n');
    }
}

void uart_putstr(const char *str){
    // Lopp through the char array and put each char to uart_putchar function to print out
    for (int i = 0; str[i] != '\0'; i++){
        uart_putchar(str[i]);
        //_delay_ms(100);
    }
}

char uart_getchar(void) {
    // Wait for incoming data    
    while (!(UCSR0A & (1 << RXC0)));

    // Return the data
    return UDR0;
}

void uart_echo(void){
    // Assign recived character to c then pass it to uart_putchar() to print out
    //char c = uart_getchar();
    uart_putchar(uart_getchar());
}
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "serial.h"

#define BAUD 38400

#define FOSC 1843000 

#define UBBR (F_CPU / 16 / BAUD - 1)


void uart_init(void){
    UBRR0H = (unsigned char) (UBBR >> 8);
    UBRR0L = (unsigned char) UBBR;

    // Enable reciever and transmitter
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);

    // Set frame format: 8data, 2stop bit
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);

    
}

void uart_putchar(char chr){
	while(!(UCSR0A & (1 << UDR0E)));
	UDR0 = chr;
}

char usart_getchar(void) {
    // Wait for incoming data
    while ( !(UCSR0A & ( 1 << RXEN0 )) );
    // Return the data
    return UDR0;
}
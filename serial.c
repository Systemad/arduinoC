#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "serial.h"

#define BAUD    38400
#define F_CPU   16000000 //1843000 
#define UBBR    ((F_CPU / 16 / BAUD) - 2)

void uart_init(void){
    UBRR0H = (UBBR >> 8);
    UBRR0L = UBBR;

    // Enable transmitter
    UCSR0B = (1 << TXEN0);

    // Set frame format: 8data, 2stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char chr){
	while(! (UCSR0A & (1 << UDRE0)));
    
    while(1){
        UDR0 = chr;
        _delay_ms(1000);
    }
}


/*
char usart_getchar(void) {
    // Wait for incoming data
    while ( !(UCSR0A & ( 1 << RXEN0 )) );
    // Return the data
    return UDR0;
}
*/
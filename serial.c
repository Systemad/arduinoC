#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
/*
#define FOSC 1843200
#define BAUD 9600UL

#define UBRR_VAL (F_CPU / 16 / BAUD - 1)


void uart_init(void){
    UBRR0H = (unsigned char) (UBRR_VAL >> 8);
    UBRR0L = (unsigned char) (UBRR_VAL & 0xff);

    // Enable reciever 
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);

    // Set frame format: 8data, 2stop bit
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);

}
*/
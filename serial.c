#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

#define BAUDRATE 9600UL


#define UBRR_VAL (F_CPU / 16 / BAUDRATE - 1)


void uart_init(void){
    UBRR0H = (unsigned char) (ubrr>>8);
    UBBROL = (unsigned char) (ubrr);

    // Enable reciever 
    UCSR0B (1<<RXEN0) | (1<<TXEN0);

    // Set frame format: 8data, 2stop bit
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);

};

void uart_putchar(char chr){
    
};

void uart_putstr(const char *str){

};

char uart_getchar(void){

};

void uart_echo(void){

};
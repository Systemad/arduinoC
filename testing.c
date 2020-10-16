#include <avr/io.h>
#include <util/delay.h>

#include "testing.h"

void blinkLed(){

    /*
    *   0B001000 - PORTB3 / RED
    *    0B000100 - PORTB2 / BLUE
    *   0B000010 - PORTB1 / GREEN   
    */
    
    // Arduino digital pin 13 (pin 5 of PORTB) for output
    DDRB |= 0B000010;

    while(1) {
        // turn LED on
        PORTB |= 0B000010;
        _delay_ms(500);

        // turn LED off
        PORTB &= ~ 0B000010;
        _delay_ms(500);
    }
}
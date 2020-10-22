#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

void blinkLed(){

    /*
    *   0B001000 - PORTB3 - PB3 / RED
    *   0B000100 - PORTB2 - PB2 / BLUE
    *   0B000010 - PORTB1 - PB1 / GREEN   
    */
    
    DDRB |= (1<<PB3);

    while(1) {
        // turn LED on
        PORTB |= (1<<PB3);
        _delay_ms(500);

        // turn LED off
        PORTB &= ~(1<<PB3);
        _delay_ms(500);
    }
}
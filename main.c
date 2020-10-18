#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "serial.h"
#include "testing.h"

/*
* Deluppgift 1
* blinkLed() - Blink led, red, green or blue
*
* Deluppgift 2
* 1. uart_init() - Set up UART serial
* 2. uart_putchar() - Send char over transmit(TX)
* 3. uart_pustr() - Print string with help of uart_putshar
*/

void main (void) {

    char chr = 'h';

    //blinkLed();

    uart_init();

    uart_putchar(chr);
}

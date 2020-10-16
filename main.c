#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "serial.h"
#include "testing.h"


void main (void) {

    char chr = "h";

    /*
    * Deluppgift 1
    * blinkLed() - Blink led, red, green or blue
    */

    //blinkLed();

    /*
    * Deluppgift 2
    * 1. uart_init() - Set up UART serial
    * 2. uart_putchar() - Send char over transmit(TX)
    * 3. uart_pustr() - Print string with help of uart_putshar
    */

    uart_init();

    uart_putchar(chr);
}

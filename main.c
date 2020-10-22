#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "serial.h"
#include "led.h"

/*
* Deluppgift 1
* - blinkLed() - Blink led, red, green or blue
*
* Deluppgift 2
* - uart_init() - Set up UART serial
* - uart_putchar() - Send char over transmit(TX)
* - uart_pustr() - Print string with help of uart_putshar
*
* Deluppgift 3
* - uart_getchar() -  receive char from serial
* - uart_echo() - echo / print received with purchar char from getchar
*/

void main (void) {

    char chr = 'h';
    char *string = "test\rstring\r";

    //blinkLed();

    uart_init();

    //uart_putchar(chr);

    uart_putstr(string);
    //uart_getchar();

    // So we can write continuously 
    while(1){
        uart_echo();
    }
}

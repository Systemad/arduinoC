#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "serial.h"
#include "testing.h"

#define F_CPU 16000000

void main (void) {

    // Blink led function
    blinkLed();
}

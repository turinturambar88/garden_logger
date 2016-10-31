
// Standard AVR includes
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

// Standard includes
#include <stdlib.h>

// Project includes
#include "pin_defines.h"

#include "usart.h"
#include "adc.h"



// -------- Global Variables --------- //


int main(void) 
{
    // -------- Inits --------x- //
    init_usart();
    init_adc();

    sei(); // Enable interrupts

    // ------ Event loop ------ //
    while (1)
    {
        // Read all sensors
        
        // Transmit message

        // Enter low power mode
        
    }
    return 0;
}

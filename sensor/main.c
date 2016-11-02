
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
    // -------- Inits --------- //
    char serialCharacter;
    
    init_usart();
    init_adc();

    DDRB |= 0b0000001;

    //sei(); // Enable interrupts

    // ------ Event loop ------ //
    while (1)
    {
        // Read all sensors
        
        // Transmit message

        // Enter low power mode
        
        
        
        serialCharacter = receive_byte();
        transmit_byte(serialCharacter);
        
        
        if (serialCharacter == 'A')
        {
            PORTB = 0b00000001;
        }
        else
        {
            PORTB = 0b00000000;
        }

    }
    return 0;
}

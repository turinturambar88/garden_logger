
#include <avr/io.h>
#include <util/setbaud.h>

#include "usart.h"

void init_usart(void)
{
    UBRR0H = UBRRH_VALUE;                        /* defined in setbaud.h */
    UBRR0L = UBRRL_VALUE;
#if USE_2X
    UCSR0A |= (1 << U2X0);
#else
    UCSR0A &= ~(1 << U2X0);
#endif
                                  /* Enable USART transmitter/receiver */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   /* 8 data bits, 1 stop bit */
}

void transmit_byte(char data) 
{
                                     /* Wait for empty transmit buffer */
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = data;                                            /* send data */
  
}

char receive_byte(void) 
{
    loop_until_bit_is_set(UCSR0A, RXC0);       /* Wait for incoming data */
    return UDR0;                                /* return register value */
}

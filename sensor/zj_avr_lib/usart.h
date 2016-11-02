#ifndef AVR_USART_H
#define AVR_USART_H

void init_usart(void);
/* Takes the defined BAUD and F_CPU,
   calculates the bit-clock multiplier,
   and configures the hardware USART                   */

/* Blocking transmit and receive functions.*/
void transmit_byte(char data);

char receive_byte(void);


#endif


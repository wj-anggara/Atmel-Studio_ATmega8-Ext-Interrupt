/*
 * Interrupt.c
 *
 * Created: 18/02/2017 15:36:59
 * Author : Anggara Wijaya
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int a=0;

ISR(INT1_vect)
{
	a++;
}

int main(void)
{
    DDRD &= ~(1<<DD3);						//INPUT
    PORTD |= (1<<PD3);						//PULL_UP
    MCUCR |= (1<<ISC11) | (1<<ISC10);		// set INT1 to trigger on Falling
    GICR |= (1<<INT1);						// Turns on INT1
    sei();									// turn on interrupts
	
    while (1) 
    {
    }
}


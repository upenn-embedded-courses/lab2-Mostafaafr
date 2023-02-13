/*
 * ESE 350 Lab 2.c
 *
 * Created: 1/27/2023 2:31:43 PM
 * Author : mosta
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void Initialize()
{
	cli();
	DDRB|=(1<<DDB5); //defines an output
	DDRB &= ~(1<<DDB0); //setting input pin
	PORTB &= ~(1<<PORTB5); //Setting the LED to off state initially
	TCCR1B |= (1<<ICES1); // Looking for rising edge
	TIFR1 |= (1<<ICF1); //necessary stuff
	TIMSK1 |= (1<<ICIE1); //Enables input capture on timer 1
	sei();
}
ISR(TIMER1_CAPT_vect)
{
	PORTB ^= (1<<PORTB5); //Toggle the LED
	TCCR1B ^= (1<<ICES1); //Start Looking for Falling Edge
}

int main(void)
{
	Initialize();
	while (1);
}

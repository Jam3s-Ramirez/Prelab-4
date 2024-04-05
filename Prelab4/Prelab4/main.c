/**************************
Universidad del Valle de Guatemala
Programación de Microcrontroladores
Proyecto: Prelab 4
Hardware: ATMEGA328p
Created: 05/04/2024 08:11:46
Author : James Ramírez
***************************/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void setup(void);
void delay(uint8_t ciclos);	

int main(void)
{
	uint8_t contador;
	
	// Boton de Incremento
	DDRB &= ~(1<<DDB3);		// PB1 como entrada
	PORTB |= (1<<PORTB3);	// Activamos Pull-Up
	
	// Boton de Decremento
	DDRB &= ~(1<<DDB4);		// PB2 como entrada
	PORTB |= (1<<PORTB4);	// Activamos Pull-Up
	
	DDRD = 0xFF;				// Puerto D como salida
	
	contador = 0;
	
	while (1)
	{
		if (!(PINB & (1<<PINB3)))
		{
			if (contador < 255)
			{
				contador = contador + 1;
				PORTD = contador;
			}
			_delay_ms(200);
		}
		if (!(PINB & (1<<PINB4)))
		{
			if (contador > 0)
			{
				contador = contador -1;
				PORTD = contador;
			}
			_delay_ms(200);
		}
	}
}









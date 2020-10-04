/*
 * Created: 2020-10-04 15:49:23
 * Author : Jringstad
 */ 


#ifndef F_CPU
#define F_CPU 1250000UL // 16 MHz clock speed
#endif
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

ISR(INT0_vect)
{
	int closing = 1;
	while(closing>=1){
		PORTC = 0b11111101;
		_delay_ms(300);
		PORTC = 0b11111011;
		_delay_ms(300);
		closing++;
		if(closing>=6){
			PORTC = 0xFF;
			closing = 0;
		}
		
	}

	
	
}
int main(void)
{

	DDRC=0xFF;		/* Make PORTC as output PORT*/
	PORTC=0xFF;
	DDRD=0;			/* PORTD as input */
	PORTD=0xFF;		/* Make pull up high */

	GICR = 1<<INT0;		/* Enable INT0*/
	MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	sei();			/* Enable Global Interrupt */

	while(1)
	{
		PORTC=0b11111110;
		_delay_ms(1000);
		PORTC=0xFF;
		_delay_ms(1000);

		
	}
}

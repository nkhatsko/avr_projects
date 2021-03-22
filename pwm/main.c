#define F_CPU 800000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED PC0


int main(void) {

	TCCR1A |= (1 << COM1A1);
	TCCR1A &= ~(1 << COM1A0);

	TCCR1A |= (1 << WGM10);
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12);
	TCCR1B &= (1 << WGM13);

	TCCR1B |= (1 << CS11);
	TCCR1B &= ~(1 << CS12);
	TCCR1B &= ~(1 << CS10);

	OCR1A = 0;

	DDRB |= ((1 << PB1) | (1 << PB2));
	PORTB &= ~((1 << PB1) | (1 << PB2));

	while (1) {
		OCR1A += 100;

		if (OCR1A >= 1024) {
			OCR1A = 0;
		};
		_delay_ms(300);
	};

	return (0);

};

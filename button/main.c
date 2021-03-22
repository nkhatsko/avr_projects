#define F_CPU 800000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED    PC0
#define BUTTON PD0


int main(void) {

	DDRC |= (1 << LED);
	DDRD |= (1 << BUTTON);

	PORTC |= (1 << LED);
	PORTD |= (1 << BUTTON);

	while (1) {
		if (!(PIND & (1 << BUTTON))) {
			PORTC ^= (1 << LED);
		};
	};

	return (0);

};

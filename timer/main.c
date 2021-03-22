#include <avr/io.h>

#define LED PC2


int main(void) {

	DDRC |= (1 << LED);
	PORTC |= (1 << LED);

	TCCR0 |= ((1 << TCCR00) | (1 << TCCR02))
	TCNT0 = 0;

	while (1) {
		if (TCNT0 == 128 || TCNT0 == 255) {
			PORTC ^= (1 << LED);
		};
	};

	return (0);

};

#define F_CPU 800000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED PC0


int main(void) {

	DDRC |= (1 << LED);

	while (1) {
		PORTC ^= (1 << LED);
		_delay_ms(300);
	};

	return (0);

};

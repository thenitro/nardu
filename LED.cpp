#include "LED.h"

LED::LED(int pPin) {
	_pin   = pPin;
	_state = false;

	pinMode(_pin, OUTPUT);
}

void LED::on() {
	_state = true;

	digitalWrite(_pin, HIGH);
}

void LED::off() {
	_state = false;

	digitalWrite(_pin, LOW);
}

void LED::toggle() {
	if (_state) {
		off();
	} else {
		on();
	}
}
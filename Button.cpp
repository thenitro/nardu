#include "Button.h"

Button::Button(int pInputPin) {
	_inputPin = pInputPin;

	pinMode(_inputPin, INPUT);
}

void Button::update() {
	int state = digitalRead(_inputPin);

	if (state == HIGH) {
		(*_callback)();
	}
}

void Button::subscribe(void(*callback)()) {
	_callback = callback;
}
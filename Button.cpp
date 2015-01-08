#include "Button.h"

Button::Button(int pInputPin) {
	_inputPin = pInputPin;

	_lastButtonState = HIGH;

	pinMode(_inputPin, INPUT);
	digitalWrite(_inputPin, HIGH);
}

void Button::update() {
	int state = digitalRead(_inputPin);

	if (state != _lastButtonState && state == HIGH) {
		(*_callback)();
	}

	_lastButtonState = state;
}

void Button::subscribe(void(*callback)()) {
	_callback = callback;
}
#include "Sonar.h"

Sonar::Sonar(int pTrigPin, int pEchoPin) {
	_trigPin = pTrigPin;
	_echoPin = pEchoPin;

	_waitTime = 0;
	_lastTime = 0;

	_state = STATE_IDLE;

	pinMode(pTrigPin, OUTPUT);
	pinMode(pEchoPin, INPUT);
}

void Sonar::update() {
	int currentTime = millis();
	int timeDiff    = currentTime - _lastTime;

	if (timeDiff < _waitTime) {
		return;
	}

	if (_state == STATE_IDLE) {
		digitalWrite(_trigPin, LOW);

		_state    = STATE_SEND;
		_waitTime = 10;
		_lastTime = currentTime;

		return;
	}

	if (_state == STATE_SEND) {
		digitalWrite(_trigPin, HIGH);

		_state    = STATE_RECIVE;
		_waitTime = 40;
		_lastTime = currentTime;

		return;
	}

	if (_state == STATE_RECIVE) {
		digitalWrite(_trigPin, LOW);

		_state    = STATE_IDLE;
		_waitTime = 10;
		_lastTime = currentTime;

		long duration = pulseIn(_echoPin, HIGH);
		long distance = duration / SPEED_OF_SOUND;
			 distance = distance >= 6 ? distance : MAX_DISTANCE;
			 distance = clamp(distance, MIN_DISTANCE, MAX_DISTANCE);

		(*_callback)(distance);

		return;
	}
}

void Sonar::subscribe(void(*callback)(int)) {
	_callback = callback;
}
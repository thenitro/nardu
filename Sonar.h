#ifndef Sonar_h
#define Sonar_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "TMath.h"

#define MIN_DISTANCE 5
#define MAX_DISTANCE 400

#define SPEED_OF_SOUND 58.2

#define STATE_IDLE 0
#define STATE_SEND 1
#define STATE_RECIVE 2

class Sonar {
	public:
		Sonar(int pTrigPin, int pEchoPin);

		void update();
		void subscribe(void(*callback)(int));

	private:
		int _trigPin;
		int _echoPin;

		int _waitTime;
		int _lastTime;

		int _state;

		void (*_callback)(int);
};

#endif
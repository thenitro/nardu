#pragma once

#if (ARDUINO >= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class LED {
	public:
		LED(int pPin);

		void on();
		void off();

		void toggle();

	private:
		int _pin;
		bool _state;
};
#ifndef Button_h
#define Button_h

#if (ARDUINO >= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Button
{
	public:
		Button(int pInputPin);

		void update();
		void subscribe(void(*callback)());
	
	private:
		int _inputPin;

		void (*_callback)();
};

#endif
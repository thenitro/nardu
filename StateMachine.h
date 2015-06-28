#pragma once

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class StateMachine {
	public:
		void addState();
		void removeState();

		void startState();

	private:
		

};
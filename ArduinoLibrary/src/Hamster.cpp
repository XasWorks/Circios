
#include "Hamster.h"

#include <Arduino.h>

namespace Hamster {
	void begin(float Geschwindigkeit) {
		TimerControl::begin();
		Motors::begin();

		Movement::setSpeeds(TICKS_PER_LINE*Geschwindigkeit, TICKS_PER_TURN*Geschwindigkeit);
	}

	void vor() {
		Movement::moveBy(TICKS_PER_LINE);
		Movement::flush();
	}

	void linksUm() {
		Movement::rotateBy(TICKS_PER_TURN);
		Movement::flush();
	}
}

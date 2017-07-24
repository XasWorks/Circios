
#include "Hamster.h"

#include <Arduino.h>

namespace Hamster {
	void postBattery() {
		Serial.print("Batterie: ");
		Serial.print(analogRead(A0)*5.0/1024); Serial.println("V");
	}

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

	bool vornFrei() {
		Movement::moveBy(TICKS_FOR_MEASURE);
		Movement::flush();

		delay(100);

		bool hasWall = analogRead(A2) > 500;

		Movement::moveBy(-TICKS_FOR_MEASURE);
		Movement::flush();

		delay(50);

		return hasWall;
	}
}

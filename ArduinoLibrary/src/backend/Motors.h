
#ifndef MOTORS_H
#define MOTORS_H

#include "TimerControl.h"
#include "Pins.h"
#include <math.h>

#define P_FACT 0.05
#define D_FACT 0.12

#define MAX_MOTOR_DEFLECTION 1.5/P_FACT

namespace Motors {
	struct motorData {
	   float    target  = 0;
	   int32_t  is      = 0;
	   int32_t  was     = 0;
	};

	extern motorData motorA, motorB;

	void begin();
	void update();

	bool atPosition();

	void moveBy(float m, float r);
}

#endif

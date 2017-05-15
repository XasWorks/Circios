
#ifndef MOTORS_H
#define MOTORS_H

#include "TimerControl.h"
#include "Pins.h"
#include <math.h>

#define P_FACT 0.05
#define D_FACT 0.12

namespace Motors {
	struct motorData {
	   float    target  = 0;
	   int32_t  is      = 0;
	   int32_t  was     = 0;
	};

	extern motorData motorA, motorB;

	void begin();
	void update();
}

#endif


#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H

#include "Motors.h"
#include <util/delay.h>

namespace Movement {
	void setSpeeds(float mSpeed, float rSpeed);

	void update();

	bool isReady();
	void flush();

	void moveBy(float distance);
	void rotateBy(float distance);
}

#endif

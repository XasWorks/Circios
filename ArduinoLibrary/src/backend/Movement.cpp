
#include "Movement.h"

namespace Movement {
	// If in is below max, return in
	// Otherwise however, return max with the sign of in, so that no value greater than max is returned
	float clamp(float in, float max) {
		return (fabs(in) > fabs(max)) ?
			copysign(max, in) :
			in;
	}

	float remainingRotation = 0;
	float remainingMovement = 0;

	float rotationSpeed = 1;
	float movementSpeed = 1;

	void setSpeeds(float mSpeed, float rSpeed) {
		if(mSpeed < 0.1)
			mSpeed = 0.1;

		movementSpeed = mSpeed/UPDATE_FREQUENCY;

		if(rSpeed < 0.1)
			rSpeed = 0.1;

		rotationSpeed = rSpeed/UPDATE_FREQUENCY;
	}

	void update() {
		if(!Motors::atPosition())
			return;

		float rThisCal = clamp(remainingRotation, rotationSpeed);
		float mThisCal = clamp(remainingMovement, movementSpeed);

		remainingRotation -= rThisCal;
		remainingMovement -= mThisCal;

		Motors::moveBy(mThisCal, rThisCal);
	}

	bool isReady() {
		if(fabs(remainingRotation) > 0.9)
			return false;
		if(fabs(remainingMovement) > 0.9)
			return false;

		return Motors::atPosition();
	}
	void flush() {
		while(!isReady()) {
			_delay_ms(1);
		}
	}


	void moveBy(float mDistance) {
		remainingMovement += mDistance;
	}
	void rotateBy(float rotation) {
		remainingRotation += rotation;
	}
}

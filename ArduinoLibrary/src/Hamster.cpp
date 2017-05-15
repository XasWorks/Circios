
#include "Hamster.h"

namespace Hamster {
	float Geschwindigkeit = 1;

	void begin() {
		TimerControl::begin();
		Motors::begin();
	}
}

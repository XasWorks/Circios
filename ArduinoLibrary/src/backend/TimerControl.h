
#ifndef TIMER_CONTROL_H
#define TIMER_CONTROL_H

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Motors.h"
#include "Movement.h"
#include "Hamster.h"

namespace TimerControl {
	void setPWM_A(float pwm);
	void setPWM_B(float pwm);

	void begin();
}

#endif

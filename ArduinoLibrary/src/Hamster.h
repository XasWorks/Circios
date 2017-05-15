
#if defined(__AVR_ATmega328P__)
#else
#error "Sorry, this Chip-Type isn't supported yet!"
#endif

#ifndef __HAMSTER_H
#define HAMSTER_H

#include "backend/Motors.h"
#include "backend/TimerControl.h"

namespace Hamster {
	extern float Geschwindigkeit;

	void begin();
}

//void vor(unsigned byte n);
//void linksUm();
//void rechtsUm();

#endif

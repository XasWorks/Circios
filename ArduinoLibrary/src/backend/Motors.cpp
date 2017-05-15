
#include "Motors.h"

#include <Arduino.h>

namespace Motors {
	motorData motorA, motorB;
}

ISR(INT0_vect) {
   if( ((PIND>>MOTOR_A_C1 ^ PIND>>MOTOR_A_C2) & 1) == 0)
      Motors::motorA.is--;
   else
      Motors::motorA.is++;
}
ISR(INT1_vect) {
   if( ((PIND>>MOTOR_B_C1 ^ PIND>>MOTOR_B_C2) & 1) == 0)
      Motors::motorB.is--;
   else
      Motors::motorB.is++;
}


namespace Motors {
	void begin() {
		// Setup der Pin-Interrupts
		EICRA |= (1<< ISC00 | 1<< ISC10);
		EIMSK |= (1<< INT0  | 1<< INT1);

		// Setup der Input-Pins
		PORTD |= (1<< MOTOR_A_C1 | 1<< MOTOR_A_C2 | 1<< MOTOR_B_C1 | 1<<MOTOR_B_C2);
		// Setup der Output-Pins
		DDRB 	|= (1<< MOTOR_A_DIR | 1<< MOTOR_A_PWM | 1<< MOTOR_B_DIR | 1<< MOTOR_B_PWM);
	}

	float limitPower(float inPower) {
		if(inPower < 0.01)
			return 0;
		if(inPower > 1)
			return 1;

		return inPower;
	}

	float getPD(motorData * m) {
		float oPower = (m->target - m->is)*P_FACT + (m->was - m->is)*D_FACT;
		m->was = m->is;
		return oPower;
	}

	void setPowers() {
		float mPWR = getPD(&motorA);
		TimerControl::setPWM_A(limitPower(fabs(mPWR)));
		PORTB &= ~(1<< MOTOR_A_DIR);
		if(mPWR > 0)
			PORTB |= (1<< MOTOR_A_DIR);

		mPWR = getPD(&motorB);
		TimerControl::setPWM_B(limitPower(fabs(mPWR)));
		PORTB &= ~(1<< MOTOR_B_DIR);
		if(mPWR > 0)
			PORTB |= (1<< MOTOR_B_DIR);
	}

	void update() {
		setPowers();
	}
}

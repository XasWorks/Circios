
#include "TimerControl.h"

namespace TimerControl {
	void begin() {
		// OC1A und OC1B auf Noninverted-PWM-Mode setzen (COM1x1)
		//WGM13 WGM11 (Für PWM Phase-Correct mit TOP: ICR1)
		// Clock-Prescaler auf 1, ICR1 auf 8000 für 1kHz
		TCCR1A = (1<< COM1A1 | 1<< COM1B1 | 1<< WGM11);
		TCCR1B = (1<< WGM13 | 1<< CS10);
		ICR1 	 =  8000;

		// Timer-Interrupt "an schalten"
		TIMSK1 |= (1<< TOIE1);
	}

	void setPWM_A(float pwr) {
		OCR1A = pwr * 8000;
	}
	void setPWM_B(float pwr) {
		OCR1B = pwr * 8000;
	}
}

uint8_t prescA = 1;
ISR(TIMER1_OVF_vect) {
	if(--prescA == 0) {
		sei();
		Movement::update();
		Motors::update();
		prescA = 1000/UPDATE_FREQUENCY;
	}
}

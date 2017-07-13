

#include "LComs.h"

namespace LComs {

	uint16_t triggerValue = DEFAULT_TRIGGER_BRIGHTNESS;

	void setTriggerBrightness(uint16_t b) {
		triggerValue = b;
	}

	void SBitH() {
		delay(SIG_LEN/3);
		digitalWrite(OUT_PIN, HIGH);
		delay(SIG_LEN/3);
		digitalWrite(OUT_PIN, LOW);
		delay(SIG_LEN/3);
	}

	void SBitL() {
		delay(SIG_LEN);
	}

	bool RBit() {
		delay(SIG_LEN/2);
		bool result = (analogRead(IN_PIN) > triggerValue);
		delay(SIG_LEN/2);
		return result;
	}

	bool Start() {
		SBitH();
		return RBit();
	}

	void sendBits(uint16_t d, uint8_t n) {
		if(n > 16) return;

		while(n-- != 0) {
			if((d & 1) == 0)
				SBitL();
			else
			 	SBitH();

			d >>= 1;
		}
	}

	uint16_t recBits(uint8_t n) {
		if(n > 16) return 0;

		uint16_t result = 0;
		uint16_t mask = 1;
		while(n-- != 0) {
			if(RBit())
				result |= mask;
			mask <<= 1;
		}

		return result;
	}

	void reportBattery() {
		if(!Start()) return;

		sendBits(OpCode::batterie, 3);
		sendBits(analogRead(A0), 10);
	}

	void print(uint8_t * message) {
		if(!Start()) return;

		sendBits(OpCode::customMSG, 3);

		while(1) {
			sendBits(*message, 8);
			if(*message == 0)
				break;
			message++;
			if(!Start()) return;
		}
	}
}

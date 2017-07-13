

#include <Arduino.h>

#ifndef L_COMS_H
#define L_COMS_H

#define OUT_PIN 13
#define IN_PIN A1
#define DEFAULT_TRIGGER_BRIGHTNESS 300

#define SIG_LEN 30

namespace LComs {
	enum OpCode : uint8_t {
		empty,
		kornNum,
		nimmKorn,
		gibKorn,
		customMSG = 0b110,
		batterie = 0b111
	};

	void setTriggerBrightness(uint16_t b);

	void SBitH();
	void SBitL();
	bool RBit();

	void sendBits(uint16_t d, uint8_t n);
	uint16_t recBits(uint8_t n);

	void reportBattery();

	void print(uint8_t * string);
}

#endif

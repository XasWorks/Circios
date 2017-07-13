#include <Hamster.h>

using namespace LComs;

void setup() {
  Serial.begin(9600);
  
  pinMode(OUT_PIN, OUTPUT);

  setTriggerBrightness(800);
}

void waitForStart() {
  while(analogRead(IN_PIN) < 800) {}

  delay(2 * SIG_LEN/3);
  SBitH();
}

void loop() {
  waitForStart();
  uint8_t oCode = recBits(3);

  if(oCode == OpCode::batterie) {
    Serial.print("Batterie: ");
    Serial.println(recBits(10)*5.0 / 1023);
  }
  else if(oCode == OpCode::customMSG) {
    while(1) {
      char c = recBits(8);
      Serial.write(c);
      if(c == 0)
        return;

      waitForStart();
    }
  }
}

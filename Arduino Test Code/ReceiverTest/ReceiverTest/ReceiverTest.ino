#include <Hamster.h>

using namespace LComs;

void setup() {
  Serial.begin(9600);
  
  pinMode(OUT_PIN, OUTPUT);
  
  triggerValue = analogRead(IN_PIN) + TRIG_HYSTHERESIS;
}

uint8_t timeoutTicks = 0;
bool waitForStart() {
  timeoutTicks = 0;
  while(analogRead(IN_PIN) < triggerValue) {
    timeoutTicks++;
    if(timeoutTicks == 0) 
      return false;
    triggerValue = analogRead(IN_PIN) + TRIG_HYSTHERESIS; 
    delay(1);
  }

  delay(2 * SIG_LEN/3);
  SBitH();
  return true;
}

void loop() {
  if(!waitForStart())
    return;
   
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

      if(!waitForStart())
        return;
    }
  }
}

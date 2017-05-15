#include <Hamster.h>

void setup() {
  Serial.begin(9600);
  Hamster::begin();
}

void loop() {
  delay(5000);
  Motors::motorA.target += 25 * TICKS_PER_TOOTH;
  delay(5000);
  Motors::motorA.target = 0;
}

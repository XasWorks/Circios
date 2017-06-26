#include <Hamster.h>

void setup() {
  Serial.begin(9600);
  Hamster::begin(1);

  pinMode(13, OUTPUT);
}

uint8_t mPresc = 100;
void loop() {
  Hamster::linksUm();
  Hamster::linksUm();
  delay(500);
  Hamster::vor();
  delay(500);
}

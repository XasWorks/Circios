#include <Hamster.h>

void setup() {
  Serial.begin(9600);
  Hamster::begin(1);

  pinMode(13, OUTPUT);
}

void loop() {
  delay(500);
  Hamster::vor();
  delay(500);
  Hamster::linksUm();
  Hamster::linksUm();
}

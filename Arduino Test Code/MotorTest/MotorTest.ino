#include <Hamster.h>

void setup() {
  Serial.begin(9600);
  Hamster::begin(0.75);

  pinMode(13, OUTPUT);
}

uint8_t mPresc = 100;
void loop() {
  delay(3000);
  Hamster::vor();
  Hamster::linksUm();
  Hamster::vor();

  delay(2000);

  Hamster::linksUm();
  Hamster::linksUm();
  Hamster::vor();

  for(uint8_t i=0; i<3; i++)
    Hamster::linksUm();

  Hamster::vor();

  Hamster::linksUm();
  Hamster::linksUm();

  delay(2000);
}

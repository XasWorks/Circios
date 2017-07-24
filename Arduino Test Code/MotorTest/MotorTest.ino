#include <Hamster.h>

void setup() {
  Serial.begin(9600);
  Hamster::begin(1);

  pinMode(13, OUTPUT);

  LComs::reportBattery();
}

void loop() {
  delay(5000);
  
  if(Hamster::vornFrei())
    Hamster::vor();
  else
    Hamster::linksUm();
}

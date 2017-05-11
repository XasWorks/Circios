
#include <MsTimer2.h>

#include <avr/interrupt.h>

volatile int32_t pos = 0;
volatile int32_t targetPos = 500;
ISR(INT0_vect) {
  if(((PIND & 1<<4)>>4) != ((PIND & 1<<2)>>2))
    pos--;
  else 
    pos++;
}

#define P_FACT -10
#define D_FACT -25

int32_t formerPos = 0;
void setPD() {
  int tDiff = pos - targetPos;
  int mSpeed = pos - formerPos;
  formerPos = pos;

  //Serial.println(tDiff);
  setMotor(tDiff * P_FACT + mSpeed * D_FACT);
}


void setup() {
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);

  EICRA |= (1<< ISC00);
  EIMSK |= (1<< INT0);

  MsTimer2::set(10, setPD);
  MsTimer2::start();
}

void setMotor(int32_t pwr) {
  if(pwr < 0) {
    digitalWrite(8, LOW);
    pwr *= -1;
  }
  else 
    digitalWrite(8, HIGH);

  if(pwr > 255)
    pwr = 255;
  if(pwr < 30) 
    pwr = 0;
  else if(pwr < 70)
    pwr = 70;
  analogWrite(9, pwr);
}

float phase = 0;
void loop() {
  delay(10);
  targetPos = sin(phase += 0.01) * 3000;
}

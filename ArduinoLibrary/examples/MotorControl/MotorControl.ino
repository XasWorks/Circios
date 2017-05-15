
#include <MsTimer2.h>

#include <avr/interrupt.h>

struct motorData {
   float    target  = 0;
   int32_t  is      = 0;
   int32_t  was     = 0;
} motorA, motorB;

volatile int32_t pos = 0;
volatile int32_t targetPos = 300;

// (PIND>>4 ^ PIND>>2) & 1

ISR(INT0_vect) {
   if( ((PIND>>4 ^ PIND>>2) & 1) == 0)
      motorA.is--;
   else
      motorA.is++;
}
ISR(INT1_vect) {
   if( ((PIND>>3 ^ PIND>>5) & 1) == 0)
      motorB.is--;
   else
      motorB.is++;
}

#define P_FACT -3
#define D_FACT -25
int32_t getPD(motorData m) {
   int32_t tDiff = m.is - m.target;
   int mSpeed = m.is - m.was;
      m.was = m.is;

   return P_FACT * tDiff + D_FACT * mSpeed;
}

void setPD() {
   setMotor(getPD(motorA), 0);
   setMotor(getPD(motorB), 1);
}

void setup() {
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

  EICRA |= (1<< ISC00 | 1<< ISC10);
  EIMSK |= (1<< INT0  | 1<< INT1);

  MsTimer2::set(1, setPD);
  MsTimer2::start();
}

void setMotor(int32_t pwr, uint8_t mNum) {
  if(pwr < 0) {
    digitalWrite(7 + mNum, LOW);
    pwr *= -1;
  }
  else
    digitalWrite(7 + mNum, HIGH);

  if(pwr > 255)
    pwr = 255;
  if(pwr < 30)
    pwr = 0;
  else if(pwr < 70)
    pwr = 70;
  analogWrite(9 + mNum, pwr);
}

void loop() {
  delay(1000);
  targetPos = -targetPos;
}

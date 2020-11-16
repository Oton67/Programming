#include <Wire.h>
#define ds3231_adr 0x68
#define interruptPin 2

volatile byte state = LOW;
volatile byte sec = 0;
volatile byte minute = 0;
volatile byte hour = 0;

void intFun()
{
  state = !state;

  sec++;
  if (sec == 60)
  {
    minute++;
    sec=0;
  }

  if (minute == 60)
  {
    hour++;
    if(hour==24) hour=0;
    minute = 0;
  }
}

void setup() {
  Wire.begin();

  pinMode(13, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), intFun, FALLING);

  Wire.beginTransmission(ds3231_adr);
  Wire.write(0x0E);

  Wire.write(0x00);
  Wire.endTransmission();

}

void loop() {
  digitalWrite(13, state);
}

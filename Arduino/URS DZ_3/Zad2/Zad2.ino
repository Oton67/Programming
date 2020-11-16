#include <Wire.h>
#define ds3231_adr 0x68

void setup() {
  Wire.begin();


  Wire.beginTransmission(ds3231_adr);
  Wire.write(0x0E);

  Wire.write(0x00);
  Wire.endTransmission();

}

void loop() {
}

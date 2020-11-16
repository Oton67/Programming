#include <Wire.h>

#define ds3231_adr 0x68

int incomingByte = 0;
byte tmp_number = 0x00;


void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  tmp_number = 0;
  Wire.beginTransmission(ds3231_adr);
  Wire.write(0x00);
  byte I2Cerror = Wire.endTransmission();
  if (I2Cerror)
  {
    Serial.print("I2C error :");
    Serial.println(I2Cerror);
    delay(1000);
    return;
  }

  Wire.requestFrom(ds3231_adr, 3);
  byte seconds = Wire.read();
  byte minutes = Wire.read();
  byte hours = Wire.read();

  Serial.print(hours, HEX); Serial.print(":");
  Serial.print(minutes, HEX); Serial.print(":");
  Serial.print(seconds, HEX);
  Serial.print("\n");
  delay(250);

  while (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if (incomingByte >= '0' && incomingByte <= '9')
    {
      tmp_number = tmp_number << 4;
      tmp_number = tmp_number | incomingByte - '0';
    }

    if (incomingByte == 'h')
    {
      Wire.beginTransmission(ds3231_adr);
      Wire.write(0x02);

      Wire.write(tmp_number);//sat
      Wire.endTransmission();
    }
    if (incomingByte == 'm')
    {
      Wire.beginTransmission(ds3231_adr);
      Wire.write(0x01);

      Wire.write(tmp_number);//min
      Wire.endTransmission();
    }
    if (incomingByte == 's')
    {
      Wire.beginTransmission(ds3231_adr);
      Wire.write(0x00);

      Wire.write(tmp_number);//sec
      Wire.endTransmission();
    }
  }



}

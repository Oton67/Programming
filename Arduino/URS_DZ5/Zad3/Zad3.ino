#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>

OneWire ds(10);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#define ds3231_adr 0x68
#define USE_RTC       1
#define USEHW         1

uint32_t i = 1;
int poz = 0, len = 15;

int hour = 19, minute = 21, second = 0;
int year = 2016, month = 8, day = 20, dayOfWeek = 6;

int h1, h0, m1, m0, s1, s0;

void setup()
{
  Wire.begin(); // Inicijalizacija i2c sabirnice
  lcd.init(); // initializacija LCD-a
  lcd.backlight(); // funkcija za paljene pozadinskog osvjetljenja

  Serial.begin(9600);
  Wire.begin();
}

void loop()
{


  ds.reset();
  ds.write(0xCC); //skip rom
  ds.write(0x44); // Convert (počinje mjeriti temperaturu
  delay(1000); // treba mu barem 750ms
  ds.reset();
  ds.write(0xCC); //skip rom
  ds.write(0xBE); // read ScratchPad
  byte dsData[9];
  for (int i = 0; i < 9; i++)
  {
    dsData[i] = ds.read();
    Serial.print(dsData[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  int16_t intTemp = 0x0000;
  intTemp = dsData[1];
  intTemp = intTemp << 8;
  intTemp = intTemp | dsData[0];
  float floatTemp = intTemp;
  floatTemp = floatTemp / 16;
  Serial.print(floatTemp, 2);
  Serial.print("\n");

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(floatTemp);

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
  byte second = Wire.read();
  byte minute = Wire.read();
  byte hour = Wire.read();


  lcd.setCursor(0, 0);
  lcd.print(hour, HEX);
  lcd.print("h ");
  lcd.print(minute, HEX);
  lcd.print("m ");
  lcd.print(second, HEX);
  lcd.print("s ");

}

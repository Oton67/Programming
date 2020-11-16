#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
OneWire ds(10);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

uint32_t i = 1;
int poz = 0, len = 15;

void setup()
{
  Wire.begin(); // Inicijalizacija i2c sabirnice
  lcd.init(); // initializacija LCD-a
  lcd.backlight(); // funkcija za paljene pozadinskog osvjetljenja

  Serial.begin(9600);
}

int prost(int n)
{
  int i;
  if (n < 2) return 0;

  for (i = 2; i < n; i++) if (n % i == 0) return 0;

  return 1;
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
lcd.setCursor(0, 0);
        lcd.print(floatTemp);

}

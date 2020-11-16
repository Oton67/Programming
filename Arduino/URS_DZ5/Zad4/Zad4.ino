#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include "DPir.h"

OneWire ds(10);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#define ds3231_adr 0x68
#define IRdata 4

int hour = 0, minute = 0, second = 0;
int year = 0, month = 0, day = 0;

byte IRcode[6];
float floatTemp = 0;
int flagH = 1, flagM = 1, flagS = 1, flag = 0, flagDan=1, flagMjesec=1, flagGodina=1;
byte tmp_number = 0;
byte myCode[10][6] = {
  {0xD1, 0x50, 0x41, 0x00, 0x50, 0x50 }, //0
  {0x84, 0x00, 0x41, 0x00, 0x05, 0x00 }, //1
  {0xD4, 0x00, 0x41, 0x00, 0x55, 0x00 }, //2
  {0x90, 0x00, 0x41, 0x00, 0x11, 0x00 }, //3
  {0x80, 0x40, 0x41, 0x00, 0x01, 0x40 }, //4
  {0xD0, 0x40, 0x41, 0x00, 0x51, 0x40 }, //5
  {0x94, 0x40, 0x41, 0x00, 0x15, 0x40 }, //6
  {0x85, 0x40, 0x41, 0x00, 0x04, 0x40 }, //7
  {0xD5, 0x40, 0x41, 0x00, 0x54, 0x40 }, //8
  {0x91, 0x40, 0x41, 0x00, 0x10, 0x40 }  //9
};

byte H[6] = {0x85, 0x54, 0x41, 0x00, 0x04, 0x54};
byte M[6] = {0xC1, 0x45, 0x41, 0x00, 0x40, 0x45};
byte S[6] = {0xD4, 0x14, 0x41, 0x00, 0x55, 0x14};
byte Dan[6] = {0x85, 0x51, 0x41, 0x00, 0x04, 0x51};
byte Mjesec[6] = {0x84, 0x50, 0x41, 0x00, 0x05, 0x50};
byte Godina[6] = {0xD4, 0x50, 0x41, 0x00, 0x55, 0x50};
byte OK[6] = {0x80, 0x51, 0x41, 0x00, 0x01, 0x51};

DPir dpir(IRdata);

byte checkCode()
{
  for (int i = 0; i < 10; i++)
  {
    byte ok = 1;
    for (int j = 0; j < 6; j++) if (IRcode[j] != myCode[i][j]) ok = 0;
    if (ok == 1) return i;
  }
  return 0;
}

void uploadCustomChars()
{
  byte degree[8] = {
    B01100,
    B10010,
    B10010,
    B01100,
    B00000,
    B00000,
    B00000
  };
  byte therm[8] = {
    0b00100,
    0b01010,
    0b01010,
    0b01010,
    0b01110,
    0b11111,
    0b11111,
    0b01110
  };
  lcd.createChar(0, degree) ;
  lcd.createChar(1, therm) ;
}


void setup()
{
  Wire.begin(); // Inicijalizacija i2c sabirnice
  lcd.init(); // initializacija LCD-a
  lcd.backlight(); // funkcija za paljene pozadinskog osvjetljenja

  Serial.begin(9600);
  Wire.begin();
  uploadCustomChars();
}


void Temp()
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

  }
  int16_t intTemp = 0x0000;
  intTemp = dsData[1];
  intTemp = intTemp << 8;
  intTemp = intTemp | dsData[0];
  floatTemp = intTemp;
  floatTemp = floatTemp / 16;
}

void Time()
{
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
  second = Wire.read();
  minute = Wire.read();
  hour = Wire.read();
}

void Date()
{
  Wire.beginTransmission(ds3231_adr);
  Wire.write(0x04);
  byte I2Cerror = Wire.endTransmission();
  if (I2Cerror)
  {
    Serial.print("I2C error :");
    Serial.println(I2Cerror);
    delay(1000);
    return;
  }
  Wire.requestFrom(ds3231_adr, 3);
  day = Wire.read();
  month = Wire.read();
  year = Wire.read();
}

void loop()
{
  Temp();
  Time();
  Date();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(hour, HEX);
  lcd.print("h ");
  lcd.print(minute, HEX);
  lcd.print("m ");
  lcd.print(second, HEX);
  lcd.print("s ");

  lcd.setCursor(0, 1);
  lcd.write(1);
  lcd.print(floatTemp);
  lcd.write(0);
  lcd.print("C ");
  lcd.print(day, HEX);
  lcd.print(".");
  lcd.print(month, HEX);
  lcd.print(".");
  lcd.print(year, HEX);
  lcd.print(".");

  if (dpir.available() != 0)
  {
    dpir.getCode(IRcode);



    for (int i = 0; i < 6; i++) if (IRcode[i] != H[i]) flagH = 0;

    lcd.clear();

    while (flagH == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Sati: ");

      if (dpir.available() != 0)
      {
        delay(100);
        dpir.getCode(IRcode);

        flagH = 0;
        for (int i = 0; i < 6; i++) if (IRcode[i] != OK[i]) flagH = 1;

        if (flagH == 1)
        {
          tmp_number = tmp_number << 4;
          tmp_number = tmp_number | checkCode();

          Wire.beginTransmission(ds3231_adr);
          Wire.write(0x02);

          Wire.write(tmp_number);
          Wire.endTransmission();
        }
        lcd.setCursor(0, 0);
        lcd.print("Sati: ");
        lcd.print(tmp_number, HEX);
      }
    }

    for (int i = 0; i < 6; i++) if (IRcode[i] != M[i]) flagM = 0;

    while (flagM == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Minute: ");

      if (dpir.available() != 0)
      {
        delay(100);
        dpir.getCode(IRcode);

        flagM = 0;
        for (int i = 0; i < 6; i++) if (IRcode[i] != OK[i]) flagM = 1;

        if (flagM == 1)
        {
          tmp_number = tmp_number << 4;
          tmp_number = tmp_number | checkCode();

          Wire.beginTransmission(ds3231_adr);
          Wire.write(0x01);

          Wire.write(tmp_number);
          Wire.endTransmission();
        }
        lcd.setCursor(0, 0);
        lcd.print("Minute: ");
        lcd.print(tmp_number, HEX);
      }
    }

    for (int i = 0; i < 6; i++) if (IRcode[i] != S[i]) flagS = 0;

    while (flagS == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Sekunde: ");

      if (dpir.available() != 0)
      {
        delay(100);
        dpir.getCode(IRcode);

        flagS = 0;
        for (int i = 0; i < 6; i++) if (IRcode[i] != OK[i]) flagS = 1;

        if (flagS == 1)
        {
          tmp_number = tmp_number << 4;
          tmp_number = tmp_number | checkCode();

          Wire.beginTransmission(ds3231_adr);
          Wire.write(0x00);

          Wire.write(tmp_number);
          Wire.endTransmission();
        }
        lcd.setCursor(0, 0);
        lcd.print("Sekunde: ");
        lcd.print(tmp_number, HEX);
      }
    }

    for (int i = 0; i < 6; i++) if (IRcode[i] != Dan[i]) flagDan = 0;

    while (flagDan == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Dan: ");

      if (dpir.available() != 0)
      {
        delay(100);
        dpir.getCode(IRcode);

        flagDan = 0;
        for (int i = 0; i < 6; i++) if (IRcode[i] != OK[i]) flagDan = 1;

        if (flagDan == 1)
        {
          tmp_number = tmp_number << 4;
          tmp_number = tmp_number | checkCode();

          Wire.beginTransmission(ds3231_adr);
          Wire.write(0x04);

          Wire.write(tmp_number);
          Wire.endTransmission();
        }
        lcd.setCursor(0, 0);
        lcd.print("Dan: ");
        lcd.print(tmp_number, HEX);
      }
    }

    for (int i = 0; i < 6; i++) if (IRcode[i] != Mjesec[i]) flagMjesec = 0;

    while (flagMjesec == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Mjesec: ");

      if (dpir.available() != 0)
      {
        delay(100);
        dpir.getCode(IRcode);

        flagMjesec = 0;
        for (int i = 0; i < 6; i++) if (IRcode[i] != OK[i]) flagMjesec = 1;

        if (flagMjesec == 1)
        {
          tmp_number = tmp_number << 4;
          tmp_number = tmp_number | checkCode();

          Wire.beginTransmission(ds3231_adr);
          Wire.write(0x05);

          Wire.write(tmp_number);
          Wire.endTransmission();
        }
        lcd.setCursor(0, 0);
        lcd.print("Mjesec: ");
        lcd.print(tmp_number, HEX);
      }
    }

    for (int i = 0; i < 6; i++) if (IRcode[i] != Godina[i]) flagGodina = 0;

    while (flagGodina == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Godina: ");

      if (dpir.available() != 0)
      {
        delay(100);
        dpir.getCode(IRcode);

        flagGodina = 0;
        for (int i = 0; i < 6; i++) if (IRcode[i] != OK[i]) flagGodina = 1;

        if (flagGodina == 1)
        {
          tmp_number = tmp_number << 4;
          tmp_number = tmp_number | checkCode();

          Wire.beginTransmission(ds3231_adr);
          Wire.write(0x06);

          Wire.write(tmp_number);
          Wire.endTransmission();
        }
        lcd.setCursor(0, 0);
        lcd.print("Godina: ");
        lcd.print(tmp_number, HEX);
      }
    }

    flagH = 1;
    flagM = 1;
    flagS = 1;
    flagDan = 1;
    flagMjesec = 1;
    flagGodina = 1;
    tmp_number = 0;
  }
}

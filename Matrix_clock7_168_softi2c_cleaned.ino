#include <Wire.h>
#include "DPir.h"

#define LOW_MEM_DEBUG 0
#define DEBUG_RTC     0

#define USE_RTC       1  // 1 for RTC clock module (default)
#define USEHW         1  // 1 for hw I2C RTC on A4/A5 pins
#define NUM_MAX       4


// MAX7219 matrices pins
#define DIN_PIN 10
#define CS_PIN  11
#define CLK_PIN 12

#define BUTTON 6
#define THERMISTOR_PIN A0

#define IRdata 3
#define ds3231_adr 0x68
#define ADC1 A0

int hour = 19, minute = 21, second = 0;
int year = 2016, month = 8, day = 20, dayOfWeek = 6;

#include "rtc.h"
#include "max7219.h"
#include "fonts.h"

int a = 0;
int cnt = -1;
byte IRcode[6];
// kodovi od 3 razlicita gumba
int flagH = 1, flagM = 1, flagS = 1, flagHMS = 0,secFr, lastSec=-1;
byte tmp_number = 0, WW = 0x00;
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
byte OK[6] = {0x80, 0x51, 0x41, 0x00, 0x01, 0x51};

byte tipkalo_zadnje_stanje = 1;
byte ledState = 0;

int h1, h0, m1, m0, s1, s0;
int d1,d0,mn1,mn0,y1,y0,dw;
int dots = 0;
int commandMode = 0;
float temp = 0;
uint32_t startTime, diffTime, zeroTime, lastMillisD, lastMillisL, lastMillisD1, lastMillisL1;
int Flag = 0;

DPir dpir(IRdata);



//------------------------------------------------------------------------------------------------
int checkModeBt()
{
  if ( digitalRead(BUTTON) == 0 && tipkalo_zadnje_stanje == 1)
  {
    tipkalo_zadnje_stanje = 0;
    return 1;
  }

  if (digitalRead(BUTTON) == 1 && tipkalo_zadnje_stanje == 0)
  {
    tipkalo_zadnje_stanje = 1;
  }
  return 0;
}

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

void updateTime()
{
  if ( USE_RTC == 1) getRTCDateTime();
  else {
    diffTime = (millis() - zeroTime) / 1000;
    if (diffTime <= 0) return;
    zeroTime += diffTime * 1000;
    for (int i = 0; i < diffTime; i++) {
      second++;
      if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
          minute = 0;
          hour++;
          if (hour >= 24) {
            hour = 0;
            dayOfWeek++;
          if(dayOfWeek>7)
            dayOfWeek=1;
          day++;
          if(day>31) {
            day=1;
            month++;
            if(month>12) {
              month=1;
              year++;
            }
           }
          }
        }
      }
    }
  }
}
//-----------------------------------------------------------------------------------
void setup()
{
  
  Serial.begin (9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(ADC1, INPUT);

  initMAX7219();
  clr();
  refreshAll();
  sendCmdAll(CMD_SHUTDOWN, 1);
  sendCmdAll(CMD_INTENSITY, 3);

  Wire.begin();
  temp = readTherm();
  zeroTime = millis();
  lastMillisD = millis();
  lastMillisL = millis();
  lastMillisD1 = millis();
  lastMillisL1 = millis();
  
}
//---------------------------------------------------------------------------------------------
void loop()
{
  startTime = millis();
  updateTime();

  h1 = hour / 10;
  h0 = hour % 10;
  m1 = minute / 10;
  m0 = minute % 10;
  s1 = second / 10;
  s0 = second % 10;
  d1 = day / 10;
  d0 = day % 10;
  mn1 = month / 10;
  mn0 = month % 10;
  y1 = (year - 2000)/10;
  y0 = (year - 2000)%10;

  if(second!=lastSec) {
    lastSec = second;
    secFr = 0;
  } else
    secFr++;

  if (cnt < 0) cnt = second * 10;
  if (secFr == 0) cnt = 0;
  dots = (cnt % 40 < 20) ? 1 : 0;


  clr();
  if ( checkModeBt()) Flag = (Flag + 1) % 4;
  
  if (Flag == 0)
    showClockMed();
  if (Flag == 1)
    showClockBig();
  if (Flag == 2)
    showDate();
    if (Flag == 3)
    showTemp();
  

  int adcVal = analogRead(ADC1);
  if (adcVal > 650 && millis()-lastMillisD > 10000)
  {
    lastMillisL = millis();
    lastMillisL1 = millis();
    lastMillisD1 = millis();
    sendCmdAll(CMD_INTENSITY, 0);
  }
  if (adcVal < 650 && adcVal > 450 && millis()-lastMillisD1 > 10000)
  {
    lastMillisL = millis();
    lastMillisL1 = millis();
    lastMillisD = millis();
    sendCmdAll(CMD_INTENSITY, 1);
  }
  if (adcVal < 450 && adcVal > 250 && millis()-lastMillisL1 > 10000)
  {
    lastMillisL = millis();
    lastMillisD1 = millis();
    lastMillisD = millis();
    sendCmdAll(CMD_INTENSITY, 2);
  }
  if (adcVal < 250 && millis()-lastMillisL > 10000)
  {
    lastMillisD=millis();
    lastMillisD1 = millis();
    lastMillisL1 = millis();
    sendCmdAll(CMD_INTENSITY, 3);
  }


  refreshAll();

 cnt++;
 while (millis() - startTime < 25);

  //-----------------------------------------IR Code

  if (dpir.available() != 0)
  {
    dpir.getCode(IRcode);
    flagHMS = 1;
    for (int i = 0; i < 6; i++) if (IRcode[i] != H[i] && IRcode[i] != M[i] && IRcode[i] != S[i]) flagHMS = 0;

    if (flagHMS == 1) {
      for (int i = 0; i < 6; i++) if (IRcode[i] != H[i]) flagH = 0;

      if (flagH == 1) {
        clr();
        showDigit(0, 0, Sati);
        showDigit(1, 6, Sati);
        showDigit(2, 11, Sati);
        showDigit(3, 16, Sati);
        setCol(19, 1 ? 0x24 : 0);

        showDigit(0, 27, dig5x8rn);
        refreshAll();
      }

      while (flagH == 1)
      {
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

            updateTime();
            if (hour > 23) {
              hour = 0;
              tmp_number = 0;
            }

            h1 = hour / 10;
            h0 = hour % 10;

            if (h1 > 0) showDigit(h1, 21, dig5x8rn);
            showDigit(h0, 27, dig5x8rn);
            refreshAll();
          }
        }
      }

      for (int i = 0; i < 6; i++) if (IRcode[i] != M[i]) flagM = 0;

      if (flagM == 1) {
        clr();
        showDigit(0, 0, Minute);
        showDigit(1, 6, Minute);
        showDigit(2, 11, Minute);
        setCol(17, 1 ? 0x24 : 0);

        showDigit(0, 27, dig5x8rn);
        refreshAll();
      }

      while (flagM == 1)
      {
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

            updateTime();
            if (minute > 60) {
              minute = 0;
              tmp_number = 0;
            }

            m1 = minute / 10;
            m0 = minute % 10;

            if (m1 > 0) showDigit(m1, 21, dig5x8rn);
            showDigit(m0, 27, dig5x8rn);
            refreshAll();
          }
        }
      }

      for (int i = 0; i < 6; i++) if (IRcode[i] != S[i]) flagS = 0;

      if (flagS == 1) {
        clr();
        showDigit(0, 0, Sekunde);
        showDigit(1, 6, Sekunde);
        showDigit(2, 11, Sekunde);
        setCol(17, 1 ? 0x24 : 0);

        showDigit(0, 27, dig5x8rn);
        refreshAll();
      }

      while (flagS == 1)
      {
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

            updateTime();
            if (second > 60) {
              second = 0;
              tmp_number = 0;
            }

            s1 = second / 10;
            s0 = second % 10;

            if (s1 > 0) showDigit(s1, 21, dig5x8rn);
            showDigit(s0, 27, dig5x8rn);
            refreshAll();
          }
        }
      }

      flagH = 1;
      flagM = 1;
      flagS = 1;
      tmp_number = 0;
    }
  }
  //-----------------------------------------
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
void showDate()
{
 if(d1) showDigit(d1, 0, dig3x8);
  showDigit(d0, 4, dig3x8);
  if(mn1) {
  showDigit(mn1, 9, dig3x8);
  showDigit(mn0, 12, dig3x8);
  setCol(16,0x80);
  }
  else {
    showDigit(mn0, 11, dig3x8);
    setCol(15,0x80);
  }
  showDigit(2, 18, dig3x8);
  showDigit(0, 22, dig3x8);
  showDigit(y1, 26, dig3x8);
  showDigit(y0, 29, dig3x8);
  setCol(8, 0x80);
}
void showTemp()
{

  if (temp > 0 && temp < 99) {
    int t1 = (int)temp / 10;
    int t0 = (int)temp % 10;
    int tf = (temp - int(temp)) * 10.0;
    if (t1) showDigit(t1, 2, dig5x8sq);
    showDigit(t0, 8, dig5x8sq);
    showDigit(tf, 16, dig5x8sq);
  }
  setCol(14, 0x80);
  showDigit(7, 22, dweek_pl);
}


// 4+1+4+3+4+1+4=21 + 3+1+3
void showClock()
{
  if (h1 > 0) showDigit(h1, h1 == 2 ? 0 : 1, dig4x8);
  showDigit(h0, 5, dig4x8);
  showDigit(m1, 12, dig4x8);
  showDigit(m0, 17, dig4x8);
  showDigit(s1, 24, dig3x6);
  showDigit(s0, 28, dig3x6);
  setCol(10, dots ? 0x24 : 0);
}

//6+2+6+3+6+2+6 = 31
void showClockBig()
{
  if (h1 > 0) showDigit(h1, h1 == 2 ? 1 : 2, dig6x8);
  showDigit(h0, 8, dig6x8);
  showDigit(m1, 17, dig6x8);
  showDigit(m0, 24, dig6x8);
  setCol(15, dots ? 0x24 : 0);
}

// 5+1+5+3+5+1+5+ 1+3+1+3=33
void showClockMed()
{
  if (h1 > 0) showDigit(h1, 0, dig5x8rn);
  showDigit(h0, h1 == 2 ? 6 : 5, dig5x8rn);
  showDigit(m1, 13, dig5x8rn);
  showDigit(m0, m1 == 1 ? 18 : 19, dig5x8rn);
  showDigit(s1, 25, dig3x6);
  showDigit(s0, 29, dig3x6);
  setCol((hour == 20) ? 12 : 11, dots ? 0x24 : 0);
}


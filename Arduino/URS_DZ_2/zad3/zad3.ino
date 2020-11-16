#include <OneWire.h>
OneWire  ds(10);

int LastMillis,LastMillis2,ledState=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  LastMillis=millis();
  LastMillis2=millis();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(millis()-LastMillis>200)
  {
   ledState = (ledState+1)%2;
   digitalWrite(13,ledState);


   LastMillis=millis();
  }

  ds.reset();
  ds.write(0xCC);   
  ds.write(0x44);

  if (millis() - LastMillis2 > 1000)
  {
    ds.reset();
    ds.write(0xCC);  
    ds.write(0xBE);

    byte dsData[9];

  for(int i = 0;i<9;i++)
  {
      dsData[i] = ds.read();
      Serial.print(dsData[i], HEX);
      Serial.print(" ");
  }
  Serial.println();

  int16_t intTemp=0x0000;
  intTemp = dsData[1];
  intTemp = intTemp<<8;
  intTemp = intTemp | dsData[0];
  float floatTemp = intTemp;
  floatTemp = floatTemp/16;
  
  Serial.print(floatTemp,2);
  Serial.print("\n");

    LastMillis2=millis();
  }
      

  
}

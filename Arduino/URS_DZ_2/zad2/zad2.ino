#include <OneWire.h>
OneWire  ds(10);

byte address[8];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ds.reset();
  ds.write(0x33);  

  delay(1000);      // treba mu barem 750ms

   

    for(int i = 0;i<8;i++)
    {
        address[i] = ds.read();
        Serial.print(address[i], HEX);
        Serial.print(" ");
    }
    Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

  ds.reset();
  ds.write(0x55);
  for(int i=0;i<8;i++) ds.write(address[i]);   
  ds.write(0x44);
   
   delay(1000);      

  ds.reset();
  ds.write(0x55);
  for(int i=0;i<8;i++) ds.write(address[i]);   
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
}

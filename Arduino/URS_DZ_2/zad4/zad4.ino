#include <OneWire.h>
#define STR 7
#define DATA 6
#define CLK 5
OneWire  ds(10);

byte num[11] = {0b11100111,0b10000100,0b11010011,0b11010110,0b10110100,0b01110110,0b01110111,0b11000100,0b11110111,0b11110110,0b00001000};


void writeCD4094_High(byte n)
{
  byte bitmask = 0x80;
  
  digitalWrite(STR,LOW);
  while(bitmask)
   {
      
      if(bitmask & num[n]) digitalWrite(DATA, LOW);
        else digitalWrite(DATA, HIGH);
      digitalWrite(CLK,HIGH);
      delay(20);
      digitalWrite(CLK,LOW);
      delay(20);
      bitmask=bitmask>>1;
   }
digitalWrite(STR,HIGH);
delay(2);
digitalWrite(STR,LOW);
delay(2);
}

void setup() {
  // put your setup code here, to run once:
    digitalWrite(CLK, LOW);
  digitalWrite(DATA, LOW);
  digitalWrite(STR, LOW);

  pinMode(STR, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CLK, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


  ds.reset();
  ds.write(0xCC);   
  ds.write(0x44);

  delay(1000);

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
  
  int i=floatTemp*10;

  writeCD4094_High(i/100);
  delay(500);
  writeCD4094_High((i/10)%10);
  delay(500);
  writeCD4094_High(10);
  delay(500);
  writeCD4094_High(i%10);
  delay(1500); 

  
}

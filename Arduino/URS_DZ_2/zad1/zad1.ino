#include <OneWire.h>
OneWire  ds(10);

byte address[8];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
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

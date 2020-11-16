#define segA A1
#define segB A0
#define segC 6
#define segD 5
#define segE 4
#define segF A2
#define segG A3
#define segDP 7
#define button 2

int i,j=10,stanje=0,dil=200,k,del=300;

byte tipkalo_zadnje_stanje=1;
byte ledStatus=0;
byte ledState;
unsigned long lastMillis;

void setup() {
pinMode(segA,OUTPUT);
pinMode(segB,OUTPUT);
pinMode(segC,OUTPUT);
pinMode(segD,OUTPUT);
pinMode(segE,OUTPUT);
pinMode(segF,OUTPUT);
pinMode(segG,OUTPUT);
pinMode(segDP,OUTPUT);
pinMode(button,INPUT_PULLUP);

randomSeed(analogRead(A0));
//attachInterrupt(digitalPinToInterrupt(button), changeLED, FALLING);
Serial.begin(9600);
lastMillis = millis();
}

byte segPinTable[8] = {segA, segB, segC, segD, segE, segF, segG, segDP};

void allOFF()
{
for(int i = 0;i<8; i++) digitalWrite(segPinTable[i],HIGH);
}

byte segTable[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

void displayWrite(int n)
{
allOFF();
byte bitmask = 0b00000001;
for(int i = 0;i<8; i++)
{
if(segTable[n] & bitmask) digitalWrite(segPinTable[i],LOW);
bitmask = bitmask << 1;
}
}

void loop() {

for(k=1;k<10;k++)
{
  lastMillis = millis();
while(millis()-lastMillis < del)
  {
    if( digitalRead(button) == 0 && tipkalo_zadnje_stanje == 1)
  {
    tipkalo_zadnje_stanje = 0;
    if(del!=25) del=del-25;
    Serial.println(del);
    delay(20);
  }
  
   if( digitalRead(button) == 1 && tipkalo_zadnje_stanje == 0)
   {
     tipkalo_zadnje_stanje = 1;
   }
   displayWrite(k);
  }
  allOFF();
}

}

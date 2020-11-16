#define segA A1
#define segB A0
#define segC 6
#define segD 5
#define segE 4
#define segF A2
#define segG A3
#define segDP 7
#define button 2

int i;

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

if(digitalRead(button)==0)
{  
allOFF();
delay(200);
i=random(1,7);
displayWrite(i);
}



}

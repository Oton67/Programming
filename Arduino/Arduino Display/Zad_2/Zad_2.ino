#define segA A1
#define segB A0
#define segC 6
#define segD 5
#define segE 4
#define segF A2
#define segG A3
#define segDP 7
#define button 2

int i,j=10,stanje=0,dil=200,k;

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


if(stanje== 0)
{
for(k=5;k<j;k++)
{
displayWrite(k);

for(int i=0;i<dil;i++) 
{
if( digitalRead(button) == 0)
{
stanje=1;
j=1;
dil=1;
}
delay(10);
}
allOFF();
}
}

if(stanje==1 && digitalRead(button)==0)
{
  
allOFF();

delay(200);
i=random(1,k);
displayWrite(i);

}



}

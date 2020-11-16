#define segA A1
#define segB A0
#define segC 6
#define segD 5
#define segE 4
#define segF A2
#define segG A3
#define segDP 7
#define button 2

unsigned long Millis1;
unsigned long Millis2;
byte bitmask = 0b00000001;
volatile unsigned long timer1_millis=0;

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

Serial.begin(9600);  


cli();
TCCR1A = 0;
TCNT1 = 0;
TCCR1B = 0b00011001;
ICR1 = 15999; 
OCR1A = 0;
TIMSK1 = 0b00000010;
sei();
}
byte segPinTable[8] = {segA, segB, segC, segD, segE, segF, segG, segDP};

void allOFF()
{
for(int i = 0;i<8; i++) digitalWrite(segPinTable[i],HIGH);
}

byte segTable[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};


ISR(TIMER1_COMPA_vect)
{
  timer1_millis++;
}

void displayWrite(int n)
{
  Millis2=millis();
while(millis()-Millis2 <= 500)
{
allOFF();
bitmask = 0b00000001;

for(int i = 0;i<8; i++)
{
 
if(segTable[n] & bitmask)
{ 
  
Millis1 = millis();
while(millis()-Millis1 <= 1)
{
digitalWrite(segPinTable[i],LOW);
} 

}                        
allOFF();                           
bitmask = bitmask << 1;
}
}
}   

void loop() {
  
for(int i=0;i<10;i++){
displayWrite(i);
}

}

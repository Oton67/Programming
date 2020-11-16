// binarno brojilo

#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15
#define button A2


int CLK = 5; // 5 = PD5
int LOAD = 6; // 6 = PD6
int DIN = 7; // 7 = PD7


byte znak[6][8] =
{ {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0xC3, 0xC3, 0x00, 0x00, 0x00},
  {0xC0, 0xC0, 0x00, 0x18, 0x18, 0x00, 0x03, 0x03},
  {0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xC3},
  {0xC3, 0xC3, 0x00, 0x18, 0x18, 0x00, 0xC3, 0xC3},
  {0xC3, 0xC3, 0x00, 0xC3, 0xC3, 0x00, 0xC3, 0xC3}
};


void sendData( byte address, byte data)
{
  byte packet[2];
  byte bitmask;
  byte i;
  packet[0] = address;
  packet[1] = data;

  for (i = 0; i < 2; i++)
    for ( bitmask = 0x80 ; bitmask != 0 ; bitmask = bitmask >> 1 )
    {
      if (bitmask & packet[i]) digitalWrite(DIN, 1);
      else digitalWrite(DIN, 0);

      digitalWrite(CLK, HIGH);
      digitalWrite(CLK, LOW);
    }
  digitalWrite(LOAD, HIGH);
  digitalWrite(LOAD, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LOAD, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(LOAD, LOW);

  randomSeed(analogRead(0));

  Serial.begin(9600);


  sendData(OP_DISPLAYTEST, 0);
  sendData(OP_INTENSITY, 0);
  sendData(OP_SCANLIMIT, 7);

  sendData(OP_DECODEMODE, 0);
  sendData(OP_SHUTDOWN, 1);
  for (int i = 0; i < 8; i++) sendData(i + 1, 0b00000000);


}

void loop() {
  // put your main code here, to run repeatedly:
  


    if (digitalRead(button) == 0)
    {
      byte neki_znak = random()%6;
      for (int i = 0; i < 8; i++)
      {
        sendData(i + 1, znak[neki_znak][i]);
      }
   delay(50);
      
    }

  
    
 


}






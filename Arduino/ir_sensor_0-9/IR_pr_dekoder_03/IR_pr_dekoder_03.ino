#define IRpin 2
#define segA A2
#define segB A1
#define segC 6
#define segD 5
#define segE 4
#define segF A3
#define segG A4
#define segDP 7

unsigned long micros1;
unsigned long micros2;
unsigned long micros3;
int last4[4]={0,0,0,0},flag=0;


byte segToPin[8]={segA,segB,segC,segD,segE,segF,segG,segDP};
byte segTable[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

byte g0[4]={0xF4,0x54,0x14,0x54};
byte g1[4]={0xE1,0x00,0x01,0x00};
byte g2[4]={0xF5,0x00,0x15,0x00};
byte g3[4]={0xE4,0x00,0x04,0x00};
byte g4[4]={0xE0,0x10,0x00,0x10};
byte g5[4]={0xF4,0x10,0x14,0x10};
byte g6[4]={0xE5,0x10,0x05,0x10};
byte g7[4]={0xE1,0x50,0x01,0x50};
byte g8[4]={0xF5,0x50,0x15,0x50};
byte g9[4]={0xE4,0x50,0x04,0x50};
byte OFF[4]={0xE5,0x40,0x05,0x40};

byte IRkod[4]={0,0,0,0};
byte bitmask;
byte numberCode[4] = {0,0,0,0};

void setup() {
  pinMode(IRpin,INPUT);
  pinMode(segA,OUTPUT);
  pinMode(segB,OUTPUT);
  pinMode(segC,OUTPUT);
  pinMode(segD,OUTPUT);
  pinMode(segE,OUTPUT);
  pinMode(segF,OUTPUT);
  pinMode(segG,OUTPUT);
  pinMode(segDP,OUTPUT);

  
  Serial.begin(57600); // slanje 1 bajta traje 10*

allOFF();
}

void allOFF()
{
   for(int i = 0;i<8; i++) digitalWrite(segToPin[i],HIGH);
}


void displayWrite(int n)
{
  allOFF();
  byte bitmask = 0b00000001;
  for(int i = 0;i<8; i++)
  {
     if(segTable[n] & bitmask) digitalWrite(segToPin[i],LOW);
     bitmask = bitmask << 1;
  }
}

void loop() {
   // nema IR signala
   int i=0;
   for(i=0;i<4;i++) IRkod[i]=0;
   for(i=0;i<4;i++) last4[i]=0;
   int j=0;
   bitmask = 0x80;
   i=0;
   
   while( digitalRead(IRpin) == 1 ) ;
  
   // IR signal prisutan

   micros1 = micros();
      do
      {
         // petlja se vrti dok imamo IR signal
         while( digitalRead(IRpin) == 0 ) ; 

         micros2 = micros(); // signal je završio, spremi vrijeme

         // pošalji koliko je trajao PULS
         last4[i]=micros2-micros1;
         i++;

         // paziti last4 treba biti signed inače se može desiti npr. rezltat tipa 0-1=255 a ne -1
         if( abs(last4[0]-last4[2])>200 ) IRkod[j] = IRkod[j] ^ bitmask; 
         bitmask=bitmask>>1;
         
         // nema signala
         micros3 = micros2;
         
         // čekamo novi signal ili timeout
         while( digitalRead(IRpin) == 1 && (micros3-micros2)<10000) micros3 = micros(); 
         // novi IR signal
         
         micros1=micros3;
         last4[i]=micros3-micros2;
         i++;
         if(i==4) i=0;
         
         
         if( abs(last4[1]-last4[3])>200 ) IRkod[j] = IRkod[j] ^ bitmask;
         bitmask=bitmask>>1;
         
         if(bitmask==0)
         {
            bitmask=0x80;
            j++;
            if(j==4) j=0;
         }
        } while(micros3-micros2<10000);





for(i=0;i<4;i++)
{
 if(IRkod[i]!=g0[i]) flag=1;
}
if(flag==0)displayWrite(0);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g1[i]) flag=1;
}
if(flag==0)displayWrite(1);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g2[i]) flag=1;
}
if(flag==0)displayWrite(2);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g3[i]) flag=1;
}
if(flag==0)displayWrite(3);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g4[i]) flag=1;
}
if(flag==0)displayWrite(4);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g5[i]) flag=1;
}
if(flag==0)displayWrite(5);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g6[i]) flag=1;
}
if(flag==0)displayWrite(6);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g7[i]) flag=1;
}
if(flag==0)displayWrite(7);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g8[i]) flag=1;
}
if(flag==0)displayWrite(8);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=g9[i]) flag=1;
}
if(flag==0)displayWrite(9);
flag=0;

for(i=0;i<4;i++)
{
 if(IRkod[i]!=OFF[i]) flag=1;
}
if(flag==0) allOFF();
flag=0;

      for(int i = 0;i<4;i++)
      {
       Serial.print(IRkod[i],HEX);  
       Serial.print(" ");  
      }

      Serial.println("--------------");


}


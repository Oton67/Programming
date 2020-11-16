#define crveno 3
#define zuto 4
#define zeleno 5

#define tipkaloLijevo 8
#define tipkaloDesno 9

byte ledStatusL=0;
byte ledStatusD=0;

unsigned long lastMillisL;
unsigned long lastMillisD;

byte tipkalo_zadnje_stanje_L=1;
byte tipkalo_zadnje_stanje_D=1;

int i=0,br=0;

void setup() {
  
pinMode(crveno, OUTPUT);
pinMode(zeleno, OUTPUT);
pinMode(zuto, OUTPUT);
  
pinMode(tipkaloLijevo, INPUT_PULLUP);
pinMode(tipkaloDesno, INPUT_PULLUP);
  
Serial.begin(9600);  
  
lastMillisL= millis();
lastMillisD= millis();
}

void loop() {

if( digitalRead(tipkaloLijevo) == 0 && tipkalo_zadnje_stanje_L == 1)
  {
    ledStatusL=(ledStatusL+1)%2; 
    tipkalo_zadnje_stanje_L = 0;
  }
  
if( digitalRead(tipkaloLijevo) == 1 && tipkalo_zadnje_stanje_L == 0)
   {
     tipkalo_zadnje_stanje_L = 1;
   } 

if(ledStatusL==1)
{                                         
if(millis()-lastMillisL<500) digitalWrite(crveno,HIGH);
else digitalWrite(crveno,LOW);

if(millis()-lastMillisL>=1000) lastMillisL=millis();    
}
if(ledStatusL==0) digitalWrite(crveno, LOW);


  
if( digitalRead(tipkaloDesno) == 0 && tipkalo_zadnje_stanje_D == 1)
  {
    ledStatusD=(ledStatusD+1)%2; 
    tipkalo_zadnje_stanje_D = 0;
  }
  
if( digitalRead(tipkaloDesno) == 1 && tipkalo_zadnje_stanje_D == 0)
   {
     tipkalo_zadnje_stanje_D = 1;
   }

if(ledStatusD==1)
{             
if(millis()-lastMillisD<500) digitalWrite(zeleno,HIGH); 
else digitalWrite(zeleno,LOW);

if(millis()-lastMillisD>=1000) lastMillisD=millis(); 
}
if(ledStatusD==0) digitalWrite(zeleno, LOW);

}

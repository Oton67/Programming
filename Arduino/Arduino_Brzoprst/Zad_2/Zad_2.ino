/* vježba 04d */
#define crveno 3
#define zuto 4
#define zeleno 5
#define tipkalo 8

byte tipkalo_zadnje_stanje=1;
byte ledStatus=0;
byte ledState;

int k=0,i;
unsigned long lastMillis;

void setup() {
pinMode(tipkalo, INPUT_PULLUP);
pinMode(crveno, OUTPUT);
pinMode(zuto, OUTPUT);
pinMode(zeleno, OUTPUT);

Serial.begin(9600);  

lastMillis = millis();
ledState=0;
}

void loop()
{
   
  while(millis()-lastMillis < 5000)
  {
   digitalWrite(crveno,HIGH); 
  }
  lastMillis=millis();

  
  while(millis()-lastMillis < 2000)
  {
   digitalWrite(zuto,HIGH); 
  }
  lastMillis=millis();
  digitalWrite(crveno,LOW);
  digitalWrite(zuto,LOW);


  while(millis()-lastMillis < 5000)
  {
    if( digitalRead(tipkalo) == 0 && tipkalo_zadnje_stanje == 1)
  {
    ledStatus=(ledStatus+1)%2; 
    tipkalo_zadnje_stanje = 0;
  }
  
   if( digitalRead(tipkalo) == 1 && tipkalo_zadnje_stanje == 0)
   {
     tipkalo_zadnje_stanje = 1;
   }
   
   digitalWrite(zeleno,HIGH); 
   if(ledStatus==1) break;
  }
  lastMillis=millis();


  for(i=0;i<5;i++)
  {
   while(millis()-lastMillis < 500)
  {
   if(i%2==0)digitalWrite(zuto,HIGH); 
   if(i%2==1)digitalWrite(zuto,LOW);
  } 
  lastMillis=millis();
  }
  digitalWrite(zeleno,LOW);
  digitalWrite(zuto,LOW);
}

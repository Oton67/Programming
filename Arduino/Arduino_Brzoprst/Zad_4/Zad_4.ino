/* vježba 04d */
#define crveno 3
#define zuto 4
#define zeleno 5
#define tipkalo 8

byte tipkalo_zadnje_stanje=1;
byte ledStatus=0;
byte ledState;

int k=0,i,dil=500;
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
   
  while(millis()-lastMillis < dil)
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
   
   if(ledStatus==1) {
    
    Serial.print("Dosli ste do:");
    Serial.println(dil);
    Serial.print("Igrali ste:");
    Serial.println(millis()/1000);
    
   while(1)
   {
    digitalWrite(zuto,HIGH); 
    digitalWrite(zeleno,HIGH); 
    digitalWrite(crveno,HIGH);
   }
   }
  }
  
  lastMillis=millis();
  digitalWrite(zeleno,LOW);

  
  while(millis()-lastMillis < dil)
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
   
   digitalWrite(zuto,HIGH);
   
   if(ledStatus==1) {
    
    Serial.print("Dosli ste do:");
    Serial.println(dil);
    Serial.print("Igrali ste:");
    Serial.println(millis()/1000);
    
   while(1)
   {
    digitalWrite(zuto,HIGH); 
    digitalWrite(zeleno,HIGH); 
    digitalWrite(crveno,HIGH);
   }
   }
  }
  
  lastMillis=millis();
  digitalWrite(zuto,LOW);


  while(millis()-lastMillis < dil)
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
   
   digitalWrite(crveno,HIGH); 
   if(ledStatus==1) dil=dil-10;
   ledStatus=0;

   if(dil==0)
   {
    Serial.print("Pobjedili ste igru!!!");
    while(1)
    {
    digitalWrite(zuto,HIGH); 
    digitalWrite(zuto,LOW); 
    digitalWrite(zeleno,HIGH); 
    digitalWrite(zeleno,LOW); 
    digitalWrite(crveno,HIGH);
    digitalWrite(crveno,LOW); 
    }
   }
   
   
  }
  lastMillis=millis();
  digitalWrite(crveno,LOW);

 
}

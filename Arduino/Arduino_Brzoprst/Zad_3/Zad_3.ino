/* vježba 03f */
#define crveno 3
#define zuto 4
#define zeleno 5

#define tipkalo 8

byte ledStatus=0;
byte tipkalo_zadnje_stanje=1;
int i,up=100,ug=0,z=0;
void setup() {
  // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(tipkalo, INPUT_PULLUP);
 
  Serial.begin(9600);  
  i=0;
}

void loop() {
  
  digitalWrite(crveno,HIGH);       
  delayMicroseconds(up);       
  digitalWrite(crveno,LOW);       
  delayMicroseconds(ug);
  
  if( digitalRead(tipkalo) == 0 && tipkalo_zadnje_stanje == 1)
  {
    ledStatus=(ledStatus+1)%2; 
    tipkalo_zadnje_stanje = 0;
  
    if(z==0)
    {
    up=up-10;
    ug=ug+10;
    }
    else
    {
     up=up+10;
     ug=ug-10;
     }
     if(up==10) z=1;
    if(up==100) z=0;
  }
  
   if( digitalRead(tipkalo) == 1 && tipkalo_zadnje_stanje == 0)
   {
     tipkalo_zadnje_stanje = 1;

    
   }
  
   
  
}



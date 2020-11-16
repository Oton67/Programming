#define crveno 3
#define zuto 4
#define zeleno 5
#define tipkalo 8

byte ledStatus=0;
byte tipkalo_zadnje_stanje=1;
int i;

void setup() {
 // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(zuto, OUTPUT);
 pinMode(zeleno, OUTPUT);

 pinMode(tipkalo, INPUT_PULLUP);
 Serial.begin(9600);

}
void loop() {
 // put your main code here, to run repeatedly:
 

 for(int i=0;i<=7;i++)
 {
   if(ledStatus==0)
   {
       if(i & 0x01) digitalWrite(zeleno, HIGH);
       else digitalWrite(zeleno, LOW);
      
       if(i & 0x02) digitalWrite(zuto, HIGH);
       else digitalWrite(zuto, LOW);
      
       if(i & 0x04) digitalWrite(crveno, HIGH);
       else digitalWrite(crveno, LOW);
   
   }
  
   if(i%2==1) delay(30);
   
  if( digitalRead(tipkalo) == 0 && tipkalo_zadnje_stanje == 1)
 {
 ledStatus=(ledStatus+1)%2;
 tipkalo_zadnje_stanje = 0;
 }

 if( digitalRead(tipkalo) == 1 && tipkalo_zadnje_stanje == 0)
 {
 tipkalo_zadnje_stanje = 1;
 } 
 
}

 }


 



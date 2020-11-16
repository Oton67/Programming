#define crveno 3
#define zuto 4
#define zeleno 5
#define tipkalo 8

byte ledStatus=0;
byte tipkalo_zadnje_stanje=1;
int i,pritisak=1;

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
 
 if(ledStatus==1 && pritisak==1){ 
  digitalWrite(crveno, HIGH);
  pritisak=2;
 }
  if(ledStatus==0 && pritisak==2){ 
  digitalWrite(crveno, LOW);  
  digitalWrite(zuto, HIGH);
  pritisak=3;
 }
 if(ledStatus==1 && pritisak==3){ 
  digitalWrite(zuto, LOW);  
  digitalWrite(zeleno, HIGH);
  pritisak=4;
 }
 if(ledStatus==0 && pritisak==4){ 
  digitalWrite(zeleno, LOW);  
  pritisak=1;
 }
   
  if( digitalRead(tipkalo) == 0 && tipkalo_zadnje_stanje == 1)
 {
 ledStatus=(ledStatus+1)%2;
 tipkalo_zadnje_stanje = 0;
 }

 if( digitalRead(tipkalo) == 1 && tipkalo_zadnje_stanje == 0)
 {
 tipkalo_zadnje_stanje = 1;
 } 
 Serial.println(i);

 }

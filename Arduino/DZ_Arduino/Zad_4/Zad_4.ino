#define crveno 3
#define zuto 4
#define zeleno 5
#define tipkalo 8

byte ledStatus=0;
byte tipkalo_zadnje_stanje=1;
int i,p=10,t1,t2,t3,k=0;

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
 
if(p>=200 && ledStatus==0) 
{
t1=0;
t2=0;
t3=0;
p=10;
k=0;
  digitalWrite(zeleno, LOW);
  digitalWrite(zuto, LOW);
  digitalWrite(crveno, LOW);
}

 for(int i=0;i<=7 && p!=200 ;i++)
 {

  if(ledStatus==1 && k==0)
  {
    if(i & 0x01) t1=1;
    if(i & 0x02) t2=1;
    if(i & 0x04) t3=1;
    k=1;
  }
   
       if(i & 0x01)
       { 
       if(t1==1) p=p+10;
       digitalWrite(zeleno, HIGH);
       }
       else digitalWrite(zeleno, LOW);
       
       if(i & 0x02)
       { 
       if(t2==1) p=p+10; 
       digitalWrite(zuto, HIGH);
       }
       else digitalWrite(zuto, LOW);
       
       if(i & 0x04) 
       {
       if(t3==1) p=p+10;
       digitalWrite(crveno, HIGH);
       }
       else digitalWrite(crveno, LOW);
   
   
   
   if(i%2==1) delay(p);
   if(i==7) i=0;

   
   if(p>=200 && ledStatus==1)
{
  digitalWrite(zeleno, LOW);
  digitalWrite(zuto, LOW);
  digitalWrite(crveno, LOW);
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
 
}
 

if(p>=200 && ledStatus==1)
{
  if(t1==1) digitalWrite(zeleno, HIGH);
  if(t2==1) digitalWrite(zuto, HIGH);
  if(t3==1) digitalWrite(crveno, HIGH);
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
 

 }


 



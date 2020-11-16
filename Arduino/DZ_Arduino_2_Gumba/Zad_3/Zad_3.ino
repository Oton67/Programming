#define crveno 3
#define zuto 4
#define zeleno 5

#define tipkaloLijevo 8
#define tipkaloDesno 9

int i=0,leftNumber,rightNumber,logicalSymbol;

unsigned long bMillis;
 

void setup() {
  // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(zuto, OUTPUT);
 pinMode(zeleno, OUTPUT);
 pinMode(tipkaloLijevo, INPUT_PULLUP);
 pinMode(tipkaloDesno, INPUT_PULLUP);

bMillis=millis();

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

while(digitalRead(tipkaloLijevo)==1); // čeka da se stisne tipka
bMillis=millis();
while(millis()-bMillis<60000)
{

randomSeed(micros());
leftNumber=random(10); // slučajni broj od 0 do 9
rightNumber=random(10); // slučajni broj od 0 do 9
logicalSymbol=random(3);// slučajni od 0 do 2 (0 je <, 1 je >, == je 2


if(logicalSymbol==0)
{
 delay(300);
 Serial.print(leftNumber); 
 Serial.print("<"); 
 Serial.print(rightNumber); 
 Serial.print("\n");

 while(1)
 {
   if(leftNumber < rightNumber && digitalRead(tipkaloLijevo)==0) 
   {    
    i++;
   Serial.print("T");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   if(leftNumber == rightNumber || leftNumber > rightNumber && digitalRead(tipkaloLijevo)==0)
   {
    i=i-5;
   Serial.print("N");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }

   if(leftNumber < rightNumber && digitalRead(tipkaloDesno)==0) 
   {
    i=i-5;
   Serial.print("N");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   if(leftNumber == rightNumber || leftNumber > rightNumber && digitalRead(tipkaloDesno)==0)
   {
    i++;
   Serial.print("T");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   
 }
 
}

if(logicalSymbol==1)
{
  delay(300);
 Serial.print(leftNumber); 
 Serial.print(">"); 
 Serial.print(rightNumber); 
 Serial.print("\n");

  while(1)
 {
   if(leftNumber > rightNumber && digitalRead(tipkaloLijevo)==0) 
   {
    i++;
   Serial.print("T");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   if(leftNumber == rightNumber || leftNumber < rightNumber && digitalRead(tipkaloLijevo)==0)
   {
    i=i-5;
   Serial.print("N");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }

   if(leftNumber > rightNumber && digitalRead(tipkaloDesno)==0) 
   {
    i=i-5;
   Serial.print("N");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   if(leftNumber == rightNumber || leftNumber < rightNumber && digitalRead(tipkaloDesno)==0)
   {
    i++;
   Serial.print("T");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
 }
 
}

if(logicalSymbol==2)
{
  delay(300);
 Serial.print(leftNumber); 
 Serial.print("="); 
 Serial.print(rightNumber); 
 Serial.print("\n");

  while(1)
 {
   if(leftNumber == rightNumber && digitalRead(tipkaloLijevo)==0) 
   {
    i++;
   Serial.print("T");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   if(leftNumber < rightNumber || leftNumber > rightNumber && digitalRead(tipkaloLijevo)==0)
   {
    i=i-5;
   Serial.print("N");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }

   if(leftNumber == rightNumber && digitalRead(tipkaloDesno)==0) 
   {
    i=i-5;
   Serial.print("N");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
   if(leftNumber < rightNumber || leftNumber > rightNumber && digitalRead(tipkaloDesno)==0)
   {
    i++;
   Serial.print("T");
   Serial.print("\n");
   Serial.print("B: ");
   Serial.print(i);
   Serial.print("\n""\n");
   break;
   }
 }
 
}

}
}

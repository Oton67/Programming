/* vježba 05g */
#define crveno 3
#define zuto 4
#define zeleno 5

#define tipkaloLijevo 8
#define tipkaloDesno 9

byte tipkaloLijevo_pStanje=1;
byte tipkaloDesno_pStanje=1;
byte code[4]={2,0,1,6};
byte typedCode[4]={0,0,0,0};

int i=0,j=0,k,flag=1;

void setup() {
  // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(zuto, OUTPUT);
 pinMode(zeleno, OUTPUT);
 
 pinMode(tipkaloLijevo, INPUT_PULLUP);
 pinMode(tipkaloDesno, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 
  if(digitalRead(tipkaloDesno)==0)
  {
    delay(300);
    i++;
    if(i>7)
    {
      i=0;
    }
  }
  if(digitalRead(tipkaloLijevo)==0)
  {
    delay(300);
    typedCode[j]=i;
    
   

    if(typedCode[j]!=code[j])
    {
      j=0;
      i=0;
    }
    else
    {
    j++;
    i=0;
    }
    
    if(j==4)  while(1)
     {
      digitalWrite(zeleno, LOW);
      digitalWrite(zuto, LOW);
      digitalWrite(crveno, HIGH);
      delay(300);
      digitalWrite(crveno, LOW);
      delay(300);
     }

  }
    if(i & 0x01) digitalWrite(zeleno, HIGH);
     else digitalWrite(zeleno, LOW);
    
    if(i & 0x02) digitalWrite(zuto, HIGH);
     else digitalWrite(zuto, LOW);
    
    if(i & 0x04) digitalWrite(crveno, HIGH);
     else digitalWrite(crveno, LOW);
 
    
}

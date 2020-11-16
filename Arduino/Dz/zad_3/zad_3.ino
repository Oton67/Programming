/* vježba 02d */
#define crveno 3
#define zuto 4
#define zeleno 5


void setup() {
  // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(zuto, OUTPUT);
 pinMode(zeleno, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i=7;i>=0;i--)
  {
    if(i & 0x01) digitalWrite(zeleno, HIGH);
     else digitalWrite(zeleno, LOW);
    
    if(i & 0x02) digitalWrite(zuto, HIGH);
     else digitalWrite(zuto, LOW);
    
    if(i & 0x04) digitalWrite(crveno, HIGH);
     else digitalWrite(crveno, LOW);
    
    delay(500);
    
  }
}

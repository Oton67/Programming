
/* vjezba 02a */
#define crveno 3
#define zuto 4
#define zeleno 5
int b=500;

void setup() {
  // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(zuto, OUTPUT);
 pinMode(zeleno, OUTPUT);
  
}

void loop() {
  
  digitalWrite(crveno, HIGH);
  delay(b);
  digitalWrite(crveno, LOW);
  
  digitalWrite(zuto, HIGH);
  delay(b);
  digitalWrite(zuto, LOW);
  
  digitalWrite(zeleno, HIGH);
  delay(b);
  digitalWrite(zeleno, LOW);

  digitalWrite(zuto, HIGH);
  delay(b);
  digitalWrite(zuto, LOW);

  b=b-10;
  if(b==40)b=500;
}


/* vjezba 02a */
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
  digitalWrite(crveno, HIGH);
  delay(500);
  digitalWrite(crveno, LOW);
  
  digitalWrite(zuto, HIGH);
  delay(500);
  digitalWrite(zuto, LOW);
  
  digitalWrite(zeleno, HIGH);
  delay(500);
  digitalWrite(zeleno, LOW);

  digitalWrite(zuto, HIGH);
  delay(500);
  digitalWrite(zuto, LOW);


}

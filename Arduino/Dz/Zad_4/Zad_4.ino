
#define crveno 3
#define zuto 4
#define zeleno 5

int A[6]={5,6,2,4,6,3};

void setup() {
  // put your setup code here, to run once:
 pinMode(crveno, OUTPUT);
 pinMode(zuto, OUTPUT);
 pinMode(zeleno, OUTPUT);
}

void loop() {
 
for(int i=0;i<3;i++)
  {
  digitalWrite(zeleno, HIGH);
  delay(A[i*2]*1000);
 
  for(int j=0;j<3;j++)
  {
    digitalWrite(zuto, HIGH);
    delay(500);
    digitalWrite(zuto, LOW);
    if(j != 2) delay(500);
  }
  digitalWrite(zeleno, LOW);

  digitalWrite(crveno, HIGH);
  delay(A[i*2+1]*1000);
  
  digitalWrite(zuto, HIGH);
  delay(500);
  
  digitalWrite(crveno, LOW);
  digitalWrite(zuto, LOW);
  }
  
}

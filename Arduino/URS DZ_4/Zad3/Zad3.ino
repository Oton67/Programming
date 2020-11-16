#define ADC1 A1
#define crveno 3
#define zuto 4
#define zeleno 5

unsigned long LastMillis;
int i=0;

void setup() {
  pinMode(crveno, OUTPUT);
  pinMode(zuto, OUTPUT);
  pinMode(zeleno, OUTPUT);
  
  pinMode(ADC1, INPUT);
  Serial.begin(9600);

}

void loop() {
int adcVal = analogRead(ADC1);

  while(adcVal>600)
  {
   adcVal = analogRead(ADC1);
   
   if(i & 0x01) digitalWrite(zeleno, HIGH);
   else digitalWrite(zeleno, LOW);
   
   if(i & 0x02) digitalWrite(zuto, HIGH);
   else digitalWrite(zuto, LOW);
   
   if(i & 0x04) digitalWrite(crveno, HIGH);
   else digitalWrite(crveno, LOW);
   delay(500);
   
   i++;
   if(i==8) i=0;
  }
  


}

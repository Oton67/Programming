#define ADC1 A1
#define crveno 3

unsigned long LastMillis;

void setup() {
  pinMode(crveno, OUTPUT);
  pinMode(ADC1, INPUT);
  Serial.begin(9600);

}

void loop() {
int adcVal = analogRead(ADC1);

  LastMillis=millis();
  while(adcVal>600)
  {
   adcVal = analogRead(ADC1);
   if(millis()-LastMillis>10000)  digitalWrite(crveno, HIGH);
  }
  
LastMillis=millis();
  while(adcVal<600)
  {
   adcVal = analogRead(ADC1);
   if(millis()-LastMillis>10000)  digitalWrite(crveno, LOW);
  }
}

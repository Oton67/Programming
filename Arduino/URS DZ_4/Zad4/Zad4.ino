#define ADC1 A1
#define crveno 3
#define zuto 4
#define zeleno 5

unsigned long LastMillis;
int i = 0;

void setup() {
  pinMode(crveno, OUTPUT);
  pinMode(zuto, OUTPUT);
  pinMode(zeleno, OUTPUT);

  pinMode(ADC1, INPUT);
  Serial.begin(9600);

}

void loop() {
  int adcVal = analogRead(ADC1);

  Serial.println(adcVal);
  

  if (adcVla < 600)
  {
   LastMillis=millis();
  }
  

}

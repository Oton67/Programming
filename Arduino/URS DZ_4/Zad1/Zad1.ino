#define ADC1 A1
#define crveno 3

void setup() {
  pinMode(crveno, OUTPUT);
  pinMode(ADC1, INPUT);
  Serial.begin(9600);

}

void loop() {
  int adcVal = analogRead(ADC1);
  Serial.println(adcVal); 

  digitalWrite(crveno, HIGH);
  delay(1000-adcVal);
   digitalWrite(crveno, LOW);
  delay(1000-adcVal);
}

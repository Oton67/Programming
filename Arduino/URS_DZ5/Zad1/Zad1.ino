#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

uint32_t i = 1;
int poz=0,len=15,a=10;

void setup()
{
  Wire.begin(); // Inicijalizacija i2c sabirnice
  lcd.init(); // initializacija LCD-a
  lcd.backlight(); // funkcija za paljene pozadinskog osvjetljenja
}

int prost(int n)
{
  int i;
  if (n < 2) return 0;

  for (i = 2; i < n; i++) if (n % i == 0) return 0;

  return 1;
}

void loop()
{
  len=15;
  lcd.clear();
  for (i = 1; i < 2000000000; i++) {
    if (prost(i))
    {
        if(i>a){
          len--;
          a=a*10;
        }
        
        poz=(poz+1)%2;
        lcd.setCursor(len, poz);
        lcd.print(i);

      delay(500);
    }

  }

}

// U ovom primjeru koristim 3 različita gumba na daljinskom
#include <Wire.h>
#include "DPir.h"
#define IRdata 4 // data pin
#define ds3231_adr 0x68

byte IRcode[6];
// kodovi od 3 razlicita gumba
int flagH=1,flagM=1,flagS=1,flag=0;
byte tmp_number=0,WW=0x00;
byte myCode[10][6] = {
                      {0xD1, 0x50, 0x41, 0x00, 0x50, 0x50 }, //0
                      {0x84, 0x00, 0x41, 0x00, 0x05, 0x00 }, //1
                      {0xD4, 0x00, 0x41, 0x00, 0x55, 0x00 }, //2
                      {0x90, 0x00, 0x41, 0x00, 0x11, 0x00 }, //3
                      {0x80, 0x40, 0x41, 0x00, 0x01, 0x40 }, //4
                      {0xD0, 0x40, 0x41, 0x00, 0x51, 0x40 }, //5
                      {0x94, 0x40, 0x41, 0x00, 0x15, 0x40 }, //6
                      {0x85, 0x40, 0x41, 0x00, 0x04, 0x40 }, //7
                      {0xD5, 0x40, 0x41, 0x00, 0x54, 0x40 }, //8
                      {0x91, 0x40, 0x41, 0x00, 0x10, 0x40 }  //9
                     };

byte H[6]={0x85, 0x54, 0x41, 0x00, 0x04, 0x54};
byte M[6]={0xC1, 0x45, 0x41, 0x00, 0x40, 0x45};
byte S[6]={0xD4, 0x14, 0x41, 0x00, 0x55, 0x14};
byte OK[6]={0x80, 0x51, 0x41, 0x00, 0x01, 0x51};

// ova funkcija uspoređuje primljeni kod s kodom iz gornje tabele
// Ako nađe kod na 0-toj poziciji vraća 1, ako na drugoj vraća 2 itd.
// ako ne nađe kod vraća 0
byte checkCode() 
{
   for(int i=0;i<10;i++)
   {
      byte ok=1;
      for(int j=0;j<6;j++) if(IRcode[j] != myCode[i][j]) ok=0;
      if(ok==1) return i;
   }
   return 0;
}


DPir dpir(IRdata);


void setup() {

   Wire.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Wire.beginTransmission(ds3231_adr); 
  Wire.write(0x00);
  byte I2Cerror = Wire.endTransmission();      
  if(I2Cerror)
  {
      Serial.print("I2C error :");     
      Serial.println(I2Cerror);
      delay(1000);
      return;
  }

  Wire.requestFrom(ds3231_adr,3);
  byte seconds = Wire.read();
  byte minutes = Wire.read();
  byte hours = Wire.read();
  
 Serial.print(hours,HEX);Serial.print(":");
 Serial.print(minutes,HEX);Serial.print(":");
 Serial.print(seconds,HEX);
 Serial.print("\n");
 delay(250);




  if(dpir.available()!=0)
  {
           dpir.getCode(IRcode);
           
           for(int i=0;i<6;i++) if(IRcode[i]!=H[i]) flagH=0;
           if(flagH==1)Serial.println("Sati: ");
           
           while(flagH==1)
           {
             if(dpir.available()!=0)
              {
                delay(100);
                dpir.getCode(IRcode);
                
                flagH=0;
                for(int i=0;i<6;i++) if(IRcode[i]!=OK[i]) flagH=1;
                
                if(flagH==1)
                {
                tmp_number=tmp_number<<4;
                tmp_number=tmp_number|checkCode();
                Serial.print(tmp_number,HEX);
                Serial.println("h");
                }
                WW=0x02;
                flag=1;
              }
           }
           


           for(int i=0;i<6;i++) if(IRcode[i]!=M[i]) flagM=0;
           if(flagM==1)Serial.println("Minute: ");
           
           while(flagM==1)
           {
             if(dpir.available()!=0)
              {
                delay(100);
                dpir.getCode(IRcode);
                
                flagM=0;
                for(int i=0;i<6;i++) if(IRcode[i]!=OK[i]) flagM=1;
                
                if(flagM==1)
                {
                tmp_number=tmp_number<<4;
                tmp_number=tmp_number|checkCode();
                Serial.print(tmp_number,HEX);
                Serial.println("min");
                }
                WW=0x01;
                flag=1;
              }
           }



           for(int i=0;i<6;i++) if(IRcode[i]!=S[i]) flagS=0;
           if(flagS==1)Serial.println("Sekunde: ");
           
           while(flagS==1)
           {
             if(dpir.available()!=0)
              {
                delay(100);
                dpir.getCode(IRcode);
                
                flagS=0;
                for(int i=0;i<6;i++) if(IRcode[i]!=OK[i]) flagS=1;
                
                if(flagS==1)
                {
                tmp_number=tmp_number<<4;
                tmp_number=tmp_number|checkCode();
                Serial.print(tmp_number,HEX);
                Serial.println("sec");
                }
                WW=0x00;
                flag=1;
              }
           }
           
           
   if(flag==1)
   {        
   Wire.beginTransmission(ds3231_adr); 
   Wire.write(WW);

   Wire.write(tmp_number);
   Wire.endTransmission();
   }        
           
           
           flag=0;
           flagH=1;
           flagM=1;
           flagS=1;
           tmp_number=0;
  }
  




}

// verzija 1.013 beta

#include "Arduino.h"
#include "DPir.h"

const uint8_t PROGMEM digital_pin_to_PCINT_PGM[] = 
{PCINT16, PCINT17, PCINT18, PCINT19, PCINT20, PCINT21, PCINT22, PCINT23};        // D0 ,1 2 3 4 5 6 7
                                                                                       
#define digitalPinPCINT(P) ( pgm_read_byte( digital_pin_to_PCINT_PGM + (P) ) )

byte bitmask =0x80;
DPir::DPir(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  bitmask=0x80;
  
  if(_pin>=0 && _pin<=7)
  {
      PCMSK2 |= bit (digitalPinPCINT(_pin)) ;  // 
      PCIFR  |= bit (PCIF2);   // Pin Change Interrupt Flag Register
      PCICR  |= bit (PCIE2);   // Pin Change Interrupt Control Register 
  }


  
}


//volatile uint16_t IRsignalTime;
volatile dpirISR_t dpISR;

volatile byte j=0;
uint16_t lastPulsLength=0;
uint16_t lastSpaceLength=0;
ISR(PCINT2_vect)
{
    if(millis()-dpISR.OKTime<15){ dpISR.OKTime = millis();  return;} ;
    dpISR.IRtime = micros();
 
    if(dpISR.IR_State==2) return;   // 0 = prazno, 1 = samplira ili gotovo, 2 = gotovo sampliranje, napravi čitanje
    dpISR.IR_State = 1;
    if(dpISR.IRcounter==0) { dpISR.lastIRtime = dpISR.IRtime; dpISR.IRcounter++; return; }
    
    uint16_t IRsignalLength = dpISR.IRtime-dpISR.lastIRtime;        // length of space or pulse
    if(IRsignalLength>15000) { dpISR.IR_State=2; return;};
    if(dpISR.IRcounter==1) lastPulsLength = IRsignalLength;
    if(dpISR.IRcounter==2) lastSpaceLength = IRsignalLength;

    if(dpISR.IRcounter>2)
    {
        if(dpISR.IRcounter%2==1)        // 
        {
           
           uint16_t PulseLengthDiff;
           if(IRsignalLength>lastPulsLength) PulseLengthDiff = IRsignalLength - lastPulsLength;
             else PulseLengthDiff = lastPulsLength -IRsignalLength ;
           if(PulseLengthDiff>200) dpISR.IRcode[j] = dpISR.IRcode[j] ^ bitmask;
           bitmask=bitmask>>1;
           lastPulsLength = IRsignalLength;
                     
        }
        if(dpISR.IRcounter%2==0)
        {
           
           uint16_t SpaceLengthDiff;
           if(IRsignalLength>lastSpaceLength) SpaceLengthDiff = IRsignalLength - lastSpaceLength;
             else SpaceLengthDiff = lastSpaceLength -IRsignalLength ;
           if(SpaceLengthDiff>200) dpISR.IRcode[j] = dpISR.IRcode[j] ^ bitmask;
           bitmask=bitmask>>1;
           lastSpaceLength = IRsignalLength;
                 if(bitmask==0)
                 {
                     bitmask=0x80;
                     j++;
                     if(j==6) j = 0;
                 }
        }
        
    }

        
   //if(IRsignalTime>15000) { IR_State=2; return;};
    
    dpISR.IRcounter++;    

    dpISR.lastIRtime = dpISR.IRtime;
}

byte DPir::available()
{
   unsigned long IRgetTime;
   unsigned long IRlt;
   cli();
       IRgetTime = micros();
       IRlt = dpISR.lastIRtime;
       if(dpISR.IR_State==0){ sei(); return 0;}
       if(IRgetTime-IRlt<15000) {sei();  return 0;}
       dpISR.IR_State = 2;
   sei();

   if(dpISR.IRcounter<10) 
   {
      for(int i =0;i<6;i++) dpISR.IRcode[i]=0;
      dpISR.IRcounter =0;
      j=0;
      bitmask=0x80;
      
      cli();
        dpISR.IR_State =0;
      sei();
      return 0;
   }
   return dpISR.IRcounter;
}



void DPir::getCode(byte * IRcode)
{

   if(available()==0) return;

   for(int i =0;i<6;i++)
   {
     //Serial.print(dpISR.IRcode[i],HEX); Serial.print(" ");
     IRcode[i] = dpISR.IRcode[i];
     dpISR.IRcode[i]=0;
   }
   //Serial.println();

   
   //Serial.println("--------------");

   cli();
       dpISR.OKTime = millis();
       dpISR.IRcounter =0;
       dpISR.IR_State =0;
       j=0;
       bitmask=0x80;
      
   sei();


   
}

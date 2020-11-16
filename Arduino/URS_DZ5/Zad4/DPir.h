/*
  DPir.h 
*/
#ifndef DPir_h
#define DPir_h

#include "Arduino.h"

class DPir
{
  public:
    DPir(int pin);
    void getCode(byte * IRcode);
    byte available();
  private:
    int _pin;
    
};




typedef struct {
  byte IR_State;    // pin for IR data from detector
  unsigned long IRtime;
  unsigned long lastIRtime;
  byte IRcounter;
  unsigned long OKTime;
  byte IRcode[6];
} dpirISR_t;

extern volatile dpirISR_t dpISR;

#endif

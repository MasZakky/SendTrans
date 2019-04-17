#ifndef _SendTrans_H_
#define _SendTrans_H_

#include "Arduino.h"
#include <TinyWireM.h>
#include <Wire.h>

#if defined(__AVR_AT90Mega169__) | defined(__AVR_ATmega169__) | \
    defined(__AVR_AT90Mega165__) | defined(__AVR_ATmega165__) | \
    defined(__AVR_ATmega325__) | defined(__AVR_ATmega3250__) | \
    defined(__AVR_ATmega645__) | defined(__AVR_ATmega6450__) | \
    defined(__AVR_ATmega329__) | defined(__AVR_ATmega3290__) | \
    defined(__AVR_ATmega649__) | defined(__AVR_ATmega6490__) | \
    defined(__AVR_ATtiny25__) | defined(__AVR_ATtiny45__) | defined(__AVR_ATtiny85__) | \
    defined(__AVR_AT90Tiny26__) | defined(__AVR_ATtiny26__) | \
    defined(__AVR_ATtiny84__) | defined(__AVR_ATtiny44__) | \
    defined(__AVR_AT90Tiny2313__) | defined(__AVR_ATtiny2313__)
      #define EX_Tiny 
#endif

#define Use_Default     0
#define Use_External    1
//#define Use_Expander  2

#define Process_Not_Found -1
#define Process_OK         0 
#define Process_ERROR      1

class SendTransI2C{
  public: 
#ifdef ARDUINO_SAM_DUE
    int8_t setWire(int8_t val = Use_External);
#else
    int8_t setWire(int8_t val = Use_Default);
#endif
    int8_t setWire(int8_t val, byte Address);
    
#ifdef ARDUINO_SAM_DUE
    int8_t InstalWire(TwoWire &val = Wire1);
#else  
    int8_t InstalWire(TwoWire &val);
#endif
    
    int8_t setWrite(int8_t val);
    int8_t setWrite(int8_t val,int8_t val2);
    int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);


    int8_t getRead(int8_t val,uint8_t& val2);
    int8_t getRead(int8_t val,uint8_t& val2,uint8_t val3);
  
  protected:
  
    TwoWire ExWire;  
    byte _Address;
    int8_t _useWire;
};
//extern SendTransI2C SimpleWire;
#endif

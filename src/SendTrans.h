#ifndef _SendTrans_H
#define _SendTrans_H

#include "Arduino.h"

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

    #if defined(TinyWireM_h)
      #include <TinyWire.h>
      #define set_Wire  TinyWireM
      #define set_Write send
      #define get_Read  receiver
    #else 
      #error "Please Download library TinyWireM"
    #endif

#else
  #include <Wire.h>
  
  #ifdef ARDUINO_SAM_DUE
    #define set_Wire  Wire1
  #else 
    #define set_Wire  Wire
  #endif
  
  #define set_Write write
  #define get_Read  read
#endif

#define Use_Default 0
#define Use_External 1
//#define Use_Expander 2

#define Process_OK 0 
#define Process_ERROR 1

class SendTransI2C{
  public: 
    int8_t setWire(int8_t val = Use_Default);
    int8_t setWire(int8_t val, byte Address);
    
#ifdef EX_Tiny
    int8_t InstalWire(USI_TWI &val);
#else  
    int8_t InstalWire(Stream &val);
#endif
    
    int8_t setWrite(int8_t val);
    int8_t setWrite(int8_t val,int8_t val2);
    int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);


    int8_t getRead(int8_t val,int8_t &val2);
    int8_t getRead(int8_t val,int8_t &val2,int8_t val3);
  
  private:
  
#ifdef EX_Tiny
    USI_TWI ExWire;
#else
    Stream ExWire;
#endif
  
    byte _Address;
    int8_t _useWire;
};

#endif

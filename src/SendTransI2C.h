#ifndef _SendTransI2C_H_
#define _SendTransI2C_H_

#include "Arduino.h"
#include "SendTrans.h"

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
      #include <TinyWireM.h>
#else 
      #include <Wire.h>
#endif

#if defined(Not_UseSwitch) || defined(Yes_UseSwitch)
    #undef Not_UseSwitch
    #undef Yes_UseSwitch
#endif
    #define Not_UseSwitch 0
    #define Yes_UseSwitch 1

#if defined(Yes_UseExpander) || defined(Not_UseExpander)
    #undef Yes_UseExpander
    #undef Not_UseExpander
#endif
    #define Yes_UseExpander 0
    #define Not_UseExpander 1

#if defined(Use_TCA9548A)
    #undef Use_TCA9548A
#endif
    #define Use_TCA9548A 0

#if defined(_AddressTCA9548A)
    #undef _AddressTCA9548A
#endif
    #define _AddressTCA9548A 0x70

class SendTransI2C{
  public: 
    int8_t setWire(byte Address);
    int8_t setWire(byte val,byte val1,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7);
 
    //I2C MultiPlexer
    int8_t setMultiPlexer(int8_t val = Not_UseSwitch,int8_t val2 = Use_TCA9548A);
    int8_t setAddressMultiPlexer(byte Address = _AddressTCA9548A,byte val1 = 0,byte val2 = 0,byte val3 = 0,byte val4 = 0);
    int8_t setChannel(int8_t val);
    
    // Wire or Wire1 or Wire3 ~~
#if !defined EX_Tiny    
        int8_t InstalWire(TwoWire* val);
#endif
    
    //Write
    int8_t setWrite(byte val);
    int8_t setWrite(byte val,byte val2);
    int8_t setWrite(byte val,byte *val2,byte val3);
 
    //read
    int8_t getRead(byte val,byte val2);
    int8_t getRead(byte val,byte *val2,byte val3);
  
  protected:
    int8_t AutoSwitchChannel();
    
#if !defined(EX_Tiny)
    TwoWire *ExWire;  
#endif
    byte _Address,_Address2;
    int8_t _useSwitch;
    int8_t _nameIC;
    int8_t _setChannel;
};
//extern SendTransI2C SimpleWire;


#endif

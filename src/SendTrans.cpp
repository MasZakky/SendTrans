#include "SendTrans.h"

int8_t SendTransI2C::setWire(byte Address){
  _Address = Address;
  return Process_OK;
}

int8_t SendTransI2C::setWire(byte val,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7){
  _Address = val | val2<<1 | val3<<2 | val4<<3 | val5<<4 | val6<<5 | val7<<6 ;
  return Process_OK;
}

int8_t SendTransI2C::setMultiPlexer(int8_t val ,int8_t val2){
  _useSwitch = val;
  _nameIC = val2;
  return Process_OK;
}

int8_t SendTransI2C::setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4){
  _Address2 = Address | val<<1 | val2<<2 | val3<<3 | val4<<4;
  return Process_OK;
}

int8_t SendTransI2C::setChannel(int8_t val){
  _setChannel = (1<<val);
  return Process_OK;
}

#if !defined(EXTiny)
int8_t SendTransI2C::InstalWire(TwoWire *val){
  ExWire = val;
  return Process_OK;
}
#endif
    
int8_t SendTransI2C::setWrite(int8_t val){
  if(SendTransI2C::AutoSwitchChannel() != Process_OK) return Process_ERROR; 
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    int8_t value = TinyWireM.endTransmission();
#else 
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    int8_t value = ExWire.endTransmission();
#endif
  if(value > 0) return Process_ERROR;
  else return Process_OK;
}

int8_t SendTransI2C::setWrite(int8_t val,int8_t val2){
  if(SendTransI2C::AutoSwitchChannel() != Process_OK) return Process_ERROR; 
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    TinyWireM.send(val2);
    int8_t value = TinyWireM.endTransmission();
#else
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    ExWire.write(val2);
    int8_t value = ExWire.endTransmission();
#endif
  if(value > 0) return Process_ERROR;
  else return Process_OK;
}

int8_t SendTransI2C::setWrite(int8_t val,int8_t *val2,int8_t val3){
  if(val3<=0) return Process_ERROR;
  if(SendTransI2C::AutoSwitchChannel() != Process_OK) return Process_ERROR; 
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.write(val);
  
    for(int8_t asa = 0; asa <= val3; asa++){
      TinyWireM.write(val2[asa]);
    }
    
    int8_t value = TinyWireM.endTransmission();
#else
    ExWire.beginTransmission(_Address);
    ExWire.write(val);

    for(int8_t asa = 0; asa <= val3; asa++){
      ExWire.write(val2[asa]);
    }

    int8_t value = ExWire.endTransmission();
#endif
  if(value > 0) return Process_ERROR;
  else return Process_OK;
}

int8_t SendTransI2C::getRead(int val,int& val2){
  if(SendTransI2C::AutoSwitchChannel() != Process_OK) return Process_ERROR; 
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    int8_t value = TinyWireM.endTransmission();
    if(value > 0) return Process_ERROR;

    TinyWireM.requestFrom((int)_Address,1);
    if(TinyWireM.available()) val2 = (int)TinyWireM.receive();
#else
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;

    ExWire.requestFrom((int)_Address,1);
    if(ExWire.available()) val2 = (int)ExWire.read();
#endif
  return Process_OK;
}

int8_t SendTransI2C::getRead(int val,int& val2,int val3){
  if(val <= 0) return Process_ERROR;
  if(SendTransI2C::AutoSwitchChannel() != Process_OK) return Process_ERROR; 
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    int8_t value = TinyWireM.endTransmission();
    if(value > 0) return Process_ERROR;
    
    TinyWireM.requestFrom((int)_Address,val3);
    if(TinyWireM.available() == val3){
      for(uint8_t asa = 0; asa <= val2; asa++){
        val2[asa] = (int)TinyWireM.receive();
      }
    }
#else
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    
    ExWire.requestFrom((int)_Address,val3);
    if(ExWire.available() == val3){ 
      for(uint8_t asa = 0; asa <= val3; asa++){
        val2[asa] = (int)ExWire.read();
      }
    } 
#endif
  return Process_OK;
}

int8_t SendTransI2C::AutoSwitchChannel(){
  if(_useSwitch == Not_UseSwitch) return Process_OK;
  switch(_nameIC){
    case Use_TCA9548A: 
#ifdef EX_Tiny
      TinyWireM.beginTransmission(_Address2);
      TinyWireM.send(_setChannel);
      int8_t value = TinyWireM.endTransmission();
#else 
      ExWire.beginTransmission(_Address);
      ExWire.write(val);
      int8_t value = ExWire.endTransmission();
#endif
      if(value > 0) return Process_ERROR;
      else return Process_OK;      
      break;
  }
}

//extern SendTransI2C SimpleWire;

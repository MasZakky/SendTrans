#include "SendTrans.h"

int8_t SendTransI2C::setWire(int8_t val){
  return  SendTransI2C::setWire(val, 0x00);
}
int8_t SendTransI2C::setWire(int8_t val, byte Address){
  _useWire = (byte)val | (Address<<1);
  return Process_OK;
}

int8_t SendTransI2C::InstalWire(TwoWire &val){
  ExWire = val;
  return Process_OK;
}

int8_t SendTransI2C::setWrite(int8_t val){
  if(_useWire == Use_Default){
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    int8_t value = TinyWireM.endTransmission();
#else
    Wire.beginTransmission(_Address);
    Wire.write(val);
    int8_t value = Wire.endTransmission();
#endif
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
}
int8_t SendTransI2C::setWrite(int8_t val,int8_t val2){
  if(_useWire == Use_Default){
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    TinyWireM.send(val2);
    int8_t value = TinyWireM.endTransmission();
#else
    Wire.beginTransmission(_Address);
    Wire.write(val);
    Wire.write(val2);
    int8_t value = Wire.endTransmission();
#endif
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    ExWire.write(val2);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
}
int8_t SendTransI2C::setWrite(int8_t val,int8_t *val2,int8_t val3){
  if(val3<=0) return Process_ERROR;
  if(_useWire == Use_Default){
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.write(val);
    for(int8_t asa = 0; asa <= val3; asa++){
      TinyWireM.write(val2[asa]);
    }
    int8_t value = TinyWireM.endTransmission();
#else
    Wire.beginTransmission(_Address);
    Wire.write(val);
    for(int8_t asa = 0; asa <= val3; asa++){
      Wire.write(val2[asa]);
    }
    int8_t value = Wire.endTransmission();
#endif
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    for(int8_t asa = 0; asa <= val3; asa++){
      ExWire.write(val2[asa]);
    }
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
}

int8_t SendTransI2C::getRead(int8_t val,uint8_t& val2){
  if(_useWire == Use_Default){
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    int8_t value = TinyWireM.endTransmission();
    if(value > 0) return Process_ERROR;

    TinyWireM.requestFrom(_Address,1);
    if(TinyWireM.available()) val2 = (uint8_t)TinyWireM.receive();
#else
    Wire.beginTransmission(_Address);
    Wire.write(val);
    int8_t value = Wire.endTransmission();
    if(value > 0) return Process_ERROR;

    Wire.requestFrom(_Address,1);
    if(Wire.available()) val2 = (uint8_t)Wire.read();
#endif
    return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;

    ExWire.requestFrom(_Address,1);
    if(ExWire.available()) val2 = (uint8_t)ExWire.read();

    return Process_OK;
  } 
}
int8_t SendTransI2C::getRead(int8_t val,uint8_t& val2,uint8_t val3){
  if(val <= 0) return Process_ERROR;
  if(_useWire == Use_Default){
#ifdef EX_Tiny
    TinyWireM.beginTransmission(_Address);
    TinyWireM.send(val);
    int8_t value = TinyWireM.endTransmission();
    if(value > 0) return Process_ERROR;
    
    TinyWireM.requestFrom(_Address,val3);
    if(TinyWireM.available() == val3){
      for(uint8_t asa = 0; asa <= val2; asa++){
        val2[asa] = (uint8_t)TinyWireM.receive();
      }
    }
#else
    Wire.beginTransmission(_Address);
    Wire.write(val);
    int8_t value = Wire.endTransmission();
    if(value > 0) return Process_ERROR;

    Wire.requestFrom(_Address,val3);
    if(Wire.available() == val3){ 
      for(uint8_t asa = 0; asa <= val2; asa++){
        val2[asa] = (uint8_t)Wire.read();
      }
    }
#endif
    return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    
    ExWire.requestFrom(_Address,val3);
    if(ExWire.available() == val3){ 
      for(uint8_t asa = 0; asa <= val3; asa++){
        val2[asa] = (uint8_t)ExWire.read();
      }
    } 
    return Process_OK;
  }
}

//extern SendTransI2C SimpleWire;

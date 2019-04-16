#include "SendTrans.h"

int8_t SendTransI2C::setWire(int8_t val){
  return  SendTransI2C::setWire(val, 0x00);
}

int8_t SendTransI2C::setWire(int8_t val, byte Address){
  _useWire = (byte)val | (Address<<1);
  return Process_OK;
}

#ifdef EX_Tiny
int8_t SendTransI2C::InstalWire(USI_TWI &val){
  ExWire *= &val;
  return Process_OK;
}
#else  
int8_t SendTransI2C::InstalWire(Stream &val){
  ExWire *= &val;
  return Process_OK;
}
#endif

int8_t SendTransI2C::setWrite(int8_t val){
  if(_useWire == Use_Default){
    set_Wire.beginTransmission(_Address);
    set_Wire.set_Write(val);
    int8_t value = set_Wire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.set_Write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
}

int8_t SendTransI2C::setWrite(int8_t val,int8_t val2){
  if(_useWire == Use_Default){
    set_Wire.beginTransmission(_Address);
    set_Wire.set_Write(val);
    set_Wire.set_Write(val2);
    int8_t value = set_Wire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.set_Write(val);
    ExWire.set_Write(val2);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
}

int8_t SendTransI2C::setWrite(int8_t val,int8_t *val2,int8_t val3){
  if(_useWire == Use_Default){
    set_Wire.beginTransmission(_Address);
    set_Wire.set_Write(val);
    for(int8_t asa = 0; asa <= val3; asa++){
      set_Wire.set_Write(val2[asa]);
    }
    int8_t value = set_Wire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.set_Write(val);
    for(int8_t asa = 0; asa <= val3; asa++){
      ExWire.set_Write(val2[asa]);
    }
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;
    else return Process_OK;
  }
}

int8_t SendTransI2C::getRead(int8_t val,int8_t &val2){
  if(_useWire == Use_Default){
    set_Wire.beginTransmission(_Address);
    set_Wire.set_Write(val);
    int8_t value = set_Wire.endTransmission();
    if(value > 0) return Process_ERROR;

    set_Wire.requestFrom(_Address,1);
    val2 = set_Wire.get_Read();
    
    return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.set_Write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;

    ExWire.requestFrom(_Address,1);
    val2 = ExWire.get_Read();
    
    return Process_OK;
  } 
}

int8_t SendTransI2C::getRead(int8_t val,int8_t &val2,int8_t val3){
  if(_useWire == Use_Default){
    set_Wire.beginTransmission(_Address);
    set_Wire.set_Write(val);
    int8_t value = set_Wire.endTransmission();
    if(value > 0) return Process_ERROR;

    set_Wire.requestFrom(_Address,val3);
    for(int8_t asa = 0; asa <= val2; asa++){
      val2[asa] = set_Wire.get_Read();
    }
    
    return Process_OK;
  }
  else if(_useWire == Use_External){
    ExWire.beginTransmission(_Address);
    ExWire.set_Write(val);
    int8_t value = ExWire.endTransmission();
    if(value > 0) return Process_ERROR;

    ExWire.requestFrom(_Address,val3);
    for(int8_t asa = 0; asa <= val2; asa++){
      val2[asa] = ExWire.get_Read();
    }
    
    return Process_OK;
  }
}
  

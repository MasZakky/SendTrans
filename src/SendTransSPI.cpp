#include "SendTransSPI.h"

int8_t SendTransSPI::InstalSPI(SPIClass * spi,uint8_t cs){
  _spi = spi;
  _cs = cs;
  return Process_OK;
}

int8_t SendTransSPI::setSetting(uint32_t clock,uint8_t bitOrder,uint8_t dataMode){
  _clock = clock;
  _bitOrder = bitOrder;
  _dataMode = dataMode;
  return Process_OK;
}

//Write
int8_t SendTransSPI::setWrite(byte val){
  _spi->beginTransaction(SPISettings(_clock,_bitOrder,_dataMode));
  ::digitalWrite(_cs,LOW);
  _spi->transfer(val);
  ::digitalWrite(_cs,HIGH);
  _spi->endTransaction();
  return Process_OK;
}
int8_t SendTransSPI::setWrite(byte val,byte val2){
  _spi->beginTransaction(SPISettings(_clock,_bitOrder,_dataMode));
  ::digitalWrite(_cs,LOW);
  _spi->transfer(val);
  _spi->transfer(val2);
  ::digitalWrite(_cs,HIGH);
  _spi->endTransaction();
  return Process_OK;
}
int8_t SendTransSPI::setWrite(byte val,byte *val2,byte val3){
  if(val3 < 0) return Process_ERROR;
  _spi->beginTransaction(SPISettings(_clock,_bitOrder,_dataMode));
  ::digitalWrite(_cs,LOW);
  _spi->transfer(val);
  for(byte a = 0; a<= val3; a++){
    _spi->transfer(val2[a]);
  }
  ::digitalWrite(_cs,HIGH);
  _spi->endTransaction();
  return Process_OK;
}

//read
int8_t SendTransSPI::getRead(byte val,byte val2){
  _spi->beginTransaction(SPISettings(_clock,_bitOrder,_dataMode));
  ::digitalWrite(_cs,LOW);
  _spi->transfer(val);

  val2 = _spi->transfer(val);
  
  ::digitalWrite(_cs,HIGH);
  _spi->endTransaction();  
  return Process_OK;
}

int8_t SendTransSPI::getRead(byte val,byte *val2,byte val3){
  if(val3 < 0) return Process_ERROR;
  _spi->beginTransaction(SPISettings(_clock,_bitOrder,_dataMode));
  ::digitalWrite(_cs,LOW);
  _spi->transfer(val);
  for(byte a = 0; a<= val3; a++){
    val2[a] = _spi->transfer(val);
  }
  ::digitalWrite(_cs,HIGH);
  _spi->endTransaction();
  return Process_OK;
}

#ifndef _SendTransSPI_H_
#define _SendTransSPI_H_

#include "Arduino.h"
#include "SendTrans.h"

#include <SPI.h>

class SendTransSPI{
  public:
    int8_t InstalSPI(SPIClass * spi,uint8_t cs);
    int8_t setSetting(uint32_t clock,uint8_t bitOrder,uint8_t dataMode);

    //Write
    int8_t setWrite(byte val);
    int8_t setWrite(byte val,byte val2);
    int8_t setWrite(byte val,byte *val2,byte val3);
 
    //read
    int8_t getRead(byte val,byte val2);
    int8_t getRead(byte val,byte *val2,byte val3);
    
  protected:
    SPIClass * _spi;
    uint32_t _clock;
    uint8_t _bitOrder,_dataMode,_cs;
};

#endif

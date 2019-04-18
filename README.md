# SendTrans
<h3>Library Simple TwoWire</h3>
    <h6>
    
    int8_t setWire(byte Address);
    int8_t setWire(byte val,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7);
    
    //I2C MultiPlexer
    int8_t setMultiPlexer(int8_t val,int8_t val2);
    int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);
    int8_t setChannel(int8_t val);
    
    // Wire or Wire1 or Wire3 ~~
    int8_t InstalWire(TwoWire *val);
    
    //Write
    int8_t setWrite(int8_t val);
    int8_t setWrite(int8_t val,int8_t val2);
    int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);
 
    //read>
    int8_t getRead(int val,int& val2);
    int8_t getRead(int val,int& val2,int val3);</h6>


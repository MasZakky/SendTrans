# SendTrans
<h3>Library Simple TwoWire</h3>
<pre>
    int8_t setWire(byte Address);
    int8_t setWire(byte val,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7);
 
    //I2C MultiPlexer
    int8_t setMultiPlexer(int8_t val = Not_UseSwitch,int8_t val2 = Use_TCA9548A);
    int8_t setAddressMultiPlexer(byte Address = _AddressTCA9548A,byte val1 = 0,byte val2 = 0,byte val3 = 0,byte val4 = 0);
    int8_t setChannel(int8_t val);
    
    // Wire or Wire1 or Wire3 ~~
#if !defined EX_Tiny    
    #ifdef ARDUINO_SAM_DUE
        int8_t InstalWire(TwoWire *val = Wire1);
    #else  
        int8_t InstalWire(TwoWire *val = Wire);
    #endif
#endif
    
    //Write
    int8_t setWrite(int8_t val);
    int8_t setWrite(int8_t val,int8_t val2);
    int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);
 
    //read
    int8_t getRead(int val,int& val2);
    int8_t getRead(int val,int& val2,int val3);
  
  protected:
    int8_t AutoSwitchChannel();
    
#if !defined(EX_Tiny)
    TwoWire ExWire;  
#endif
    byte _Address,_Address2;
    int8_t _useSwitch;
    int8_t _nameIC;
    int8_t _setChannel;
};
</pre>

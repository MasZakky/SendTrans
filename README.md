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
    
    <h4>All the command fuctions with RETURN</h4>
    <ul>
        <li> <h5> Process_OK </h5> </li>
        <li> <h5> Process_ERROR </h5> </li>
    </ul>
    
    <h4>Notice</h4>
    <pre><h5> 
    if  defined(__AVR_AT90Mega169__) | defined(__AVR_ATmega169__) | \
        defined(__AVR_AT90Mega165__) | defined(__AVR_ATmega165__) | \
        defined(__AVR_ATmega325__) | defined(__AVR_ATmega3250__) | \
        defined(__AVR_ATmega645__) | defined(__AVR_ATmega6450__) | \
        defined(__AVR_ATmega329__) | defined(__AVR_ATmega3290__) | \
        defined(__AVR_ATmega649__) | defined(__AVR_ATmega6490__) | \
        defined(__AVR_ATtiny25__) | defined(__AVR_ATtiny45__) | defined(__AVR_ATtiny85__) | \
        defined(__AVR_AT90Tiny26__) | defined(__AVR_ATtiny26__) | \
        defined(__AVR_ATtiny84__) | defined(__AVR_ATtiny44__) | \
        defined(__AVR_AT90Tiny2313__) | defined(__AVR_ATtiny2313__)
            Automatic disable "InstalWire" and "Wire" will be replaced with "TinyWireM" 
        
        </h5></pre>

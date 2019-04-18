# SendTrans
<h3>Library Simple TwoWire</h3>
<pre>
    <h6>int8_t setWire(byte Address);</h6>

    <h6>int8_t setWire(byte val,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7); </h6>
    
    <h6>//I2C MultiPlexer</h6>
    <h6>int8_t setMultiPlexer(int8_t val,int8_t val2);</h6>
    <h6>int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);</h6>
    <h6>int8_t setChannel(int8_t val);</h6>
    
    <h6>// Wire or Wire1 or Wire3 ~~</h6>
<h6>#if !defined EX_Tiny    </h6>
    <h6>#ifdef ARDUINO_SAM_DUE</h6>
        <h6>int8_t InstalWire(TwoWire *val = Wire1);</h6>
    <h6>#else  </h6>
        <h6>int8_t InstalWire(TwoWire *val = Wire);</h6>
    <h6>#endif</h6>
<h6>#endif</h6>
    
    <h6>//Write</h6>
    <h6>int8_t setWrite(int8_t val);</h6>
    <h6>int8_t setWrite(int8_t val,int8_t val2);</h6>
    <h6>int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);</h6>
 
    <h6>//read</h6>
    <h6>int8_t getRead(int val,int& val2);</h6>
    <h6>int8_t getRead(int val,int& val2,int val3);</h6>
</pre>

# SendTrans
<h3>Library Simple TwoWire</h3>
<h6>
    
    #define Not_UseSwitch 0
#define Yes_UseSwitch 1

#define Yes_UseExpander 0
#define Not_UseExpander 1

#define Use_TCA9548A 0

#define _AddressTCA9548A 0x70

#define Process_Not_Found -1
#define Process_OK         0 
#define Process_ERROR      1

    int8_t setWire(byte Address);
    int8_t setWire(byte val,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7);
    
    //I2C MultiPlexer
    int8_t setMultiPlexer(int8_t val,int8_t val2);
                          Value     ,IC MuliPlexer
        Value => Not_UseSwitch or Yes_UseSwitch
        IC    => Use_TCA9548A
        
    int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);
                                 Value       ,A0       ,A1       ,A2       ,A3 or 0
        Value       => Address IC MuliPlexer
        pinAddr     => A0,A1,A2,A3/0
        
    int8_t setChannel(int8_t val);
                      Channel
        Channel => 0 ~ 7
    
    // Wire or Wire1 or Wire3 ~~
    int8_t InstalWire(TwoWire *val);
        Syntax:
         - InstalWire(&Wire);
         - InstalWire(&Wire1);
         - InstalWire(&Wire2);
    
    //Write
    int8_t setWrite(int8_t val);
    int8_t setWrite(int8_t val,int8_t val2);
    int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);
    
    //read>
    int8_t getRead(int val,int& val2);
    int8_t getRead(int val,int& val2,int val3);
    
    
</h6>
    
<h4>All the command fuctions with RETURN</h4>
<ul>
    <li> <h5> Process_OK </h5> </li>
    <li> <h5> Process_ERROR </h5> </li>
</ul>

<h4>Notice</h4>
<pre><h5> 
    if  defined(__AVR_AT90Mega169__)  or defined(__AVR_ATmega169__)   or
        defined(__AVR_AT90Mega165__)  or defined(__AVR_ATmega165__)   or
        defined(__AVR_ATmega325__)    or defined(__AVR_ATmega3250__)  or
        defined(__AVR_ATmega645__)    or defined(__AVR_ATmega6450__)  or
        defined(__AVR_ATmega329__)    or defined(__AVR_ATmega3290__)  or
        defined(__AVR_ATmega649__)    or defined(__AVR_ATmega6490__)  or
        defined(__AVR_ATtiny25__)     or defined(__AVR_ATtiny45__)    or defined(__AVR_ATtiny85__) or
        defined(__AVR_AT90Tiny26__)   or defined(__AVR_ATtiny26__)    or
        defined(__AVR_ATtiny84__)     or defined(__AVR_ATtiny44__)    or
        defined(__AVR_AT90Tiny2313__) or defined(__AVR_ATtiny2313__)
            Automatic disable "InstalWire" and "Wire" will be replaced with "TinyWireM" 
        
</h5></pre>

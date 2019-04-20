# SendTransI2C or SendTransSPI or SendTransUART

<h5> Example Param </h5>
        
        #include "SendTrans.h"
        SendTransI2C SimpleWire;
        
        void setup(){
            Wire.begin();
            Serial.begin(9600);
            
            if(SimpleWire.setWire(0x00) != Process_OK) Serial.println("Process_ERROR");
            else Serial.println("Process_OK");
            
            if(SimpleWire.InstalWire(&Wire) != Process_OK) Serial.println("Process_ERROR");
            else Serial.println("Process_OK");
            
        }
        
        void loop(){
            //Do something
        }
        

<h3> Command SendTransI2C : </h3>

    1.  int8_t setWire(byte Address);
                       Address
                      
    2.  int8_t setWire(byte val,byte val1,byte val2,byte val3,byte val4,byte val5,byte val6,byte val7);
             Address   =BIT0   ,BIT1     ,BIT2     ,BIT3     ,BIT4     ,BIT5     ,BIT6     ,BIT7 
    
    //I2C MultiPlexer
    3.  int8_t setMultiPlexer(int8_t val,int8_t val2);
                           Value     ,IC MuliPlexer
             Default => Not_UseSwitch & Use_TCA9548A 
             Value   => Not_UseSwitch or Yes_UseSwitch
             IC      => Use_TCA9548A
        
    4.  int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);
                                     Value       ,A0       ,A1       ,A2       ,A3 or 0
             Default     => _AddressTCA9548A & A0 = 0 & A1 = 0 & A2 = 0 & A3 = 0                           
             Value       => Address IC MuliPlexer
             pinAddr     => A0,A1,A2,A3/0
        
    5.  int8_t setChannel(int8_t val);
                          Channel
             Default => 0
             Channel => 0 ~ 7
    
    // Wire or Wire1 or Wire3 ~~
    6.  int8_t InstalWire(TwoWire *val);
             Default => NULL
             Syntax:
             - InstalWire(&Wire);
             - InstalWire(&Wire1);
             - InstalWire(&Wire2);
    
    //Write
    7.  int8_t setWrite(int8_t val);
                        Data
                        
    8.  int8_t setWrite(int8_t val,int8_t val2);
                        Data      ,Data
                        
    9.  int8_t setWrite(int8_t val,int8_t *val2,int8_t val3);
                        Data      ,Data array  ,size Array
    
    //read>
    10. int8_t getRead(int val,int& val2);
                       Value  ,Data
                       
    11. int8_t getRead(int val,int& val2 ,int val3);
                       Value  ,Data Array,size Array
    
</h6>
    
<h4>All the command fuctions with RETURN</h4>
<ul>
    <li> <h5> Process_OK </h5> </li>
    <li> <h5> Process_Not_Found </h5> </li>
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
            Download <a href="https://github.com/adafruit/TinyWireM">TinyWireM Library</a>
</h5></pre>

#include "SendTrans.h"

SendTransI2C SimpleWire;

void setup() {
  Wire.begin();
  SimpleWire.InstalWire(&Wire);
  // Instal Wire

  SimpleWire.setMultiPlexer(Yes_UseSwitch,Use_TCA9548A);
  //                 Value        ,Name IC
  // Default => No_UseSwitch 
  // Value   => No_UseSwitch or Yes_UseSwitch
  
  SimpleWire.setAddressMultiPlexer(0x70   ,0 ,0 ,0 ,0);
  //                        Address,A0,A1,A2,0
  
  SimpleWire.setChannel(0);
  //             Value
  // Value => 0 ~ 7

}

void loop() {
  // put your main code here, to run repeatedly:
}

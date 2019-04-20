#include "SendTrans.h"
SendTransI2C SimpleWire;

int val = 8;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  SimpleWire.InstalWire(&Wire);
  SimpleWire.setWire(0x2C); // Address
}

void loop() {
  Wire.setClock(100000); // setClock I2C 100kHZ

  SimpleWire.setWrite(val); 
  
  delay(500);
}

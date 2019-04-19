#include "SendTrans.h"
SendTransI2C SimpleWire;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  SimpleWire.setWire(0x00); // Address
  Serial.begin(9600);
}

void loop() {
  Wire.setClock(100000); // setClock I2C 100kHZ

  int c = Serial.read()    
  SimpleWire.setWrite(SubbAddress, c); 
  
  delay(500);
}

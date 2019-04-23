#include "SendTrans.h"
SendTransI2C SimpleWire;

int SubbAddress ;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  SimpleWire.InstalWire(&Wire);
  SimpleWire.setWire(0x00); // Address
  Serial.begin(9600);
}

void loop() {
  Wire.setClock(100000); // setClock I2C 100kHZ

  int c; 
  SimpleWire.getRead(SubbAddress, &c); 
  Serial.println(c);
  
  delay(500);
}

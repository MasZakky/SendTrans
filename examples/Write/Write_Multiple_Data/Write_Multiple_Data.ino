#include "SendTrans.h"
SendTrans SimpleWire;

int SubbAddress = 8;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  SimpleWire.InstalWire(&Wire);
  SimpleWire.setWire(0x2C); // Address
  Serial.begin(9600);
}

void loop() {
  Wire.setClock(100000); // setClock I2C 100kHz

  char c = Serial.read()    
  SimpleWire.setWrite(SubbAddress, c,sizeof(c)); 
  
  delay(500);
}

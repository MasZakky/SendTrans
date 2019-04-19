#include "SendTrans.h"
SendTrans SimpleWire;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  SimpleWire.setWire(0x2C); // Address
}

byte val = 0;

void loop() {
  Wire.setClock(100000); // setClock I2C 100kHZ

  SimpleWire.setWrite(byte(0x00));      // sends instruction byte
  SimpleWire.setWrite(val);             // sends potentiometer value byte
  
  val++;        // increment value
  if (val == 64) { // if reached 64th position (max)
    val = 0;    // start over from lowest value
  }
  delay(500);
}

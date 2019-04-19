#include "SendTrans.h"
SendTransI2C SimpleWire;

int SubbAddress = 8;
int val = 6;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  SimpleWire.setWire(0x00); // Address
  Serial.begin(9600);
}

void loop() {
  Wire.setClock(100000); // setClock I2C 100kHZ

  char *c;
  c = malloc(c); //Replace memory to ram
    
  SimpleWire.setRead(SubbAddress,&c,val); 
  
  for(int a;a <= val, a++){
    Serial.print(c[a]);         // print 
  }

  free(c); //Free memory 
  
  delay(500);
}

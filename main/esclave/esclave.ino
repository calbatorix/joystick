#include <Wire.h>
#include "Potar.h"
#include "bouton.h"

int Values[3];
const byte* p = (const byte*)(const void*)&Values[0];

Potar collectif(0);
bouton reset(7);

void setup() {
  reset.init();
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  collectif.value();
  if(reset.value()==1){
    collectif.resetEeprom();
  }
  Wire.beginTransmission(8); // transmit to device #8

  Values[0] = collectif.getValueAnalog();

  Values[1] = collectif.getmin();

  Values[2] = collectif.getmax();

  for(int i=0;i<6;i++){
    Wire.write(*(p+i));
  }
  Wire.endTransmission();    // stop transmitting

}

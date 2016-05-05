#include <Wire.h>
#include <potar.h>

potar collectif(0);

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("valeur potar :");        // sends five bytes
  Wire.write(collectif.getValueAnalog());              // sends one byte
  Wire.endTransmission();    // stop transmitting

  delay(100);
}

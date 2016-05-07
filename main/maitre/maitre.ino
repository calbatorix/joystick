#include <Wire.h>

int Values[12];
byte* p = (byte*)(void*)&Values[0];

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  for(int i=0;i<12;i++){
    *(p+i) = Wire.read();
  }
  Serial.println(Values[0]);         // print the integer
  Serial.println(Values[1]);
  Serial.println(Values[3]);
  Serial.println(Values[4]);
  Serial.println(Values[5]);
  Serial.println(Values[6]);
  Serial.println(Values[7]);
  Serial.println(Values[8]);
  Serial.println(Values[9]);
  Serial.println(Values[10]);
  Serial.println(Values[11]);
  Serial.println("fin");
}

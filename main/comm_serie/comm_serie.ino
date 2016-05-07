#include <SoftwareSerial.h>  
#include "report.h"

SoftwareSerial mySerial(3,2); // RX, TX 
comm trame;

void setup() { 
 Serial.begin(9600); 
 mySerial.begin(9600);   
}

 void loop() {    
  if (mySerial.available()){
   mySerial.readBytes( (byte*)&trame, sizeof(comm));
  }
  Serial.println(trame.axis[0]);
  Serial.println(trame.axis[1]);
  Serial.println(trame.axis[2]);
  Serial.println(trame.axis[3]);
  Serial.println(trame.axis[4]);
  Serial.println(trame.axis[5]);
  Serial.println(trame.axis[6]);
  Serial.println(trame.axis[7]);
  Serial.println(trame.axis[8]);
  Serial.println(trame.axis[9]);
  Serial.println(trame.axis[10]);
  Serial.println(trame.axis[11]);
  Serial.println("fin");
  delay(200);
}

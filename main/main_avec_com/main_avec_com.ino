#include "Potar.h"
#include "bouton.h"
#include "report.h"
#include <SoftwareSerial.h>

const int rxpin = 2;
const int txpin = 3;
SoftwareSerial arduino_ecran(rxpin, txpin);
joyReport_t joyReport(NUM_AXES);
comm com ;
int tab[NUM_AXES];

Potar collectif(0);
Potar pallonier(1);
Potar cycliquex(2);
Potar cycliquey(3);
bouton reset(7);

void setup(void);
void loop(void);

void setup() {
  reset.init();
  joyReport.init();
  arduino_ecran.begin(9600);
}

void loop() { 

  if(reset.value()==1){
    collectif.resetEeprom();
    pallonier.resetEeprom();
    cycliquex.resetEeprom();
    cycliquey.resetEeprom();
  }
  com.axis[0] = collectif.getValueAnalog();
  com.axis[1] = collectif.getmin();
  com.axis[2] = collectif.getmax();
  com.axis[3] = pallonier.getValueAnalog();
  com.axis[4] = pallonier.getmin();
  com.axis[5] = pallonier.getmax();
  com.axis[6] = cycliquex.getValueAnalog();
  com.axis[7] = cycliquex.getmin();
  com.axis[8] = cycliquex.getmax();
  com.axis[9] = cycliquey.getValueAnalog();
  com.axis[10] = cycliquey.getmin();
  com.axis[11] = cycliquey.getmax();
  
  tab[0] = collectif.value();
  tab[1] = pallonier.value();
  tab[2] = cycliquex.value();
  tab[3] = cycliquey.value();
  joyReport.setJoyReport(tab);
   arduino_ecran.flush();
  arduino_ecran.write((uint8_t*)&com, sizeof(comm));
  joyReport.sendJoyReport();

  delay(100);
}

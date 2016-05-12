#include "Potar.h"
#include "bouton.h"
#include "report.h"

JoyReport joyReport(NUM_AXES);
int tabValue[NUM_AXES/*+(NUM_BUTTONS-1)*/];
Potar collectif(0);
Potar pallonier(1);
Potar cycliquex(2);
Potar cycliquey(3);
bouton reset(7);
/*bouton bouton0(4);
bouton bouton1(5);
bouton bouton2(6);
bouton bouton3(8);
bouton bouton4(9);
bouton bouton5(10);
bouton bouton6(11);
bouton bouton7(12);*/


void setup(void);
void loop(void);

void setup() {
    reset.init();
   /* bouton0.init();
    bouton1.init();
    bouton2.init();
    bouton3.init();
    bouton4.init();
    bouton5.init();
    bouton6.init();
    bouton7.init();*/
    joyReport.init();
}

void loop() { 
  if(reset.value()==1){
    collectif.resetEeprom();
    pallonier.resetEeprom();
    cycliquex.resetEeprom();
    cycliquey.resetEeprom();
  }
  tabValue[0] = collectif.value();
  tabValue[1] = pallonier.value();
  tabValue[2] = cycliquex.value();
  tabValue[3] = cycliquey.value();
  /*tabValue[4] = bouton.value();
  tabValue[5] = bouton.value();
  tabValue[6] = bouton.value();
  tabValue[7] = bouton.value();
  tabValue[8] = bouton.value();
  tabValue[9] = bouton.value();
  tabValue[10] = bouton.value();
  tabValue[11] = bouton.value();*/
  joyReport.setJoyReport(tabValue);
  joyReport.sendJoyReport();
  delay(100);
}

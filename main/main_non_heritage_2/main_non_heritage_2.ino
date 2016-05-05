#include "Potar.h"
#include "bouton.h"
#include "report.h"
#include "Rapport.h"

joyReport_t joyReport(NUM_AXES);
int tab[4];
Potar collectif(0);
//potar pallonier(1);
bouton reset(7);

void setup(void);
void loop(void);

void setup() {
    reset.init();
    joyReport.init();
}

void loop() { 
  if(reset.value()==1){
    collectif.resetEeprom();
    //pallonier.resetEeprom();
  }
  tab[0] = collectif.value();
  tab[1] = 1000;
  tab[2] = 2000;
  tab[3] = 4000;
  joyReport.setJoyReport(tab);
  joyReport.sendJoyReport(); //TODO
  delay(100);
}

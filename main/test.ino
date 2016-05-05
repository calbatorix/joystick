#include <potar.h>
#include <bouton.h>
#define NUM_AXES    4 

typedef struct joyReport_t {
    int16_t axis[NUM_AXES];
} joyReport_t;

joyReport_t joyReport;
int tab[4];
potar collectif(0);
//potar pallonier(1);
bouton reset(7);

void setup(void);
void loop(void);
void sendJoyReport(joyReport_t *report);

void setup() {
    reset.init();
    Serial.begin(115200);
    delay(200);
}

void sendJoyReport(struct joyReport_t *report){
    Serial.write((uint8_t *)report, sizeof(joyReport_t));
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
  for (uint8_t ind=0; ind<NUM_AXES; ind++){
    joyReport.axis[ind] =tab[ind];
  }
  sendJoyReport(&joyReport);
  delay(100);
}

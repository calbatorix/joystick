#include "report.h"

joyReport_t::joyReport_t(int num_axes){
	numAxes = num_axes;
}

void joyReport_t::init(){
	Serial.begin(115200);
	delay(200);
}

void joyReport_t::setJoyReport(int tabValue[]){
	for (uint8_t ind=0; ind<numAxes; ind++){
	    joyReport.axis[ind] = tabValue[ind];
        }	
}

void joyReport_t::sendJoyReport(){
	struct joyReport_tt *report = &joyReport;
	Serial.write((uint8_t*)report, sizeof(joyReport_tt));// doit obtenir un truc comme ca "Serial.write(const (uint8_t *)buffer, size_t size);"
    	/*for (uint8_t ind=0; ind<numAxes; ind++) {
		Serial.print("axis[");
		Serial.print(ind);
		Serial.print("]= ");
		Serial.print(axis[ind]);
		Serial.println(" ");
	}
	Serial.println();*/
}

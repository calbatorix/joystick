#ifndef REPPORT_H_
#define REPPORT_H_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Rapport.h"

class joyReport_t{
	public:
		joyReport_t(int num_axes);
		void init();
		void setJoyReport(int tabValue[]);
		void sendJoyReport(); //TODO
		joyReport_tt joyReport;
	private:
		int numAxes;
};

#endif

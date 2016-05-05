#ifndef REPPORT_H_
#define REPPORT_H_

#include <Arduino.h>

class joyReport_t{
	public:
		joyReport_t(int num_axes);
		void init();
		void setJoyReport(int tabValue[]);
		void sendJoyReport(); //TODO
	private:
		int numAxes;
		int16_t axis[];
};

#endif

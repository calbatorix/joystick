#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <Arduino.h>

class Capteur{
	public:
	   Capteur(int pin);
	protected:
	   int Pin;
};

#endif

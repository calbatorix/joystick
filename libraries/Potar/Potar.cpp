/**
 * \file	potar.cpp
 * \author	calbatorix
 * \version 1.0
 * \date    26 mars 2016
 * \brief   Fichier de definition pour la class potar.
 *
 * \details Ce fichier a pour but de definir les methodes et les constucteurs/destructeurs de la class potar.
 *
 */
#include "Potar.h"

Potar::Potar(int Pin){
	in = Pin;
	flags = 0;
	millisflag = 0;
	Potar::init();
	/*Serial.begin(9600);
	Serial.println("Creation potar .....");
	Serial.print("max: ");
	Serial.println(max);
	Serial.print("min: ");
	Serial.print("min");*/

}

void Potar::init(){
	byte hiByteMin = EEPROM.read(4*in);
	byte loByteMin = EEPROM.read((4*in)+1);
	byte hiByteMax = EEPROM.read((4*in)+2);
	byte loByteMax = EEPROM.read((4*in)+3);
	min = word(hiByteMin, loByteMin);
	max = word(hiByteMax, loByteMax);
}

void Potar::writeEeprom(){
	if(flags == 1){
		if((millis()-millisflag)>600000){

			byte hiByteMin = highByte(min);
			byte loByteMin = lowByte(min);
			byte hiByteMax = highByte(max);
			byte loByteMax = lowByte(max);
			EEPROM.write((4*in),hiByteMin);
			EEPROM.write((4*in)+1,loByteMin);
			EEPROM.write((4*in)+2,hiByteMax);
			EEPROM.write((4*in)+3,loByteMax);
			flags = 0;
		}
	}
}

void Potar::resetEeprom(){
	min = analogRead(in);
	max = min+1;
	flags = 1;
	millisflag = millis();
}

void Potar::update(){
	Valueanalog = analogRead(in);

    if ( Valueanalog < min)
    	min = Valueanalog ;
    if ( Valueanalog> max)
        max = Valueanalog ;
	Value = map(Valueanalog,min,max,-32768,32767);
}

int Potar::value() {
	Potar::writeEeprom();
	Potar::update();
	return Value;
}

int Potar::getValueAnalog(){
	return Valueanalog;
}
int Potar::getmin(){
	return min;
}

int Potar::getmax(){
	return max;
}
/*
int Potar::getflag(){
	return flags;
}

int Potar::getmillisflag(){
	return millisflag;
}*/

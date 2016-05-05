/**
 * \file	bouton.cpp
 * \author	calbatorix
 * \version 1.0
 * \date    26 mars 2016 
 * \brief   Fichier de definition pour la class bouton.
 *
 * \details Ce fichier a pour but de definir les methodes et les constucteurs/destructeurs de la class bouton.
 *
 */
#include "bouton.h"

bouton::bouton(int Pin){
	in = Pin;
}

void bouton::init(){
	pinMode(in, INPUT);
}

void bouton::update(){
	Value = digitalRead(in);
}

int bouton::value(){
	bouton::update();
	return Value ;
}

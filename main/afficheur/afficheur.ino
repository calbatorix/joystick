#include <SoftwareSerial.h>  
#include "report.h"
#include <SPI.h>
#include <Ucglib.h>

SoftwareSerial mySerial(11,10); // RX, TX 
comm trame;

int buttonPins[2] = {8,9};
boolean buttonEtat[2] = {false, false};
int pressBouton = 0;
int flag = 0;
int oldX = 0;
int oldY = 0;
int flagD = 1;
Ucglib_ILI9341_18x240x320_SWSPI ucg(/*sclk=*/ 7, /*data=*/ 6, /*cd=*/ 5 , /*cs=*/ 3, /*reset=*/ 4);
const int boutonSuiv = 8 ;
const int boutonPrec = 9 ;

  
void setup(void){
   mySerial.begin(9600);
   Serial.begin(9600);
   delay(1000);
   ucg.begin(UCG_FONT_MODE_TRANSPARENT);
   ucg.clearScreen();

   pinMode(boutonSuiv,INPUT_PULLUP);
   pinMode(boutonPrec,INPUT_PULLUP);
   }

void loop(void){
    if (mySerial.available()){
   mySerial.readBytes( (byte*)&trame, sizeof(comm));
  }
  Serial.println(trame.axis[0]);
  Serial.println(trame.axis[1]);
  Serial.println(trame.axis[2]);
  Serial.println(trame.axis[3]);
  Serial.println(trame.axis[4]);
  Serial.println(trame.axis[5]);
  Serial.println(trame.axis[6]);
  Serial.println(trame.axis[7]);
  Serial.println(trame.axis[8]);
  Serial.println(trame.axis[9]);
  Serial.println(trame.axis[10]);
  Serial.println(trame.axis[11]);
  Serial.println("fin");
   etatBouton();
   deplacement();
   afficheD();
  
}

void affichePallonier(void){
  ucg.clearScreen();
  ucg.setColor(255,255,255);
  ucg.drawFrame(40,60,121,122);
  ucg.drawFrame(40,180,121,122);
  }

void afficheCyclique(void){
  ucg.clearScreen();
  ucg.setColor(255,255,255);
  ucg.drawFrame(10,50,220,220);   //largeur de l'écran = 240x320 pixels 
  }
  
void afficheCollectif(void){
  ucg.clearScreen();
  ucg.setColor(255,255,255);
  ucg.drawFrame(40,60,120,240);
  }



  
void positionCyclique(void){
   int potardX = analogRead(0);
   int potardY = analogRead(1);

   int newX = map(potardX,0,1024,0,200);
   int newY = map(potardY,0,1024,0,200);

   if(oldY != newY || oldX != newX){
      if(newY > oldY + 1 || newX > oldX + 1){
         ucg.setColor(255,255,255);
         ucg.drawDisc(newX+20,newY+60,5,15);
         // ucg.drawLine(newX+10,100,newX+30,100);
         ucg.setColor(0,0,0);
         ucg.drawDisc(oldX+20,oldY+60,5,15);
         // ucg.drawLine(oldX+10,100,oldX+30,100);
         oldX=newX;
         oldY=newY;
         //Serial.println(potardX);
         }
      else if(newY < oldY - 1 || newX < oldY - 1){
         ucg.setColor(255,255,255);
         ucg.drawDisc(newX+20,newY+60,5,15);
         //ucg.drawLine(newX+10,100,newX+30,100);
         ucg.setColor(0,0,0);
         ucg.drawDisc(oldX+20,oldY+60,5,15);
         //ucg.drawLine(oldX+10,100,oldX+30,100);
         oldX=newX;
         oldY=newY;
         //Serial.println(potardX);
         }
      }
   }



void jaugeCollectif(){
  
   int potard = analogRead(0);
   int newX = map(potard,0,1024,0,240);

 
   if(oldX != newX ){
      if(newX > oldX +1){
         ucg.setColor(255,255,255);
         ucg.drawBox(40,oldX + 61,119,newX-oldX);
         // ucg.setColor(0,0,0);
         // ucg.drawBox(41,oldX+61,119,newX-oldX);
         oldX = newX;
         //Serial.println("newx > oldx");
         }
         
      else if(newX < oldX - 1){
         ucg.setColor(0,0,0);
         //ucg.drawBox(41,newX+61,119,-newX);
         ucg.drawBox(40, newX+61,119, oldX-newX);
         oldX = newX;
         //Serial.println("newx < oldx");
         }
      }
   }


void jaugePallonier(){
  
   int potard = analogRead(0) ;
   int newX = map(potard,-512,512,0,240);

   potard -= 512;
 
   if(potard<0){
      if(oldX != newX ) {
         if(newX > oldX +1 ){
            ucg.setColor(0,0,0);
            ucg.drawBox(41,oldX + 61,119,newX-oldX);
            oldX = newX;
            //Serial.println("newx > oldx");   
            } 
            
         else if(newX < oldX - 1){
            ucg.setColor(255,255,255);
            ucg.drawBox(41, newX+61,119, oldX-newX);
            oldX = newX;
            //Serial.println("newx < oldx");
            }
         }
      }
   else{
      if(oldX != newX ){
         if(newX > oldX +1){
            ucg.setColor(255,255,255);
            ucg.drawBox(41,oldX + 62,119,newX-oldX);
            oldX = newX;
           // Serial.println("newx > oldx");   
            } 
         else if(newX < oldX - 1){
            ucg.setColor(0,0,0);
            ucg.drawBox(41, newX+62,119, oldX-newX);
            oldX = newX;
           // Serial.println("newx < oldx");
            }
         }  
      }
   }


void etatBouton(){
  if (!digitalRead(boutonSuiv)==1 ){
    pressBouton = 1 ;
  }

  if (!digitalRead(boutonPrec)==1){
    pressBouton = 2 ;
  }
}


void deplacement(){
  if((pressBouton==1) && (flagD < 3)){
    flagD++;
    pressBouton = 0;
    affiche1();}
  if((pressBouton==2) && (flagD > 1)){
    flagD--;
    pressBouton= 0;
    affiche1();}
}


void affiche1(){
  if (flagD == 1)
    afficheCyclique();
  if (flagD == 2)
    afficheCollectif();
  if (flagD == 3)
    affichePallonier();
}

void afficheD(){
    if (flagD == 1)
    positionCyclique();
  if (flagD == 2)
    jaugeCollectif();
  if (flagD == 3)
    jaugePallonier();
}

#include "GestionI2C.h"
#include "thermistance.h"
#include "dht22.h"
#include "CartoucheChauffante.h"

const int BOUTON_UP_PIN = 2;
const int BOUTON_DOWN_PIN = 3;
const int BOUTON_OK_PIN = 4;

bool boutonUp = false;
bool boutonDown = false;
bool boutonOk = false;
bool CanHeat = false;
int menuState = 1;
int boutons;

bool setvalue = false;


unsigned long dateDernierChangement = 0;
unsigned long dateDernierChangement1 = 0;

int currentTempGoal = 40;
int currentHumiGoal = 50;
int currentMaxAirTemp = 30;



void setup()
{ 
  analogReference(EXTERNAL);
  initDisplay();
  initHeatPin();
  pinMode(BOUTON_UP_PIN,INPUT);
  pinMode(BOUTON_DOWN_PIN,INPUT);
  pinMode(BOUTON_OK_PIN,INPUT);

}


void loop()
{
unsigned long dateCourante = millis();
unsigned long intervalle = dateCourante - dateDernierChangement;
unsigned long intervalle1 = dateCourante - dateDernierChangement1;


//////////////////////////////////////////////// Gestion clavier
boutons = clavier();
switch (boutons) {
  case 0 :
    break;
  case 1 :              /////////////////////////////// BOUTON ENTREE
          if (setvalue = false && menuState != 0) {
              setvalue = true;

          }
          else if (setvalue = true) {
            setvalue = false;
          }
          else {

          }
          displayChit(1);
    break;

  case 2 :             ////////////////////////////////// BOUTON HAUT
          if (setvalue = false) {
            changeMenuState(true);

          }
          else if (setvalue = true){  switch (menuState) {
                    case 1 :
                       currentTempGoal++;
                    break;
                    case 2 :
                       currentHumiGoal++;
                       break;
                    case 3 :
                      currentMaxAirTemp++;
                    break;


                  }


          }
          displayChit(2);
    break;
  case 3 :         /////////////////////////////BOUTON BAS
          if (setvalue = false) {
            changeMenuState(false);

          }
          else if (setvalue = true) {  switch (menuState) {
                    case 1 :
                       currentTempGoal--;
                    break;
                    case 2 :
                       currentHumiGoal--;
                       break;
                    case 3 :
                      currentMaxAirTemp--;
                    break;


                  }


          }
          displayChit(3);
    break;
}


//////////////////////////////////////////////////



switch (menuState) {
  case -1 :
  menuState = 3;
  break;
  case 4 :
  menuState = 0;
  break;

}


////////////////////////////////////////////////////////////// Mesures capteurs (Toutes les 2 secondes)
if (intervalle > 2000) {
float HeatTemp = mesureTempHeat ();
displayTempHeat(HeatTemp);
int BoxHumi = mesureHumi();
displayHumi(BoxHumi);
int BoxTemp = mesureTemp();
displayTemp(BoxTemp);
dateDernierChangement = dateCourante;
///////////////////////////////////////////////////////////// Fin 
}


////////////////////////////////////////////////////////////// Gestion de la chauffe (demi secondes d'intervalle)
if (intervalle1 > 500 && CanHeat == true) {
  Heat();
  dateDernierChangement1 = dateCourante;
}
////////////////////////////////////////////////////////////////Fin

//////////////////////////////////////////////////////////////////////////















///////////////////////////////////////////////////////////////////////////

security (currentTempGoal , currentHumiGoal , currentMaxAirTemp);
switch (menuState) {
  case 0 :
  displayMenu("merde", -1);
  break;
  case 1 :
  displayMenu("TempGoal", currentTempGoal);
  break;
  case 2:
  displayMenu("HumiGoal", currentHumiGoal);
  break;
  case 3:
  displayMenu("MaxAirTemp", currentMaxAirTemp);
  break;
}
}

void security(int MaxTemp, int MaxHumi , int MaxAirTemp) {
  float temp = mesureTempHeat();
  int  humi = mesureHumi();
  int airTemp = mesureTemp();
  if (temp > MaxTemp-1) {
      stopHeat();
      CanHeat = false;
  }
  else if (humi > MaxHumi && MaxHumi != 0) {
      stopHeat();
      CanHeat = false;
  }
  else if (airTemp > MaxAirTemp && MaxAirTemp != 0) {
      stopHeat();
      CanHeat = false;
  }
  else if (temp < MaxTemp-1) {
    CanHeat = true;
    
    }

  }

void changeMenuState (bool MenuUpOrDown) {
  if (MenuUpOrDown = true) {
      menuState = menuState+1;
  }
  else
  {
    menuState = menuState-1;
  }
  
}

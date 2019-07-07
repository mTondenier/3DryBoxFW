#include <Arduino.h>
#define heatPin 7

void initHeatPin () {
  pinMode(heatPin, OUTPUT);
  
  }

void Heat () {
  digitalWrite(heatPin, HIGH);
  }
void stopHeat () {
  digitalWrite(heatPin, LOW);
  
  }

  void blockHeat() {
    pinMode(heatPin,INPUT);
    }


#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);



float mesureHumi () {
  dht.begin();
  float h = dht.readHumidity();
  return h; }

float mesureTemp () {
  float t = dht.readTemperature();
  return t; }


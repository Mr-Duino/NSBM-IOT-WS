
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
//  note: use pins 3, 4, 5, 12, 13 or 14 --

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {

  delay(2000);


  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }


  float hif = dht.computeHeatIndex(f, h);

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}

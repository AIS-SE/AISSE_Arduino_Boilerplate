// Interfacing DHT11 and DHT22 Sensors with Arduino by ArduinoYard
#include "DHT.h"

// Define DHT type and pin
#define DHTPIN 2       // Data pin connected to digital pin 2
#define DHTTYPE DHT11  // DHT11 or DHT22 (change according to the sensor you are using)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT Arduino Tutorial: Reading Temperature and Humidity");
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity();      // Read humidity percentage

  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Wait 2 seconds before reading again
}

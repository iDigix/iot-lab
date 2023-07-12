#include <Arduino.h>
// Import required libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define DHTTYPE    DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  dht.begin();
}

void loop(){  
// print the temerature value in the serial monitor
   Serial.println("Temperature in C:");  
   Serial.println((dht.readTemperature( )));  
// print the humidity value in the serial monitor
   Serial.println("Humidity in %:");  
   Serial.println((dht.readHumidity()));  
   delay(5000); 
}
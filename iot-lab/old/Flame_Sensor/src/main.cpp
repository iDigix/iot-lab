#include <Arduino.h>

#define flPin 5  // Pin connected to the flame sensor D1

void setup() {
  Serial.begin(115200);  // Initialize the serial monitor
  pinMode(flPin, INPUT);  // Set the flame pin as an input
}

void loop() {
  int mvValue = digitalRead(flPin);  // Read the digital value from the flame sensor

  if (mvValue == 1) {
    Serial.println("flame detected!");
  } else {
    Serial.println("no    flame detected!");
  }
  
  delay(100);  // Delay for 1 second before taking the next reading
}

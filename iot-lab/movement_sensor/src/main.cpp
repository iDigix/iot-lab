#include <Arduino.h>

#define mvPin 5  // Pin connected to the mvmnt sensor

void setup() {
  Serial.begin(115200);  // Initialize the serial monitor
  pinMode(mvPin, INPUT);  // Set the mvmnt pin as an input
}

void loop() {
  int mvValue = digitalRead(mvPin);  // Read the digital value from the mvmnt sensor

  if (mvValue == 1) {
    Serial.println("mvmnt detected!");
  } else {
    Serial.println("no    mvmnt detected!");
  }
  
  delay(100);  // Delay for 1 second before taking the next reading
}

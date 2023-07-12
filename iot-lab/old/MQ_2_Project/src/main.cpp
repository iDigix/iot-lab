#include <Arduino.h>

int smokeA0 = A0;



void setup() {
 pinMode(smokeA0, INPUT);
 Serial.begin(115200);
}

void loop() {
 int sensor = analogRead(smokeA0);

 Serial.print("Gas Level : ");
 //1.0 is the max voltage value
 //1023.0, represents the maximum value the analog pin can output (10-bit resolution, so 2^10 - 1 = 1023)
 Serial.println(sensor * (1.0 / 1023.0));

 delay(100);
}
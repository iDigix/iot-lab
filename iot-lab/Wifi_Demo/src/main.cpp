#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "Costart";      // "REPLACE_WITH_YOUR_SSID"
const char *password = "COSTART2021"; // "REPLACE_WITH_YOUR_PASSWORD"

void connect2Network()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(1000);
  }

  // Serial.println("\n");
  Serial.println("\n================================================================================");
  Serial.println("> Connected to WiFi network \"" + WiFi.SSID() + "\"");
  Serial.println("> IP Address: " + WiFi.localIP().toString());
  Serial.println("> MAC Address: " + WiFi.macAddress());
  Serial.println("================================================================================");
}

void setup()
{
  Serial.begin(115200);
  
  // Connect to Network
  connect2Network();
}

void loop() {}
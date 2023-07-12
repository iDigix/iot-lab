
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
//start STA
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>
//end STA


const char *logCsv = "/files/LogData.csv";


//STA
const char* ssidst = "kammal";
const char* passwordst = "123456789";
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
ESP8266WebServer server(80);
//STA


// const char *ssid     = "ANIMATION"; 
const char *ssid     = "TOPNET_9040";
// const char *password = "VILLAGEE#2020"; 
const char *password = "3v3bswa77f";
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};





void setup() {
  Serial.begin(115200);
    Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
// Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  timeClient.setTimeOffset(3600);



//Sta
LittleFS.begin();
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAPConfig(local_ip, gateway, subnet);
  /* You can remove the password parameter if you want the AP to be open */
  WiFi.softAP(ssidst, passwordst);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  // if (!mdns.begin("gaskya", myIP)) {
  //   Serial.println("Error setting up MDNS responder!");
  // }
   server.serveStatic("/", LittleFS, "/");
  // server.on("/", handleRoot);
  
//STA


//start write on csv

  LittleFS.begin();
            File logCsv_File = LittleFS.open(logCsv, "a");
            if (!logCsv_File)
            {
              Serial.println("could not open the keylist file for writing");
              LittleFS.end();
              return;
            }
            String data ="";
            data += "line";
            data += ",";
            data += "from";
            data += "\n";
            data += ",";
            data += ",";
            data += "esp";
            data += "\n";
            Serial.println(data);

            auto bytesWritten = logCsv_File.print(data);
            Serial.printf("bytes written: %d\n", bytesWritten);
            Serial.println(bytesWritten);
            if (bytesWritten != 0)
            {
              Serial.println("Card Added Succefully");
            }
            else
            {
              Serial.println("Card was not added");
            }
            logCsv_File.close();
            LittleFS.end();

//end write on csv


server.begin();
  // MDNS.addService("http", "tcp", 80);
  Serial.println("HTTP server started");


}







void loop() {
  

//Start STA
  LittleFS.begin();
  server.handleClient();
  LittleFS.end();
//END STA


  //start AP
  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();
  String formattedTime = timeClient.getFormattedTime();
  // Serial.print("Time And Date: ");
  String weekDay = weekDays[timeClient.getDay()];
  // Serial.print(weekDay);    
  //Get a time structure
  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  String currentMonthName = months[currentMonth-1];
  int currentYear = ptm->tm_year+1900;
  //Print complete date:
  // String currentDate = String(monthDay) + "/" + String(currentMonth) + "/" + String(currentYear);
  // Serial.print(" , ");
  // Serial.print(currentDate);
  // Serial.print(" : ");
  // Serial.print(formattedTime);  
  // Serial.println("");
//END AP



}
#define _DISABLE_TLS_
#define _DEBUG_
#define THINGER_SERVER "159.65.149.211" //Enter your thinger server ip address

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#define USERNAME "admin" //Enter username
#define DEVICE_ID "switchbox"  //Enter device ID
#define DEVICE_CREDENTIAL "OSL@123*"  //Enter device credentials

bool switch1,thinger1, relay1;

ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(D1, OUTPUT); 
  pinMode(D7, INPUT);
  Serial.begin(115200);
  
  WiFiManager wifiManager;
  wifiManager.autoConnect("SwitchUP");
  Serial.println("Connected.");
  //Thinger logic
  thing["led"] << [](pson & in) {
    if (in.is_empty()) {
      in = relay1;
    }
    else {
      thinger1 = (in ? HIGH : LOW);
    }
  };
}

void loop() {
  thing.handle();//update thinger side
  switch1 = (bool) digitalRead(D7);           //update physical switch sid 
  relay1 = switch1 ^ thinger1;                //compute relay output
  digitalWrite(D1, relay1);                   //write output to relay
 }

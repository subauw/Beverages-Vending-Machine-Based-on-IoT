#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
#include <ESP8266HTTPClient.h> 

SoftwareSerial NodeMCU(D2, D1); 
 
WiFiClient wifiClient;

const char* ssid = "Zacky's IPhone";
const char* password = "1ndones1a";
int stok;

void setup() {
  Serial.begin(2400);
  NodeMCU.begin(4800);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
    int i=0;
    while(WiFi.status() != WL_CONNECTED){ 
      Serial.print(".");
      delay(1000);     
    } 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  delay(2000); 
}

void loop() {
  int status = 1;

  while (NodeMCU.available()) {
    stok = NodeMCU.parseInt();
    if (NodeMCU.read() == '\n') {
    Serial.println(stok);
    }
  }
  delay(30);
  
  if ((WiFi.status() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    
    String address;
    address ="http://192.168.43.115/webapi/api/create.php?stok=";
    address += String(stok);
      
    http.begin(client,address);
    int httpCode = http.GET();
    String payload;  
    if (httpCode > 0) { 
        payload = http.getString();
        payload.trim();
        if( payload.length() > 0 ){
           Serial.println(payload + "\n");
        }
    }
    http.end();
  }else{
    Serial.print("Not connected to wifi ");Serial.println(ssid);
  }
  delay(10000); //interval 60s

  //baca data
  HTTPClient http;
  http.begin(wifiClient,"http://192.168.43.115/webapi/api/read.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.GET();
  String payload = http.getString();

  Serial.println(payload);
  http.end();
}
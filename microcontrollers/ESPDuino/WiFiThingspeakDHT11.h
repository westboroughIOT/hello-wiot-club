
#import "DHT.h"
 #include <ESP8266WiFi.h>

// replace with your channel’s thingspeak API key,
 String apiKey = "7FPAGP7Y79SEV59H";
 //replace with you WIFI user id and password
 const char* ssid = "Yourssid";
 const char* password = "Your password";

const char* server = "api.thingspeak.com";
 #define DHT11Pin 2

DHT dht(DHT11Pin, DHT11);
 WiFiClient client;

void setup() {
 Serial.begin(115200);
 //ensure WIFI is disconnected before making a connection
 WiFi.disconnect(true);
 delay(10);
 //dht.begin();

WiFi.begin(ssid, password);

Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");

}

void loop() {


 //float t = dht.readTemperature(true);
 

//if WIFI is connected and thingspeak can be reached and data posting can start

if (client.connect(server,80)) { // "184.106.153.149" or api.thingspeak.com
 String postStr = apiKey;
 postStr +="&field1=";
 postStr += String(t);
  postStr += "\r\n\r\n";

client.print("POST /update HTTP/1.1\n");
 client.print("Host: api.thingspeak.com\n");
 client.print("Connection: close\n");
 client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
 client.print("Content-Type: application/x-www-form-urlencoded\n");
 client.print("Content-Length: ");
 client.print(postStr.length());
 client.print("\n\n");
 client.print(postStr);

Serial.print("Temperature: ");
 Serial.print(t);
// Serial.print(" degrees Celcius Humidity: ");
 //Serial.print(h);
 //Serial.println("% send to Thingspeak");
 }
 client.stop();

Serial.println("Waiting…");
 // thingspeak needs minimum 15 sec delay between updates
 delay(20000);
 }

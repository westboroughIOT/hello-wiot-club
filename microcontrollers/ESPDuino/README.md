# ESPDuino

## What you need

### Hardware
* ESPDuino

### Software
* Arduino IDE
* OSX, Windows, Linux

## Examples
### WifiScanNow
Example WiFiScanNow.h shows how easy it is to use Arduino library and perform WiFi actions. This examples once uploaded to ESPDUINO lists all the wireless access points in the range within the serial monitor.

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/Wifiscan_example.PNG)

### Collecting temperature and updating to Thingspeak
Thingspeak www.thingspeak.com  is an IOT website where sensor data from ESPDUINO can be posted. Things speak lets to configure different data channels and seven fields for each channel. 

In this example I am updating field1 in challen named "Temperature". For each channel Thingspeak generates an API key that needs to be used along with the field name(field1) while updating  data.   

####Hardware needed
Espduino
DHT11 Temperature sensor
Connecting Wires

####Software needed
Arduino IDE with ESP8266 board 
ESP8266 library

#### Others
User id in thingspeak.com
Temperature Channel





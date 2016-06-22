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

### Collecting temperature and updating to Thingspeak WiFiThingspeakDHT11.h
Thingspeak www.thingspeak.com  is an IOT website where sensor data from ESPDUINO can be posted. Things speak lets to configure different "Channels" of information and multiple (Eight) parameter fields  for each channel. 

In this example I am updating "field1" in Channel named "Temperature". For each channel Thingspeak generates an API key that needs to be used along with the field name(field1) while updating  data.   

Login into thingspeak.com create your account and create your own Channel and field for testing this code.

####Hardware needed
1. Espduino
2. DHT11 Temperature sensor
3. Connecting Wires

####Software needed
1. Arduino IDE with ESP8266 board 
2. ESP8266 library

#### Others
1. User id in thingspeak.com
2. Temperature Channel

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/thingspeak.PNG)



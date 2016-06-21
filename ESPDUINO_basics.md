ESPDUINO is a recent WIFI enabled Arduino board that is very easy to use for IOT project. ESPDUI combines Arduino and ESP8266 wireless capability. So connecting to Wifi and posting data to cloud can be done with easy steps. 
![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/IMG_1137.JPG)

Espduino can be purchased online as low as $8,this makes any IOT project cost effective.
Once you got your ESPDUINO there are few more steps to complete

#### IDE update

##### Adding ESP8266 board to your existing Arduino IDE

If you are already using Arduino IDE 1.6.8 or 1.6.9 then you need to add ESP8266 board to the IDE. 
You can do that by following.

Go  File Menu--> and click on preferences

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/Path.PNG)

Add the following URL to the  "Additional Boards Manager URL"
 
 http://espduino.doit.am/package_esp8266com_index.json

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/Preference.PNG)

Now go to Tools--> Board --> Boards Manager

Select "updatable" in the type dropdown and you can see the board to be installed. Select the board and install

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/board.PNG)

Now you can see all the boards that are available as part of the installed package

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/esp8266boards.PNG)

##### Download the complete Arduino IDE prepackaged with ESP8266 module






